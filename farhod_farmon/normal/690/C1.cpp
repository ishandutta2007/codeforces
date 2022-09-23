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

using namespace std;

vector < int > v[1001];
bool used[1001];
int n, m;

void dfs(int x)
{
    if(used[x])
        return;
    used[x] = true;
    for(int i = 0; i < v[x].size(); i++)
        dfs(v[x][i]);
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
    dfs(1);
    if(m != n - 1){
        cout << "no" << endl;
        return 0;
    }
    for(int i = 1; i <= n; i++){
        if(!used[i]){
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
    return 0;
}