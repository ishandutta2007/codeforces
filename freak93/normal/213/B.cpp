#include <iostream>
#include <vector>

using namespace std;

const int mod = 1000000007;

int powm(int x, int y) {
    if (y == 1)
        return x;
    int v = powm(x, y / 2);
    v = (1LL * v * v) % mod;
    if (y % 2) {
        v = (1LL * v * x) % mod;
    }

    return v;
}

int main() {
    int N; cin >> N;
    vector<int> A(10);

    for (auto &it:A)
        cin >> it;

    vector<int> fact(N + 1, 1), ifact(N + 1, 1);
    for (int i = 1; i <= N; ++i) {
        fact[i] = (1LL * fact[i - 1] * i) % mod;
        ifact[i] = powm(fact[i], mod - 2);
    }

    vector< vector<int> > dp(10, vector<int>(N + 1, 0));

    for (int i = A[1]; i <= N; ++i)
        dp[1][i] = 1;

    for (int i = 2; i <= 10; ++i) {
        for (int j = 0; j <= N; ++j)
            for (int k = A[i % 10]; k <= j - (i / 10); ++k) {
                int ways = fact[j - (i / 10)];
                ways  = (1LL * ways * ifact[k]) % mod;
                ways = (1LL * ways * ifact[(j - i / 10) - k]) % mod;
                dp[i % 10][j] = (dp[i % 10][j] + 1LL * dp[i - 1][j - k] * ways) % mod;
            }
    }

    int answer = 0;
    for (int i = 1; i <= N; ++i)
        answer = (answer + dp[0][i]) % mod;

    cout << answer;
}