#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

const int p = 998244353;

int add32(int x, int y) {
    int res = x + y;
    if (res >= p) res -= p;
    return res;
}

int sub32(int x, int y) {
    int res = x - y;
    if (res < 0) res += p;
    return res;
}

int mul32(int x, int y) {
    return int64_t(x) * y % p;
}

struct Solution {
    int n, k;
    std::vector<int> as;
    std::vector<std::vector<int>> dyn;
    std::vector<int> combs;

    void run(std::istream &in, std::ostream &out) {
        in >> n >> k;
        as.assign(n, 0);
        for (int i = 0; i < n; i++) {
            in >> as[i];
        }
        std::sort(as.begin(), as.end());
        dyn.assign(n, std::vector<int>(k));
        combs.resize(100000 / (k - 1) + 2);
        std::cerr << combs.size() << std::endl;
        for (int i = 0; i < combs.size(); i++) {
            //std::cerr << "Iter " << i << std::endl;
            std::fill(dyn[0].begin(), dyn[0].end(), 0);
            dyn[0][0] = 1;
            int prev = -1;
            for (int j = 1; j < n; j++) {
                while (prev + 1 < j && as[prev + 1] <= as[j] - i) prev++;
                //std::cerr << "pos " << j << " prev = " << prev << std::endl;
                if (prev < 0) {
                    dyn[j] = dyn[j-1];
                    dyn[j][0] = add32(1, dyn[j][0]);
                } else {
                    dyn[j][0] = add32(1, dyn[j - 1][0]);
                    for (int l = 1; l < k; l++) {
                        dyn[j][l] = add32(dyn[j - 1][l], dyn[prev][l - 1]);
                    }
                }
                /*for (int l = 0; l < k; l++) {
                    std::cerr << dyn[j][l] << " ";
                }
                std::cerr << std::endl;*/
            }
            combs[i] = dyn[n - 1][k - 1];
        }
        /*for (int i = 0; i < combs.size(); i++) {
            if (combs[i] != 0) {
                std::cerr << i << " " << combs[i] << "\n";
            }
        }*/
        int ans = 0;
        for (int i = 0; i + 1 < combs.size(); i++) {
            int diff = sub32(combs[i], combs[i + 1]);
            ans = add32(ans, mul32(diff, i));
        }
        out << ans << "\n";

    }
};

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solution().run(std::cin, std::cout);
    return 0;
}