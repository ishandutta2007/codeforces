#ifdef __GNUC__
#pragma GCC target("sse4,avx")
#endif
#include <immintrin.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <array>
/*
struct LazyBinTreeUniversal {
    using T = int;
    using TMod = int;
    size_t size;
    std::vector<T> t;
    std::vector<TMod> mod;
    size_t h;

    LazyBinTreeUniversal(size_t N) :
        size(N),
        t(2 * N),
        mod(N, modInit()),
        h(32 - __builtin_clz(N)) { }

    LazyBinTreeUniversal(const std::vector<T>& other) :
        size(other.size()),
        t(2 * other.size()),
        mod(other.size(), modInit()),
        h(32 - __builtin_clz(other.size())) {
        std::copy(other.begin(), other.end(), t.begin() + size);
    }

    void apply(size_t p, const TMod& up_mod) {
        if (p < size) {
            if (mod[p] == -1) {
                mod[p] = up_mod;
            } else {
                mod[p] = combineMod(mod[p], up_mod);
            }
        } else {
            t[p] = combineValue(t[p], up_mod);
        }
    }

    void push(size_t p) {
        for (size_t s = h; s > 0; s--) {
            size_t pos = p >> s;
            if (mod[pos] != modInit()) {
                apply(2 * pos, mod[pos]);
                apply(2 * pos + 1, mod[pos]);
                mod[pos] = modInit();
            }
        }
    }

    void modify(size_t l, size_t r, const TMod& value) {
        if (l == r) return;
        l += size;
        r += size;
        push(l);
        push(r - 1);
        while (l < r) {
            if (l & 1) {
                apply(l, value);
                l++;
            }
            if (r & 1) {
                r--;
                apply(r, value);
            }
            l /= 2;
            r /= 2;
        }
    }

    T query(size_t p) {
        p += size;
        push(p);
        return t[p];
    }

  private:

    TMod combineMod(const TMod& mod, const TMod& up_mod) {
        return up_mod < 0 ? mod : up_mod;
    }

    T combineValue(T value, const TMod& up_mod) {
        return up_mod < 0 ? value : up_mod;
    }

    T init() {
        return 0;
    }

    TMod modInit() {
        return -1;
    }
};*/

struct LazyBinTreeUniversal {
    size_t size;
    using T = std::pair<int, int>;
    using TMod = int;
    std::vector<T> t;
    std::vector<TMod> mod;
    size_t h;

    LazyBinTreeUniversal(size_t N) :
        size(N),
        t(2 * N),
        mod(N, modInit()),
        h(32 - __builtin_clz(N)) { }

    LazyBinTreeUniversal(const std::vector<T>& other) :
        size(other.size()),
        t(2 * other.size()),
        mod(other.size(), modInit()),
        h(32 - __builtin_clz(other.size())) {
        std::copy(other.begin(), other.end(), t.begin() + size);
        for (size_t i = size; i-- > 1;) {
            t[i] = combine(t[2 * i], t[2 * i + 1]);
        }
    }

    void apply(size_t p, size_t level, TMod up_mod) {
        if (p < size) {
            mod[p] = combineMod(mod[p], up_mod);
            t[p] = combineWithMod(t[2 * p], t[2 * p + 1], level, mod[p]);
        } else {
            t[p] = combineValue(t[p], up_mod);
        }
    }

    void build(size_t p) {
        size_t level = 0;
        while (p > 1) {
            level++;
            p /= 2;
            t[p] = combineWithMod(t[2 * p], t[2 * p + 1], level, mod[p]);
        }
    }

    void push(size_t p) {
        for (size_t s = h; s > 0; s--) {
            size_t pos = p >> s;
            if (mod[pos] != modInit()) {
                apply(2 * pos, s - 1, mod[pos]);
                apply(2 * pos + 1, s - 1, mod[pos]);
                mod[pos] = modInit();
            }
        }
    }

    void modify(size_t p, TMod value) {
        p += size;
        t[p] = combineValue(t[p], value);
        build(p);
    }

    T query(size_t l, size_t r) {
        if (l == r) return init();
        l += size;
        r += size;
        push(l);
        push(r - 1);
        T left = init();
        T right = init();
        while (l < r) {
            if (l & 1) {
                left = combine(left, t[l]);
                l++;
            }
            if (r & 1) {
                r--;
                right = combine(t[r], right);
            }
            l /= 2;
            r /= 2;
        }
        return combine(left, right);
    }

    void modify(size_t l, size_t r, TMod value) {
        if (l == r) return;
        l += size;
        r += size;
        int l0 = l;
        int r0 = r - 1;
        size_t level = 0;
        push(l0);
        push(r0);
        while (l < r) {
            if (l & 1) {
                apply(l, level, value);
                l++;
            }
            if (r & 1) {
                r--;
                apply(r, level, value);
            }
            l /= 2;
            r /= 2;
            level++;
        }
        build(l0);
        build(r0);
    }

    T query(size_t p) {
        p += size;
        push(p);
        return t[p];
    }

  private:
    T combineWithMod(T left, T right, size_t level, TMod mod) {
        if (mod >= 0) {
            T tmp = combine(left, right);
            return std::make_pair(tmp.second * mod, tmp.second);
        }
        return combine(left, right);
    }

    T combine(T left, T right) {
        return std::make_pair(left.first + right.first, left.second + right.second);
    }

    TMod combineMod(TMod mod, TMod up_mod) {
        return up_mod < 0 ? mod : up_mod;
    }

    T combineValue(T value, TMod up_mod) {
        return up_mod < 0 ? value : std::make_pair(up_mod * value.second, value.second);
    }

    T init() {
        return std::make_pair(0, 0);
    }

    TMod modInit() {
        return -1;
    }
};

struct Solution {
    int n, q;
    std::vector<std::array<int, 3>> queries;
    void run(std::istream& in, std::ostream& out) {
        in >> n >> q;
        queries.resize(q);
        for (int i = 0; i < q; i++) {
            in >> queries[i][0] >> queries[i][1] >> queries[i][2];
            queries[i][0]--;
            queries[i][2]--;
        }
        std::vector<int> bounds;
        bounds.reserve(2 * q + 2);
        for (int i = 0; i < q; i++) {
            bounds.push_back(queries[i][0]);
            bounds.push_back(queries[i][1]);
        }
        bounds.push_back(n);
        bounds.push_back(0);
        std::sort(bounds.begin(), bounds.end());
        bounds.erase(std::unique(bounds.begin(), bounds.end()), bounds.end());
        std::vector<std::pair<int, int>> init;
        for (size_t i = 0; i + 1 < bounds.size(); i++) {
            init.emplace_back(bounds[i + 1] - bounds[i], bounds[i + 1] - bounds[i]);
        }
        LazyBinTreeUniversal tree(init);
        for (int i = 0; i < q; i++) {
            int l = std::lower_bound(bounds.begin(), bounds.end(), queries[i][0]) - bounds.begin();
            int r = std::lower_bound(bounds.begin(), bounds.end(), queries[i][1]) - bounds.begin();
            tree.modify(l, r, queries[i][2]);
            out << tree.query(0, init.size()).first << "\n";
        }
    }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}