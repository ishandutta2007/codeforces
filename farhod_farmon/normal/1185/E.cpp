#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 2020;

using namespace std;

int n;
int m;
char c[N][N];
pair < int, int > a[27];
pair < int, int > b[27];
vector < pair < int, int > > v[27];

void solve()
{
        scanf("%d %d\n", &n, &m);
        for(int i = 0; i < 26; i++){
                a[i].fi = a[i].se = N;
                b[i].fi = b[i].se = 0;
                v[i].clear();
        }
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        scanf("%c", &c[i][j]);
                        if(c[i][j] != '.'){
                                int x = c[i][j] - 'a';
                                a[x].fi = min(a[x].fi, i);
                                a[x].se = min(a[x].se, j);
                                b[x].fi = max(b[x].fi, i);
                                b[x].se = max(b[x].se, j);
                        }
                }
                scanf("\n");
        }
        int last = -1;
        for(int i = 0; i < 26; i++){
                if(a[i].fi == N){
                        continue;
                }
                last = i;
                if(a[i].fi < b[i].fi && a[i].se < b[i].se){
                        printf("NO\n");
                        return;
                }
                for(int j = a[i].fi; j <= b[i].fi; j++){
                        for(int h = a[i].se; h <= b[i].se; h++){
                                v[i].push_back({j, h});
                        }
                }
        }

        bool good = true;
        vector < pair < pair < int, int >, pair < int, int > > > res;
        for(int i = last; i >= 0; i--){
                if(v[i].empty()){
                        for(int h = 1; h <= n && v[i].empty(); h++){
                                for(int j = 1; j <= m; j++){
                                        if(c[h][j] == '#'){
                                                v[i].push_back({h, j});
                                                a[i] = b[i] = {h, j};
                                                break;
                                        }
                                }
                        }
                }
                bool can = true;
                if(v[i].empty()){
                        can = false;
                }
                for(auto p: v[i]){
                        if(c[p.fi][p.se] != '#' && c[p.fi][p.se] != 'a' + i){
                                can = false;
                        }
                }
                if(!can){
                        good = false;
                        break;
                }
                good = true;
                res.push_back({a[i], b[i]});
                for(auto p: v[i]){
                        c[p.fi][p.se] = '#';
                }
        }
        if(good == false){
                printf("NO\n");
                return;
        }
        printf("YES\n%d\n", res.size());
        reverse(res.begin(), res.end());
        for(auto p: res){
                printf("%d %d %d %d\n", p.fi.fi, p.fi.se, p.se.fi, p.se.se);
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int T;
        scanf("%d\n", &T);
        while(T--) {
                solve();
        }
}