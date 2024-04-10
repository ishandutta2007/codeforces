#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 200200;
const int MX = 300300;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int ans = -1;
int a[N];
int up[N];
bool used[N];
vector < int > v[N];

void dfs(int x, int p)
{
    vector < pair < int, int > > g;
    for(int y: v[x]){
        if(y == p || used[y])
            continue;
        dfs(y, x);
        g.pb({a[y], y});
    }
    if(g.empty()){
        a[x] = 1;
        return;
    }
    sort(g.begin(), g.end());
    int cnt = 0;
    for(int i = 1; i < g.size(); i++){
        if(g[i - 1].fi == -1){
            continue;
        }
        if(g[i].fi == g[i - 1].fi){
            used[g[i].se] = true;
            cnt++;
        }
    }
    if(g.size() - cnt == 1 && a[g[0].se] != -1)
        a[x] = a[g[0].se] + 1;
    else
        a[x] = -1;
}

void trace(int x, int p)
{
    if(up[x] == -1)
        return;
    vector < pair < int, int > > g;
    for(int y: v[x]){
        if(y == p || used[y])
            continue;
        if(a[y] == up[x])
            used[y] = true;
        else
            g.pb({a[y], y});
    }
    if(g.size() == 0){
        ans = up[x] + 1;
        return;
    }
    sort(g.begin(), g.end());
    if(x == 1){
        if(g.size() == 1){
            if(g[0].fi != -1){
                ans = g[0].fi + 1;
                return;
            }
            up[g[0].se] = 1;
            trace(g[0].se, x);
            return;
        }
        if(g.size() == 2){
            if(g[0].fi != -1){
                ans = g[0].fi + g[1].fi + 1;
                return;
            }
            if(g[1].fi != -1){
                up[g[0].se] = g[1].fi + 1;
                trace(g[0].se, x);
            }
        }
        return;
    }
    if(g.size() > 1)
        return;
    if(g[0].fi != -1){
        ans = up[x] + g[0].fi + 1;
        return;
    }
    up[g[0].se] = up[x] + 1;
    trace(g[0].se, x);
}

void solve()
{
    cin >> n;
    for(int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1, -1);
    trace(1, -1);
    if(ans < 0){
        cout << ans << endl;
        return;
    }
    ans--;
    while(ans % 2 == 0 && ans > 1)
        ans = ans / 2;
    cout << ans << endl;
}

bool mtest = false; int main()
{
    //fin("input.txt");
    //fout("output.txt");
    //fin("friendcross.in");
    //fout("friendcross.out");
    ios_base::sync_with_stdio(0);
    int TE = 1;
    if(mtest)
        cin >> TE;
    while(TE--)
        solve();
}