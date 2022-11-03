#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 2e6 + 13;

int sum(int a, int b) {
    int res = a + b;

    while(res >= M)
        res -= M;

    return res;
}

int dp[N];
int s[N];

void solve() {
    int n;
    cin >> n;

    cout << (n >= 3 ? s[n - 3] * 4ll % M : 0) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    dp[0] = dp[1] = 1;
    s[0] = s[1] = 1;
    for(int i = 2; i < N; i++) {
        dp[i] = sum(dp[i - 1], sum(dp[i - 2], dp[i - 2]));
//        s[i] = sum(s[i - 1], (i % 3 == 0 ? dp[i] : 0));
        s[i] = sum((i >= 3 ? s[i - 3] : 0), dp[i]);
    }

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}