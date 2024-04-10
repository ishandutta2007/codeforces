#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 77;
const long long mod = 998244353;

using namespace std;

int n;
int m;
int a;
int b;
int p[N];
int d[1 << 17][N];
int id[N];
int c[N];
int res[N];
bool big[N];
vector < pair < int, int > > v[N];
set < pair < int, int > > s[1 << 17];

int get(int x)
{
        return x == p[x] ? x : p[x] = get(p[x]);
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m >> a >> b;
        for(int i = 1; i <= n; i++){
                p[i] = i;
        }
        for(int i = 1; i <= m; i++){
                int x, y, c;
                cin >> x >> y >> c;
                v[x].push_back({y, c});
                v[y].push_back({x, c});
                if(c == a){
                        x = get(x);
                        y = get(y);
                        if(x != y){
                                p[x] = y;
                        }
                }
        }
        for(int i = 1; i <= n; i++){
                int x = get(i);
                c[x] += 1;
        }
        int G = 0;
        for(int i = 1; i <= n; i++){
                if(c[i] >= 4){
                        big[i] = true;
                        id[i] = G++;
                }
                res[i] = 1e9;
        }
        int f, x, ni;
        for(int i = 0; i < (1 << G); i++){
                for(int j = 1; j <= n; j++){
                        d[i][j] = 1e9;
                }
        }
        ni = 0; f = p[1];
        if(big[f]){
                ni = 1 << id[f];
        }
        d[ni][1] = 0;
        s[ni].insert({0, 1});
        for(int i = 0; i < (1 << G); i++){
                while(!s[i].empty()){
                        x = s[i].begin()->se;
                        s[i].erase(s[i].begin());
                        for(auto y: v[x]){
                                f = p[y.fi];
                                if(big[f] && y.se == b && i & (1 << id[f])){
                                        continue;
                                }
                                if(y.se == b && f == p[x]){
                                        continue;
                                }
                                ni = i;
                                if(big[f]){
                                        ni |= 1 << id[f];
                                }
                                if(d[i][x] + y.se < d[ni][y.fi]){
                                        s[ni].erase({d[ni][y.fi], y.fi});
                                        d[ni][y.fi] = d[i][x] + y.se;
                                        s[ni].insert({d[ni][y.fi], y.fi});
                                }
                        }
                }
                for(int j = 1; j <= n; j++){
                        res[j] = min(res[j], d[i][j]);
                }
        }
        for(int i = 1; i <= n; i++){
                cout << res[i] << " ";
        }
}