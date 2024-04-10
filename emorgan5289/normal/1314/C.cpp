#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

const int N = 1005;
ll n, m, k;
string s;
int lcp[N][N], c[N][N];
ll dp[N][N];

ll query(int x, int len) {
    debug(x, len, s.substr(x, len));
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        if (lcp[x][i] >= len)
            r[i] = i+len-1;
        else if (c[i][x])
            r[i] = n;
        else
            r[i] = i+lcp[x][i];
    }
    debug(r);
    for (int i = 0; i < N; i++)
        fill(dp[i], dp[i]+N, 0);
    dp[n][0] = 1;
    for (int i = n-1; i >= 0; i--)
        for (int j = 0; j <= m; j++) {
            dp[i][j] = (i == 0 ? 0 : dp[i+1][j]) + (j == 0 ? 0 : dp[r[i]+1][j-1]);
            cmin(dp[i][j], inf_ll);
        }
    debug(dp[0][m]);
    return dp[0][m];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k >> s;
    s += '$';
    for (int i = n-1; i >= 0; i--)
        for (int j = n-1; j >= 0; j--) {
            lcp[i][j] = s[i] == s[j] ? 1+lcp[i+1][j+1] : 0;
            c[i][j] = s[i+lcp[i][j]] < s[j+lcp[i][j]];
        }
    vector<array<int, 2>> subs;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            subs.pb({i, j-i+1});
    sort(all(subs), [&](auto x, auto y){
        return lcp[x[0]][y[0]] < min(x[1], y[1]) ? c[x[0]][y[0]] : x[1] < y[1];
    });
    int x = 0;
    for (int i = 1<<20; i > 0; i >>= 1)
        if (x+i < subs.size() && query(subs[x+i][0], subs[x+i][1]) >= k)
            x += i;
    cout << s.substr(subs[x][0], subs[x][1]) << "\n";
}