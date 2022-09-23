#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 1e9 + 7;
const long long m1 = 999998727899999ll;

using namespace std;

int n;
int m;
int d[N];
int in[N];
int f[N][20];
vector < int > g[N];
vector < pair < int, int > > v[N];
vector < pair < int, int > > vg[N];
long long h[N];
long long res[N];

long long get(int x, int l, int extra)
{
        for(int i = 19; i >= 0; i--){
                if(d[f[x][i]] > l){
                        x = f[x][i];
                }
        }
        if(d[x] > l){
                extra = in[x];
                x = f[x][0];
        }
        assert(d[x] <= l);
        long long res = 0;
        res = h[x];
        for(int i = 0; i < l - d[x]; i++){
                res = (res * 13 + g[extra][i]) % m1;
        }
        return res;
}

int get_c(int x, int l, int extra)
{
        for(int i = 19; i >= 0; i--){
                if(d[f[x][i]] >= l){
                        x = f[x][i];
                }
        }
        if(d[x] >= l){
                extra = in[x];
                x = f[x][0];
        }
        return g[extra][l - d[x] - 1];
}

bool better(pair < int, int > x, pair < int, int > y)
{
        int l = 1, r = d[x.fi] + g[x.se].size();
        while(l < r){
                int m = (l + r) / 2;
                if(get(x.fi, m, x.se) == get(y.fi, m, y.se)){
                        l = m + 1;
                } else{
                        r = m;
                }
        }
        return get_c(x.fi, l, x.se) < get_c(y.fi, l, y.se);
}

void add(int x, pair < int, int > p)
{
        f[x][0] = p.fi;
        for(int i = 1; i < 20; i++){
                f[x][i] = f[f[x][i - 1]][i - 1];
        }
        in[x] = p.se;
        h[x] = h[p.fi];
        for(int z: g[p.se]){
                h[x] = (h[x] * 13 + z) % m1;
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back({y, i});
                v[y].push_back({x, i});
                for(int j = i; j > 0; j /= 10){
                        g[i].push_back(j % 10);
                }
                reverse(g[i].begin(), g[i].end());
        }
        for(int i = 1; i <= n; i++){
                d[i] = 1e9;
        }
        d[1] = 0;
        set < pair < int, int > > s;
        s.insert({0, 1});
        while(!s.empty()){
                int x = s.begin()->se;
                s.erase(s.begin());
                for(auto p: v[x]){
                        if(d[x] + g[p.se].size() < d[p.fi]){
                                s.erase({d[p.fi], p.fi});
                                d[p.fi] = d[x] + g[p.se].size();
                                s.insert({d[p.fi], p.fi});
                        }
                }
        }
        vector < int > ord;
        for(int i = 1; i <= n; i++){
                if(i > 1){
                        ord.push_back(i);
                }
                for(auto p: v[i]){
                        if(d[i] + g[p.se].size() == d[p.fi]){
                                vg[p.fi].push_back({i, p.se});
                        }
                }
        }
        sort(ord.begin(), ord.end(), [&](int x, int y){
                return d[x] < d[y];
        });
        for(int i = 0; i < 20; i++){
                f[1][i] = 1;
        }
        for(int x: ord){
                int par = 0;
                for(int i = 1; i < (int)vg[x].size(); i++){
                        if(better(vg[x][i], vg[x][par])){
                                par = i;
                        }
                }
                add(x, vg[x][par]);
                res[x] = res[vg[x][par].fi];
                for(int z: g[vg[x][par].se]){
                        res[x] = (res[x] * 10ll + z) % mod;
                }
        }
        for(int i = 2; i <= n; i++){
                cout << res[i] << "\n";
        }
}