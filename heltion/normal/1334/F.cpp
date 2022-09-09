#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 500000;
constexpr LL inf = 1E16;
int a[maxn + 2], b[maxn + 2], p[maxn + 1];
LL dp[maxn + 2];
vector<int> vv[maxn + 2];
LL sm[maxn + 1];
void add(int p, int x){
    for(; p <= maxn; p += p & -p) sm[p] += x;
}
LL sum(int p){
    LL res = 0;
    for(; p; p -= p & -p) res += sm[p];
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i += 1) cin >> a[i];
    a[n + 1] = n + 1;
    for(int i = n + 1; ~i; i -= 1) vv[a[i]].push_back(i);
    for(int i = 1; i <= n; i += 1) cin >> p[i];
    int m;
    cin >> m;
    for(int i = 1; i <= m; i += 1) cin >> b[i];
    b[m + 1] = n + 1;
    for(int i = 1; i <= n; i += 1) if(p[i] < 0) add(i, p[i]);
    for(int i = m + 1; i; i -= 1){
        int u = b[i], v = b[i - 1];
        //for(int x : vv[u]) cout << x << " " << dp[x] << "\n";
        for(int j = v + 1; j <= u; j += 1)
            for(int k : vv[j])
                if(p[k] > 0)
                    add(k, p[k]);
        for(int p = 0, q = -1, x = -1; p < (int)vv[v].size(); p += 1){
            dp[vv[v][p]] = inf;
            if(x != -1) dp[vv[v][p]] = sum(x - 1) - sum(vv[v][p]) + dp[x];
            while(q + 1 < (int)vv[u].size() and vv[u][q + 1] > vv[v][p]){
                q += 1;
                if(sum(vv[u][q] - 1) - sum(vv[v][p]) + dp[vv[u][q]] < dp[vv[v][p]]){
                    x = vv[u][q];
                    dp[vv[v][p]] = sum(x - 1) - sum(vv[v][p]) + dp[x];
                }
            }
        }
    }
    if(dp[0] > 1E15) cout << "NO";
    else cout << "YES\n" <<dp[0];
    return 0;
}