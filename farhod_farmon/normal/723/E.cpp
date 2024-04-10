#include <bits/stdc++.h>
#include <windows.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 202;

using namespace std;

vector < int > v[N];
int n, m;
bool used[N][N];

void dfs(int x)
{
    for(auto y: v[x]){
        if(used[x][y] || used[y][x])
            continue;
        used[x][y] = true;
        dfs(y);
    }
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1; i <= n + 1; i++){
            v[i].clear();
            for(int j = 1; j <= n + 1; j++)
                used[i][j] = false;
        }
        int x[N * N], y[N * N];
        for(int i = 1; i <= m; i++){
            cin >> x[i] >> y[i];
            v[x[i]].pb(y[i]);
            v[y[i]].pb(x[i]);
        }
        int cnt = n;
        for(int i = 1; i <= n; i++){
            if(v[i].size() % 2){
                v[i].pb(n + 1);
                v[n + 1].pb(i);
                cnt--;
            }
        }
        for(int i = 1; i <= n; i++)
            dfs(i);
        cout << cnt << endl;
        for(int i = 1; i <= m; i++){
            if(used[x[i]][y[i]])
                cout << x[i] << " " << y[i] << endl;
            else
                cout << y[i] << " " << x[i] << endl;
        }
    }
}