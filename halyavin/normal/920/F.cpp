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

const int Iters = 8;

struct LazyBinTreeUniversal {
    using T = std::array<int64_t, Iters>;
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
        for (size_t i = size; i-- > 1;) {
            t[i] = combine(t[2 * i], t[2 * i + 1]);
        }
    }

    void apply(size_t p, size_t level, TMod up_mod) {
        if (p < size) {
            mod[p] = combineMod(mod[p], up_mod);
            t[p] = combineValue(t[p], up_mod);
            //t[p] = combineWithMod(t[2 * p], t[2 * p + 1], level, mod[p]);
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
        if (mod == 0) {
            return combine(left, right);
        }
        return combineValue(combine(left, right), mod);
    }

    T combine(T left, T right) {
        T res;
        for (int i = 0; i < Iters; i++) {
            res[i] = left[i] + right[i];
        }
        return res;
    }

    TMod combineMod(TMod mod, TMod up_mod) {
        return mod + up_mod;
    }

    T combineValue(T value, TMod up_mod) {
        T res;
        for (int i = 0; i < Iters; i++) {
            res[i] = value[std::min(Iters - 1, i + up_mod)];
        }
        return res;
    }

    T init() {
        return T{};
    }

    TMod modInit() {
        return 0;
    }
};

struct Solution {
    int n;
    std::vector<int> ds;
    std::vector<int> as;
    void init() {
        ds.resize(1000001);
        for (int i = 1; i < ds.size(); i++) {
            for (int j = i; j < ds.size(); j += i) {
                ds[j]++;
            }
        }
    }
    void run(std::istream& in, std::ostream& out) {
        init();
        int m;
        in >> n >> m;
        as.resize(n);
        for (int i = 0; i < n; i++) {
            in >> as[i];
        }
        std::vector<std::array<int64_t, Iters>> init(n);
        for (int i = 0; i < n; i++) {
            init[i][0] = as[i];
            for (int j = 1; j < Iters; j++) {
                init[i][j] = ds[init[i][j - 1]];
            }
        }
        LazyBinTreeUniversal tree(init);
        for (int i = 0; i < m; i++) {
            int t, l, r;
            in >> t >> l >> r;
            if (t == 1) {
                tree.modify(l - 1, r, 1);
            } else {
                out << tree.query(l - 1, r)[0] << std::endl;
            }
        }
    }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}