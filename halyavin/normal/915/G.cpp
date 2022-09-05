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

const int mod = 1000000007;

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

int mul32(int x, int y) {
  return int(int64_t(x) * y % mod);
}

int pow(int x, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) {
            res = mul32(res, x);
        }
        x = mul32(x, x);
        n /= 2;
    }
    return res;
}

void run(std::istream &in, std::ostream &out) {
    int n, k;
    in >> n >> k;
    std::vector<int> fs(k + 1);
    for (int i = 1; i <= k; i++) {
        fs[i] = pow(i, n);
    }
    for (int i = k; i > 0; i--) {
        fs[i] = sub32(fs[i], fs[i - 1]);
    }
    for (int i = 1; i <= k; i++) {
        int tmp = fs[i];
        for (int j = 2 * i; j <= k; j += i) {
            fs[j] = sub32(fs[j], tmp);
        }
    }
    int ans = 0;
    int sum = 0;
    for (int i = 1; i <= k; i++) {
        /*int res = i == 1 ? fs[1] : sub32(fs[i], fs[1]);
        for (int d : primeDiv[i]) {
            res = sub32(res, fs[d]);
        }
        fs[i] = res;
        sum = add32(sum, res);*/
        sum = add32(sum, fs[i]);
        //out << res << std::endl;
        ans = add32(ans, sum ^ i);
    }
    out << ans << "\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}