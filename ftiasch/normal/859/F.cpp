#include <iostream>
#include <deque>
#include <utility>

const int N = 200000;
const long long INF = 1000000000000000000LL;

long long s[N + N + 1], dp[N + 1];

int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    long long c;
    std::cin >> n >> c;
    for (int i = 1, a; i < n << 1; ++ i) {
        std::cin >> a;
        s[i] = s[i - 1] + a;
    }
    dp[0] = 0;
    std::deque<std::pair<long long, int>> dq;
    dq.emplace_back(0, 0);
    long long prefix = -INF;
    for (int i = 1, j = 0; i <= n; ++ i) {
        while (j < i && s[2 * i - 1] - s[2 * j] >= c) {
            prefix = std::max(prefix, dp[j ++]);
        }
        while (!dq.empty() && dq.front().second < j) {
            dq.pop_front();
        }
        dp[i] = -INF;
        if (prefix > -INF) {
            dp[i] = std::max(dp[i], prefix + c);
        }
        if (!dq.empty()) {
            dp[i] = std::max(dp[i], dq.front().first + s[2 * i - 1]);
        }
        while (!dq.empty() && dq.back().first <= dp[i] - s[2 * i]) {
            dq.pop_back();
        }
        dq.emplace_back(dp[i] - s[2 * i], i);
    }
    std::cout << dp[n] << std::endl;
}