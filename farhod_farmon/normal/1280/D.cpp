#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 3030;
const int mod = 1e9 + 7;

using namespace std;

int n;
int k;
int a[N];
int s[N];
vector < int > v[N];
pair < int, long long > d[N][N], f[N];

pair < int, long long > K = {-1e9, -1e18};

void dfs(int x, int p)
{
        s[x] = 1;
        d[x][1] = {0, a[x]};
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                dfs(y, x);
                int s1 = s[x], s2 = s[y];
                for(int i = 1; i <= s1 + s2; i++){
                        f[i] = K;
                }
                pair < int, long long > sh;
                for(int i = 1; i <= s1; i++){
                        sh = d[x][i];
                        for(int j = 1; j <= s2; j++){
                                f[i + j - 1] = max(f[i + j - 1], make_pair(sh.fi + d[y][j].fi, sh.se + d[y][j].se));
                                f[i + j] = max(f[i + j], make_pair(sh.fi + d[y][j].fi + (d[y][j].se > 0), sh.se));
                        }
                }

                s[x] += s[y];
                for(int i = s1 + s2; i >= 1; i--){
                        d[x][i] = f[i];
                }
        }
}

void solve()
{
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                a[i] = x - a[i];
        }

        for(int i = 1; i <= n; i++){
                for(int j = 0; j <= n + 1; j++){
                        d[i][j] = K;
                }
                s[i] = 0;
                v[i].clear();
        }
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }

        dfs(1, 1);

        int res = d[1][k].fi;
        if(d[1][k].se > 0){
                res += 1;
        }

        cout << res << "\n";
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                solve();
        }
}