#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int mod = 998244353;

using namespace std;

int n;
int tim;
int tin[N];
int tout[N];
int f[N][18];
long long d[N];
vector < pair < int, int > > v[N];

void dfs(int x, int p)
{
        f[x][0] = p;
        tin[x] = ++tim;
        for(int i = 1; i < 18; i++){
                f[x][i] = f[f[x][i - 1]][i - 1];
        }
        for(auto y: v[x]){
                if(y.fi == p){
                        continue;
                }
                d[y.fi] = d[x] + y.se;
                dfs(y.fi, x);
        }
        tout[x] = tim;
}

bool isp(int x, int y)
{
        return tin[x] <= tin[y] && tout[x] >= tout[y];
}

int lca(int x, int y)
{
        if(isp(x, y)){
                return x;
        } else if(isp(y, x)){
                return y;
        }
        for(int i = 17; i >= 0; i--){
                if(!isp(f[x][i], y)){
                        x = f[x][i];
                }
        }
        return f[x][0];
}

long long res;
void upd(int x, int y, int g)
{
        int p = lca(x, y);
        res += (d[x] + d[y] - 2 * d[p]) * g;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i < n; i++){
                int a, b, c;
                cin >> a >> b >> c;
                v[a].push_back({b, c});
                v[b].push_back({a, c});
        }

        dfs(1, 1);

        set < pair < int, int > > s;
        int q;
        cin >> q;
        for(int i = 1; i <= q; i++){
                char c;
                int x;
                cin >> c;
                if(c == '?'){
                        cout << res / 2 << "\n";
                } else if(c == '+'){
                        cin >> x;
                        if(s.size() == 0){
                                s.insert({tin[x], x});
                                continue;
                        }
                        s.insert({tin[x], x});

                        auto p = s.find({tin[x], x});
                        int l, r;
                        {
                                p++;
                                if(p == s.end()){
                                        l = s.begin()->se;
                                } else{
                                        l = p->se;
                                }
                                p--;
                        }
                        {
                                if(p == s.begin()){
                                        r = (--s.end())->se;
                                } else{
                                        p--;
                                        r = p->se;
                                }
                        }
                        upd(l, r, -1);
                        upd(l, x, 1);
                        upd(r, x, 1);
                } else{
                        cin >> x;
                        if(s.size() == 1){
                                s.erase({tin[x], x});
                                continue;
                        }

                        auto p = s.find({tin[x], x});
                        int l, r;
                        {
                                p++;
                                if(p == s.end()){
                                        l = s.begin()->se;
                                } else{
                                        l = p->se;
                                }
                                p--;
                        }
                        {
                                if(p == s.begin()){
                                        r = (--s.end())->se;
                                } else{
                                        p--;
                                        r = p->se;
                                }
                        }

                        upd(l, r, 1);
                        upd(l, x, -1);
                        upd(r, x, -1);
                        s.erase({tin[x], x});
                }
        }
}