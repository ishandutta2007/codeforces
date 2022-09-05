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

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

struct BinTree1 {
    using T = int;
    size_t size;
    std::vector<T> t;

    BinTree1(size_t N) :
        size(N),
        t(2 * N) { }

    BinTree1(const std::vector<T>& other) :
        size(other.size()),
        t(2 * other.size()) {
        std::copy(other.begin(), other.end(), t.begin() + size);
        for (size_t i = size; i-- > 1;) {
            t[i] = combine(t[2 * i], t[2 * i + 1]);
        }
    }

    T get(size_t p) {
        return t[p + size];
    }

    void modify(size_t p, T value) {
        p += size;
        t[p] = value;
        while (p > 1) {
            p = p / 2;
            t[p] = combine(t[2 * p], t[2 * p + 1]);
        }
    }

    T query(size_t l, size_t r) {
        l += size;
        r += size;
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
            l = l / 2;
            r = r / 2;
        }
        return combine(left, right);
    }

    bool check(size_t l, size_t r, int x) {
        int a = query(l, r);
        if (a % x == 0) return true;
        while (r - l > 1) {
            size_t m = (l + r) / 2;
            int a1 = query(l, m);
            int a2 = query(m, r);
            if (a1 % x == 0) {
                l = m;
            } else if (a2 % x == 0) {
                r = m;
            } else {
                return false;
            }
        }
        return true;
    }

  private:
    T combine(T left, T right) {
        return gcd(left, right);
    }

    T init() {
        return 0;
    }
};

void run(std::istream &in, std::ostream &out) {
    int n;
    in >> n;
    std::vector<int> as(n);
    for (int i = 0; i < n; i++) {
        in >> as[i];
    }
    BinTree1 tree(as);
    int q;
    in >> q;
    for (int i = 0; i < q; i++) {
        int t;
        in >> t;
        if (t == 1) {
            int l, r, x;
            in >> l >> r >> x;
            l--;
            if (tree.check(l, r, x)) {
                out << "YES\n";
            } else {
                out << "NO\n";
            }
        } else {
            int p, y;
            in >> p >> y;
            tree.modify(p - 1, y);
        }
    }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}