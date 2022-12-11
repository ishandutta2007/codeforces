#include <bits/stdc++.h>
using namespace std;
           
#define ll long long
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n;
int p[100007];
vector<int> g[100007];
ll d[100007];
ll a[100007];

void dfs(int v, ll sum){
    if (d[v] == -1){
        ll val = (ll)1e18;
        for (int to : g[v]){
            val = min(val, d[to]);
        }   
        if (val == (ll)1e18){
            a[v] = 0;
            return;
        }
        if (val < sum) cout << -1, exit(0);
        a[v] = val - sum;
    } else {
        a[v] = d[v] - sum;
        if (a[v] < 0) cout << -1, exit(0);
    }
    sum += a[v];
    for (int to : g[v]){
        dfs(to, sum);
    }
}

int main(){
   // freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 2; i <= n; i++) cin >> p[i], g[p[i]].pb(i);
    for (int i = 1; i <= n; i++) cin >> d[i];
    dfs(1, 0);
    ll ans = 0;
    for (int i = 1; i <= n; i++) ans += a[i];
    cout << ans;
}