#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC

const int N = 2007, INF = 1e9 + 7;
int dp[N][N];
string a[N];
bool usedx[N], usedy[N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            dp[i][j] = INF;            
    queue <ii> q;
    for (int i = 0; i < m; ++i) {
        if (a[n - 1][i] == '#') {
            q.push(mp(n - 1, i));
            dp[n - 1][i] = 1;                    
        }   
    }
    int ans = INF;
    while (q.size()) {
        auto p = q.front(); q.pop();
        int x = p.f, y = p.s;

        if (x == 0) 
            ans = min(ans, dp[x][y]);

        if (!usedx[x]) {
            usedx[x] = 1;
            for (int j = 0; j < m; ++j) {
                if (a[x][j] == '.')
                    continue;
                if (dp[x][y] + 1 < dp[x][j]) {
                    dp[x][j] = dp[x][y] + 1;
                    q.push(mp(x, j));
                }   
            }   
        }   
        if (!usedy[y]) {
            usedy[y] = 1;
            for (int i = 0; i < n; ++i) {
                if (a[i][y] == '.')
                    continue;
                if (dp[x][y] + 1 < dp[i][y]) {
                    dp[i][y] = dp[x][y] + 1;
                    q.push(mp(i, y));
                }      
            }   
        }   
    }   

    if (ans == INF)
        cout << "-1" << endl;
    else
        cout << ans << endl;
}