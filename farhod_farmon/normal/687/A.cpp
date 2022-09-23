#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

const int N = 100100;

using namespace std;

vector < int > v[N], a, b;
int n, m, used[N];

void dfs(int x, int g)
{
    if(used[x]){
        if(used[x] != g){
            cout << -1 << endl;
            exit(0);
        }
        return;
    }
    used[x] = g;
    if(g == 1)
        a.pb(x);
    else
        b.pb(x);
    for(int i = 0; i < v[x].size(); i++)
        dfs(v[x][i], 3 - g);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    for(int i = 1; i <= n; i++)
        if(!used[i])
            dfs(i, 1);
    cout << a.size() << endl;
    for(int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << endl << b.size() << endl;
    for(int i = 0; i < b.size(); i++)
        cout << b[i] << " ";
}