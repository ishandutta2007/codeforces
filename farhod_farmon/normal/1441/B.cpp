#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int mod = 998244353;

using namespace std;

void add(int &x, int y)
{
        x += y;
        if(x >= mod){
                x -= mod;
        }
}

int p[N];

struct lol{
        bool operator() (const pair < pair < int, int >, pair < int, int > > &A, const pair < pair < int, int >, pair < int, int > > &B) const{
                if(max(A.fi.fi, B.fi.fi) > 26){
                        return A < B;
                }
                return make_pair(p[A.fi.fi] + A.fi.se, A.se) < make_pair(p[B.fi.fi] + B.fi.se, B.se);
        }
};

bool les(pair < int, int > A, pair < int, int >B){
        if(max(A.fi, B.fi) > 26){
                return A < B;
        }
        return p[A.fi] + A.se < p[B.fi] + B.se;
}

int n, m;
int f[N][28][2];
pair < int, int > d[N][2];
vector < pair < int, int > > v[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        p[0] = 1;
        for(int i = 1; i < N; i++){
                p[i] = p[i - 1];
                add(p[i], p[i]);
        }

        cin >> n >> m;
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back({y, 0});
                v[y].push_back({x, 1});
        }

        for(int i = 1; i <= n; i++){
                for(int j = 0; j < 28; j++){
                        f[i][j][0] = f[i][j][1] = 1e9;
                }
        }
        f[1][0][0] = 0;
        queue < pair < int, int > > q;
        q.push({1, 0});
        while(!q.empty()){
                int x = q.front().fi;
                int j = q.front().se / 2;
                int h = q.front().se % 2;
                q.pop();
                if(j == 27){
                        continue;
                }
                for(auto y: v[x]){
                        int g = y.se ^ h;
                        if(f[x][j][h] + 1 < f[y.fi][j + g][y.se]){
                                f[y.fi][j + g][y.se] = f[x][j][h] + 1;
                                q.push({y.fi, (j + g) * 2 + y.se});
                        }
                }
        }
        int inf = 1e9;

        set < pair < pair < int, int >, pair < int, int > >, lol > S;
        for(int i = 1; i <= n; i++){
                d[i][0] = d[i][1] = {1e9, 1e9};
                for(int j = 0; j < 27; j++){
                        for(int h = 0; h < 2; h++){
                                if(f[i][j][h] == inf){
                                        continue;
                                }
                                if(les(make_pair(j, f[i][j][h]), d[i][h])){
                                        d[i][h] = make_pair(j, f[i][j][h]);
                                }
                        }
                }
                S.insert({d[i][0], {i, 0}});
                S.insert({d[i][1], {i, 1}});
                //cout << d[i][0].fi << " " << d[i][1].fi << "\n";
        }


        while(!S.empty()){
                auto x = S.begin()->se;
                S.erase(S.begin());
                for(auto y: v[x.fi]){
                        int g = y.se ^ x.se;
                        auto cost = d[x.fi][x.se];
                        cost.se += 1;
                        cost.fi += g;
                        if(les(cost, d[y.fi][y.se])){
                                S.erase({d[y.fi][y.se], y});
                                d[y.fi][y.se] = cost;
                                S.insert({d[y.fi][y.se], y});
                        }
                }
        }
        S.insert({d[n][0], {0, 0}});
        S.insert({d[n][1], {0, 0}});
        auto shit = S.begin()->fi;
        int res = shit.se;
        add(res, p[shit.fi]);
        res -= 1;
        if(res < 0){
                res += mod;
        }
        cout << res << "\n";
}