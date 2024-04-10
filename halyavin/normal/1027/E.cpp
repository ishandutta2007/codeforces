#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

const int mod = 998244353;

int add32(int x, int y) {
    int res = x + y;
    if (res >= mod) {
        res -= mod;
    }
    return res;
}

int sub32(int x, int y) {
    int res = x - y;
    if (res < 0) res += mod;
    return res;
}

int mul32(int x, int y) {
    return (int64_t(x) * y) % mod;
}

template<class T>
std::pair<T, T> gcd2(T x, T y) {
    if (x == 0) {
        return {0, 1};
    }
    T s = y / x;
    std::pair<T, T> res = gcd2(y % x, x);
    return {res.second - s * res.first, res.first};
}

template<class T>
T inv(T x, T p) {
    x = x % p;
    if (x < 0) {
        x += p;
    }
    std::pair<T, T> res = gcd2(x, p);
    if (res.first < 0) {
        res.first += p;
    }
    if (res.first >= p) {
        res.first -= p;
    }
    return res.first;
}

int inv(int x) {
    return inv(x, mod);
}

struct Solution {
    int n, k;
    std::vector<std::vector<std::vector<int>>> dyn;
    std::vector<int> final;

    void run(std::istream &in, std::ostream &out) {
        in >> n >> k;
        dyn.resize(n);
        for (int i = 0; i < n; i++) {
            dyn[i].assign(i + 1, std::vector<int>(i + 1));
        }
        dyn[0][0][0] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                for (int k = 0; k < i; k++) {
                    dyn[i][j + 1][std::max(k, j + 1)] = add32(dyn[i][j + 1][std::max(k, j + 1)], dyn[i-1][j][k]);
                    dyn[i][0][k] = add32(dyn[i][0][k], dyn[i-1][j][k]);
                }
            }
        }
        final.assign(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                final[i] = add32(final[i], dyn[n - 1][j][i]);
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((i + 1) * (j + 1) < k) {
                    res = add32(res, mul32(final[i], final[j]));
                }
            }
        }
        res = add32(res, res);
        out << res << "\n";
    }
};

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solution().run(std::cin, std::cout);
    return 0;
}