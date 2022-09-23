#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 3030;

using namespace std;

int n;
vector < int > v[N], cycle;
int used[N];
int P[N];
int ans[N];

void dfs(int x, int p)
{
    if(used[x] == 2)
        return;
    if(used[x] == 1){
        while(p != P[x]){
            cycle.pb(p);
            p = P[p];
        }
        return;
    }
    used[x] = 1;
    P[x] = p;
    for(int i = 0; i < v[x].size(); i++)
        if(v[x][i] != p)
            dfs(v[x][i], x);
    used[x] = 2;
}

void upd(int x, int p, int g)
{
    if(ans[x] <= g)
        return;
    ans[x] = g;
    for(int i = 0; i < v[x].size(); i++)
        if(v[x][i] != p)
            upd(v[x][i], x, g + 1);
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
        ans[i] = 1e7;
    }
    for(int i = 1; i <= n; i++)
        if(used[i] == 0)
            dfs(i, -1);
    for(int i = 0; i < cycle.size(); i++){
        upd(cycle[i], -1, 0);
    }
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
}