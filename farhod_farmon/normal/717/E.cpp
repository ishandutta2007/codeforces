#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 200200;

using namespace std;

vector < int > ans, v[N];
int n, a[N];

void dfs(int x, int p)
{
    ans.pb(x);
    a[x] = -a[x];
    for(int i = 0; i < v[x].size(); i++){
        int y = v[x][i];
        if(y == p)
            continue;
        dfs(y, x);
        if(a[y] == -1){
            ans.pb(y);
            ans.pb(x);
            a[y] = -a[y];
            a[x] = -a[x];
        }
    }
    if(p)
        ans.pb(p);
    a[p] = -a[p];
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    bool l = true;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] == -1)
            l = false;
    }
    for(int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    if(l){
        cout << 1;
        return 0;
    }
    dfs(1, 0);
    if(a[1] == 1){
        ans.pb(v[1][0]);
        ans.pb(1);
        ans.pb(v[1][0]);
    }
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}