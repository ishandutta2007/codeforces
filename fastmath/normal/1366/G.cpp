#include<bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC

#ifdef HOME
const int N = 41;
#else
const int N = 10001;
#endif
int dp[N][N];
int link[N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    for (int i = 0; i < n; ++i) {
        link[i] = n;
        if (s[i] != '.') {
            int cur = 0;
            for (int j = i; j < n; ++j) {
                if (s[j] == '.')
                    --cur;
                else
                    ++cur;
                if (cur == 0) {
                    link[i] = j;
                    break;
                }   
            }   
        }
    }
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            dp[i][j] = N;
    auto rel = [](int &a, int b) { a = min(a, b); };
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= m; ++j) {
            if (dp[i][j] == N)
                continue;
            if (s[i] == t[j]) {
                rel(dp[i + 1][j + 1], dp[i][j]);
            }   
            if (link[i] != n) {
                rel(dp[link[i]+1][j], dp[i][j]);
            }
            rel(dp[i + 1][j], dp[i][j] + 1);
        }   

    if (dp[n][m] == N) {
        cout << -1 << endl;
        exit(0);
    }   

    cout << dp[n][m] << endl;
}