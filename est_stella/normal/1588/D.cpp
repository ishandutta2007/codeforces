#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second
#define em emplaces
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf = 1e9;
const ll INF = 2e18;

int n;
string s[11];
int a[11][111];
bool chk[60];

int g[11][111][111];
int from[111][1111];
int fromb[111][1111];
int dp[111][1111];
bool vis[111][1111];

int conv(char c) {
    if('a' <= c && c <= 'z') return c - 'a' + 1;
    return c - 'A' + 27;
}

void dfs(int x, int bit) {
    vis[x][bit] = true;
    if(x == 0) return;

    int cnt = 0;
    for(int j=1; j<=n; j++) {
        if(g[j][0][((1 << j-1) & bit) ? x + 52 : x]) cnt++; 
    }
    if(cnt == n) dp[x][bit] = 1;
   
    for(int i=1; i<=52; i++) {
        int nbit = 0;
        cnt = 0;
        for(int j=1; j<=n; j++) {
            if(g[j][i + 52][((1 << j-1) & bit) ? x + 52 : x]) nbit |= 1 << j-1, cnt++;
            else if(g[j][i][((1 << j-1) & bit) ? x + 52 : x]) cnt++;
        }
        if(cnt < n) continue;

        if(!vis[i][nbit]) dfs(i, nbit);
        if(dp[i][nbit]+1 > dp[x][bit]) {
            dp[x][bit] = dp[i][nbit] + 1;
            from[x][bit] = i;
            fromb[x][bit] = nbit;
        }
    }
}

void solve() {
    memset(g, 0, sizeof(g));
    memset(from, 0, sizeof(from));
    memset(fromb, 0, sizeof(fromb));
    memset(dp, 0, sizeof(dp));
    memset(vis, 0, sizeof(vis));

    cin >> n;
    
    for(int i=1; i<=n; i++) {
        memset(chk, 0, sizeof(chk));
        cin >> s[i];

        for(int j=0; j<s[i].size(); j++) {
            int x = conv(s[i][j]);
            if(!chk[x]) {
                chk[x] = true;
            }
            else x += 52;
            a[i][j] = x;

            for(int k=0; k<j; k++) {
                g[i][a[i][k]][a[i][j]]++;
            }
            g[i][0][a[i][j]]++;
        }
    }

    for(int i=1; i<=52; i++) {
        for(int j=0; j<(1<<n); j++) {
            if(!vis[i][j]) dfs(i, j);
        }
    }

    int s = 0, bit = 0;
    for(int i=1; i<=52; i++) {
        for(int j=0; j<(1<<n); j++) {
            if(dp[i][j] > dp[s][bit]) {
                s = i;
                bit = j;
            }
        }
    }

    cout << dp[s][bit] << "\n";

    string ans;
    for(s; s; ) {
        int x = (s - 1) % 52;
        
        if(x < 26) ans += ('a' + x);
        else ans += ('A' + x - 26);

        int ns = from[s][bit];
        bit = fromb[s][bit];
        s = ns;
    }

    reverse(all(ans));
    cout << ans << "\n";
}

int main() {
    fast;

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}