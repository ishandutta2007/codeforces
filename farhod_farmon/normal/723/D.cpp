#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 55;

using namespace std;

int n, m, k;
char c[N][N];
bool used[N][N];
bool oz;
int sz;
vector < pair < int, pair < int, int > > > v;

void dfs(int x, int y)
{
    if(x < 1 || y < 1 || x > n || y > m){
        oz = false;
        return;
    }
    if(used[x][y] || c[x][y] == '*')
        return;
    used[x][y] = true;
    sz++;
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}

void upd(int x, int y)
{
    if(c[x][y] == '*')
        return;
    c[x][y] = '*';
    upd(x + 1, y);
    upd(x - 1, y);
    upd(x, y + 1);
    upd(x, y - 1);
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> c[i][j];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(used[i][j] || c[i][j] == '*')
                continue;
            oz = true;
            sz = 0;
            dfs(i, j);
            if(oz)
                v.pb({sz, {i, j}});
        }
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    for(int i = v.size(); i > k; i--){
        cnt += v[v.size() - i].fi;
        upd(v[v.size() - i].se.fi, v[v.size() - i].se.se);
    }
    cout << cnt << endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            cout << c[i][j];
        cout << endl;
    }
}