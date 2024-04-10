#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <array>

const int mod = 1000000007;

int add32(int x, int y) {
    return (x + y) % mod;
}

int mul32(int x, int y) {
    return (int64_t(x) * y) % mod;
}

void run(std::istream &in, std::ostream &out) {
    int n;
    in >> n;
    std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            in >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        a[i][n] = a[i][0];
        a[n][i] = a[0][i];
    }
    std::vector<std::vector<std::array<int, 3>>> dyn(n);
    for (int i = 0; i < n; i++) {
        dyn[i].resize(n - i + 1);
    }
    std::fill(dyn[0].begin(), dyn[0].end(), std::array<int, 3>{1, 1, 1});
    for (int len = 1; len < n; len++) {
        for (int i = 1; i < dyn[len].size(); i++) {
            int res = 0;
            for (int start = 0; start < len; start++) {
                if (a[i - 1][i + start] == 0) continue;
                res = add32(res, mul32(dyn[start][i][2], dyn[len - start - 1][i + start + 1][0]));
            }
            dyn[len][i][0] = res;
            res = 0;
            for (int start = 0; start < len; start++) {
                if (a[i + len][i + start] == 0) continue;
                res = add32(res, mul32(dyn[start][i][1], dyn[len - start - 1][i + start + 1][2]));
            }
            dyn[len][i][1] = res;
            res = dyn[len][i][1];
            for (int start = 0; start < len; start++) {
                if (a[i - 1][i + start] == 0) continue;
                res = add32(res, mul32(dyn[start][i][2], dyn[len - start - 1][i + start + 1][2]));
            }
            dyn[len][i][2] = res;
        }
    }
    int res = 0;
    for (int i = 1; i < n; i++) {
        if (a[0][i] == 0) continue;
        res = add32(res, mul32(dyn[i - 1][1][1], dyn[n - i - 1][i + 1][2]));
    }
    /*for (int i = 0; i < n; i++) {
        for (int j = 1; j < dyn[i].size(); j++) {
            std::cout << i << " " << j << " " << dyn[i][j][0] << " " << dyn[i][j][1] << " " << dyn[i][j][2] << std::endl;
        }
    }*/
    out << res << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}