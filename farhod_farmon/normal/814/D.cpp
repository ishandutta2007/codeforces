#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1010;
const long long MX = 1000100;
const long long MAGIC = 1000;
const long long mod = 1e9 + 7;

using namespace std;

long double pi = acos(-1);

ll n;
ll x[N];
ll y[N];
ll r[N];
ll p[N];
long double a[N];
long double d[N];
bool used[N];
vector < ll > v[N];

ll get(ll x)
{
        return p[x] == x ? x : p[x] = get(p[x]);
}

void dfs(int x)
{
        for(int y: v[x]){
                dfs(y);
                d[x] += d[y];
        }
        d[x] = a[x] - d[x];
}

void solve()
{
        cin >> n;
        vector < pair < int, int > > g;
        for(int i = 1; i <= n; i++){
                cin >> x[i] >> y[i] >> r[i];
                p[i] = i;
                g.pb({r[i], i});
                a[i] = 1.0 * pi * r[i] * r[i];
        }
        sort(g.begin(), g.end());
        for(int i = 0; i < g.size(); i++){
                for(int j = i - 1; j >= 0; j--){
                        int a = g[i].se, b = g[j].se;
                        ll l = (x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]);
                        if(l <= r[a] * r[a]){
                                if(get(a) != get(b)){
                                        v[a].pb(b);
                                        p[get(a)] = get(b);
                                        used[b] = true;
                                }
                        }
                }
        }
        long double ans = 0;
        for(int i = 1; i <= n; i++){
                if(used[i] == false){
                        for(int j: v[i]){
                                dfs(j);
                                ans += d[j];
                        }
                        ans += a[i];
                }
        }
        cout << fixed << setprecision(9) << ans << endl;
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("cowjog.in");
        //fout("cowjog.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}