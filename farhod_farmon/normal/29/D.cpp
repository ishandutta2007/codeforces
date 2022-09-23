#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 333;

using namespace std;

int n;
vector < int > child[N];
vector < int > v[N], nv[N], g, ans;

void dfs(int x, int p)
{
    child[x].pb(x);
    for(int i = 0; i < v[x].size(); i++){
        if(v[x][i] == p)
            continue;
        int y = v[x][i];
        dfs(y, x);
        for(int j = 0; j < child[y].size(); j++)
            child[x].pb(child[y][j]);
    }
}

bool used[N][N];

void ras(int x, int p)
{
    for(int i = 0; i < g.size(); i++){
        for(int j = 0; j < v[x].size(); j++){
            int y = v[x][j];
            if(y == p || used[x][j])
                continue;
            ras(y, x);
            bool b = false;
            for(int h = 0; h < child[y].size(); h++){
                if(child[y][h] == g[i]){
                    b = true;
                    break;
                }
            }
            if(b){
                nv[x].pb(y);
                used[x][j] = true;
                break;
            }
        }
    }
    for(int j = 0; j < v[x].size(); j++)
        if(!used[x][j] && v[x][j] != p)
            nv[x].pb(v[x][j]);
}

int cur = 0;

void trc(int x)
{
    ans.pb(x);
    if(nv[x].size() == 0){
        if(g[cur] != x){
            cout << -1 << endl;
            exit(0);
        }
        cur++;
        return;
    }
    for(int i = 0; i < nv[x].size(); i++){
        trc(nv[x][i]);
        ans.pb(x);
    }
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    int x;
    while(cin >> x)
        g.pb(x);
    dfs(1, -1);
    ras(1, -1);
    trc(1);
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}