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

struct LazyBinTreeUniversal {
    using T = int;
    using TMod = std::array<uint8_t, 101>;
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
            if (mod[p][0] == 0) {
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
            if (mod[pos][0] != 0) {
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
        TMod result = {};
        for (size_t i = 0; i < result.size(); i++) {
            result[i] = up_mod[mod[i]];
        }
        return result;
    }

    T combineValue(T value, const TMod& up_mod) {
        return up_mod[value];
    }

    T init() {
        return 0;
    }

    TMod modInit() {
        TMod result = {};
        std::iota(result.begin(), result.end(), 0);
        return result;
    }
};

void run(std::istream &in, std::ostream &out) {
    int n;
    in >> n;
    std::vector<int> as(n);
    for (int i = 0; i < n; i++) {
        in >> as[i];
    }
    LazyBinTreeUniversal tree(as);
    int q;
    in >> q;
    for (int i = 0; i < q; i++) {
        size_t l, r, x, y;
        in >> l >> r >> x >> y;
        l--;
        LazyBinTreeUniversal::TMod mod = {};
        std::iota(mod.begin(), mod.end(), 0);
        mod[0] = 1;
        mod[x] = y;
        tree.modify(l, r, mod);
    }
    for (int i = 0; i < n; i++) {
        out << tree.query(i) << " ";
    }
    out << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    run(std::cin, std::cout);
    return 0;
}