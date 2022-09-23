#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int Q = 250200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int q;
int p[N];
vector < pair < int, pair < int, int > > > e;

int get(int x)
{
        return p[x] == x ? x : p[x] = get(p[x]);
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //freopen("tracking2.in", "r", stdin);
        //freopen("tracking2.out", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> q;
        for(int i = 1; i <= n; i++){
                p[i] = i;
        }
        for(int i = 1; i <= q; i++){
                int l, r, w;
                cin >> l >> r >> w;
                e.push_back({w, {l, r}});
        }
        vector < pair < int, int > > g;
        sort(e.begin(), e.end());
        int res = 0;
        for(int i = 0; i < q; ){
                g.clear();
                int j = i;
                while(j < q && e[j].fi == e[i].fi){
                        int x = e[j].se.fi, y = e[j].se.se;
                        if(get(x) != get(y)){
                                g.push_back({x, y});
                        }
                        j += 1;
                }
                for(auto gg: g){
                        int x = gg.fi, y = gg.se;
                        x = get(x);
                        y = get(y);
                        if(x == y){
                                res += 1;
                        }
                        else{
                                p[x] = y;
                        }
                }
                i = j;
        }
        cout << res << "\n";
}