#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

const int mod = 998244353;

int mul32(int x, int y) {
    return int(int64_t(x) * y % mod);
}

int add32(int x, int y) {
    int res = x + y;
    if (res >= mod) res -= mod;
    return res;
}

int sub32(int x, int y) {
    int res = x - y;
    if (res < 0) res += mod;
    return res;
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

int calcProb(std::vector<int>& dist, int n) {
    int result = 0;
    int cur = 1;
    std::sort(dist.begin(), dist.end());
    for (int i = 0; i < n; i++) {
        int d = dist[i];
        int bound = n - d + 1;
        if (bound >= n - i) {
            return 1;
        }
        int p = mul32((n - i) - bound, inv(n - i));
        cur = mul32(cur, p);
    }
    return sub32(1, cur);
}

void run(std::istream& in, std::ostream& out) {
    int n, m;
    in >> n >> m;
    std::vector<std::vector<int>> as(m, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            in >> as[j][i];
        }
    }
    int result = 0;
    for (int i = 0; i < m; i++) {
        result = add32(result, calcProb(as[i], n));
    }
    out << result << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    run(std::cin, std::cout);
    return 0;
}