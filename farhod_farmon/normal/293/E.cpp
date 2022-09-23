#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long MX = sqrt(N);
const long long H = 17;
const long long MAGIC = 1000;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int L;
int W;
int t[N];
int s[N];
int d1[N];
int d2[N];
bool used[N];
vector < pair < int, int > > v[N];

void upd(int x, int g)
{
        x++;
        while(x < N){
                t[x] += g;
                x += x & -x;
        }
}

int get(int x)
{
        x++;
        if(x < 0){
                return 0;
        }
        int cnt = 0;
        while(x > 0){
                cnt += t[x];
                x -= x & -x;
        }
        return cnt;
}

vector < pair < int, int > > g;
queue < pair < int, int > > q;

ll con(int x, int pp)
{
        g.clear();
        ll cnt = 0;
        q.push({x, pp});
        while(!q.empty()){
                int y = q.front().fi;
                int par = q.front().se;
                q.pop();
                g.pb({d2[y], d1[y]});
                for(auto p: v[y]){
                        if(used[p.fi] || par == p.fi){
                                continue;
                        }
                        d1[p.fi] = d1[y] + 1;
                        d2[p.fi] = d2[y] + p.se;
                        q.push({p.fi, y});
                }
        }
        sort(g.begin(), g.end());
        int j = -1;
        for(int i = 0; i < g.size(); i++){
                while(j + 1 < i && g[j + 1].fi + g[i].fi <= W){
                        j++;
                        upd(g[j].se, 1);
                }
                while(j >= 0 && g[j].fi + g[i].fi > W){
                        upd(g[j].se, -1);
                        j--;
                }
                cnt += get(L - g[i].se);
        }
        while(j >= 0){
                upd(g[j].se, -1);
                j--;
        }
        return cnt;
}

void dfs(int x, int p)
{
        s[x] = 1;
        for(auto y: v[x]){
                if(used[y.fi] || y.fi == p){
                        continue;
                }
                dfs(y.fi, x);
                s[x] += s[y.fi];
        }
}

int trace(int x, int p, int sz)
{
        int mx = sz - s[x];
        for(auto y: v[x]){
                if(used[y.fi] || y.fi == p){
                        continue;
                }
                int g = trace(y.fi, x, sz);
                if(g != -1){
                        return g;
                }
                mx = max(mx, s[y.fi]);
        }
        if(mx <= sz / 2){
                return x;
        }
        return -1;
}

ll dv(int x)
{
        dfs(x, -1);
        int root = trace(x, -1, s[x]);
        used[root] = true;
        d1[root] = d2[root] = 0;
        ll ans = con(root, -1);
        for(auto y: v[root]){
                if(used[y.fi]){
                        continue;
                }
                d1[y.fi] = 1;
                d2[y.fi] = y.se;
                ans -= con(y.fi, root);
        }
        for(auto y: v[root]){
                if(!used[y.fi]){
                        ans += dv(y.fi);
                }
        }
        return ans;
}

void solve()
{
        cin >> n >> L >> W;
        for(int i = 2; i <= n; i++){
                int p, w;
                cin >> p >> w;
                v[p].pb({i, w});
                v[i].pb({p, w});
        }
        cout << dv(1) << endl;
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("landscape.in");
        //fout("landscape.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}