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
    return (int64_t(x) * y) % p;
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
T inv(T x) {
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

int div32(int x, int y) {
    return mul32(x, inv(y));
}

struct Solution {
    int n;
    std::vector<int> as;
    std::vector<int> stat;
    int k;
    std::vector<int> compA;
    std::vector<int> compC;
    std::vector<int> compSum;
    std::vector<std::vector<int>> dyn;
    std::vector<int> curSum;
    void run(std::istream &in, std::ostream &out) {
        in >> n;
        as.resize(n);
        for (int i = 0; i < n; i++) {
            in >> as[i];
        }
        stat.resize(n + 1);
        for (int i = 0; i < n; i++) {
            stat[as[i]]++;
        }
        k = 0;
        compA.clear();
        compC.clear();
        compSum.clear();
        int sum = 0;
        for (int i = 0; i <= n; i++) {
            if (stat[i] != 0) {
                compA.push_back(i);
                compC.push_back(stat[i]);
                compSum.push_back(sum);
                sum += stat[i];
                k++;
            }
        }
        curSum.assign(n + 1, 0);
        dyn.assign(k, std::vector<int>());
        for (int i = 0; i < k; i++) {
            dyn[i].assign(compSum[i] + 1, 0);
        }
        for (int i = k - 1; i >= 0; i--) {
            for (int b = 0; b < dyn[i].size(); b ++) {
                int fr = inv(n - b - 1);
                int res = add32(compC[i] - 1, curSum[b + 1]);
                dyn[i][b] = mul32(res, fr);
            }
            for (int b = 0; b < dyn[i].size(); b++) {
                curSum[b] = add32(curSum[b], mul32(compC[i], dyn[i][b]));
            }
        }
        int ans = 0;
        for (int i = 0; i < k; i++) {
            ans = add32(ans, mul32(compC[i], dyn[i][0]));
        }
        ans = div32(ans, n);
        out << ans << "\n";
    }
};

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solution().run(std::cin, std::cout);
    return 0;
}