#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 5050;

using namespace std;

int d[N][N], p[N][N];
int n, m, T;
vector < pair < int, int > > v[N];
vector < int > order;
bool used[N];

void dfs(int x)
{
    if(used[x])
        return;
    used[x] = true;
    for(int i = 0; i < v[x].size(); i++)
        dfs(v[x][i].fi);
    order.pb(x);
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> T;
    for(int i = 1; i <= m; i++){
        int x, y, l;
        cin >> x >> y >> l;
        v[x].pb({y, l});
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            d[i][j] = 1e9 + 1;
    d[1][1] = 0;
    dfs(1);
    reverse(order.begin(), order.end());
    for(int i = 0; i < order.size(); i++){
        int x = order[i];
        for(int j = 1; j <= n; j++){
            if(d[x][j] == 1e9 + 1)
                continue;
            for(int h = 0; h < v[x].size(); h++){
                int y = v[x][h].fi,
                    l = v[x][h].se;
                if(d[x][j] + l < d[y][j + 1]){
                    d[y][j + 1] = d[x][j] + l;
                    p[y][j + 1] = x;
                }
            }
        }
    }
    int h;
    for(int i = n; i >= 1; i--){
        if(d[n][i] <= T){
            h = i;
            break;
        }
    }
    vector < int > ans;
    for(int i = h; i >= 1; i--){
        ans.pb(n);
        n = p[n][i];
    }
    cout << ans.size() << endl;
    for(int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << " ";
}