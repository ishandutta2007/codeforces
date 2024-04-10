#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 20020;

using namespace std;

int n;
int m;
vector < vector < char > > a;
vector < vector < char > > b;
vector < vector < int > > us;
vector < vector < int > > used;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int op(char c)
{
        if(c == 'R'){
                return 2;
        } else if(c == 'L'){
                return 3;
        } else if(c == 'U'){
                return 1;
        } else{
                return 0;
        }
}

pair < int, int > solve(int x, int y)
{
        int L = 0;
        queue < pair < int, int > > qu;
        while(!us[x][y]){
                L += 1;
                us[x][y] = L;
                qu.push({x, y});
                int i = op(b[x][y]);
                x += dx[i];
                y += dy[i];
        }
        vector < int > bb(L + 1, 0);
        while(!qu.empty()){
                auto x = qu.front();
                qu.pop();
                used[x.fi][x.se] = true;
                bb[us[x.fi][x.se]] |= a[x.fi][x.se] - '0';
                for(int i = 0; i < 4; i++){
                        auto y = x;
                        y.fi -= dx[i];
                        y.se -= dy[i];
                        if(y.fi >= 0 && y.fi < n && y.se >= 0 && y.se < m && !us[y.fi][y.se]){
                                if(op(b[y.fi][y.se]) == i){
                                        us[y.fi][y.se] = us[x.fi][x.se] - 1;
                                        if(us[y.fi][y.se] == 0){
                                                us[y.fi][y.se] = L;
                                        }
                                        qu.push(y);
                                }
                        }
                }
        }
        int res = 0;
        for(int i = 1; i <= L; i++){
                res += bb[i];
        }
        return make_pair(L, res);
}

void solve()
{
        cin >> n >> m;
        a.resize(n);
        b.resize(n);
        us.resize(n);
        used.resize(n);
        for(int i = 0; i < n; i++){
                a[i].resize(m);
                b[i].resize(m);
                us[i].resize(m);
                used[i].resize(m);
                for(int j = 0; j < m; j++){
                        used[i][j] = us[i][j] = 0;
                }
        }

        for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                        cin >> a[i][j];
                        if(a[i][j] == '1'){
                                a[i][j] = '0';
                        } else{
                                a[i][j] = '1';
                        }
                }
        }
        for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                        cin >> b[i][j];
                }
        }
        pair < int, int > res = {0, 0};
        for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                        if(used[i][j]){
                                continue;
                        }
                        int x = i, y = j;
                        while(!used[x][y]){
                                used[x][y] = true;
                                int i = op(b[x][y]);
                                x += dx[i];
                                y += dy[i];
                        }
                        auto cur = solve(x, y);
                        res.fi += cur.fi;
                        res.se += cur.se;
                }
        }

        cout << res.fi << " " << res.se << "\n";
}

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int T;
        cin >> T;
        while(T--){
                solve();
        }
}