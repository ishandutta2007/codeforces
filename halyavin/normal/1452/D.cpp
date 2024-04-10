#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

const int mod = 998'244'353;

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

void run(std::istream &in, std::ostream &out) {
    int half = inv(2);
    int quarter = inv(4);
    int n;
    in >> n;
    std::vector<int> dyn(n + 1);
    std::vector<int> dyn2(n + 1);
    dyn[0] = 1;
    dyn2[0] = 1;
    for (int i = 1; i <= n; i++) {
        dyn[i] = mul32(half, dyn2[i-1]);
        dyn2[i] = add32(dyn[i], mul32(quarter, i >= 2 ? dyn2[i - 2] : 0));
    }
    out << dyn[n] << "\n";
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}