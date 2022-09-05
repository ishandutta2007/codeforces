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

struct Solution {
    int n, r;
    std::vector<int> f;
    std::vector<int> s;
    std::vector<double> p;
    std::vector<std::vector<double>> dyn;

    double getRes(double T) {
        for (int i = 0; i <= r; i++) {
            dyn[n][i] = 0;
        }
        for (int i = n - 1; i >= 0; i--) {
            int ff = f[i];
            int ss = s[i];
            double pp = p[i];
            for (int j = 0; j <= r; j++) {
                double res = i == 0 ? 1e+20 : T;
                double ft = (j + ff <= r) ? (dyn[i + 1][j + ff] + ff) : (ff + T);
                double st = (j + ss <= r) ? (dyn[i + 1][j + ss] + ss) : (ss + T);
                res = std::min(res, ft * pp + st * (1 - pp));
                dyn[i][j] = res;
            }
        }
        return dyn[0][0];
    }

    void run(std::istream& in, std::ostream& out) {
        in >> n >> r;
        f.resize(n);
        s.resize(n);
        p.resize(n);
        for (int i = 0; i < n; i++) {
            int pi;
            in >> f[i] >> s[i] >> pi;
            p[i] = pi / 100.0;
        }
        dyn.resize(n + 1, std::vector<double>(r + 1));
        double left = std::accumulate(f.begin(), f.end(), 0);
        double right = 1e+20;
        for (int i = 0; i < 120; i++) {
            double middle = (left + right) / 2;
            double res = getRes(middle);
            if (res > middle) {
                left = middle;
            } else {
                right = middle;
            }
        }
        out.precision(15);
        out << left << std::endl;
    }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}