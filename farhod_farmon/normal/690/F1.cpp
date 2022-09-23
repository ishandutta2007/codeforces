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

const int N = 10001;

using namespace std;

vector < int > v[N];
int n, ans;

void dfs(int x, int p)
{
    if(p != -1)
        ans += v[p].size() - 1;
    for(int i = 0; i < v[x].size(); i++)
        if(v[x][i] != p)
            dfs(v[x][i], x);
    if(p != -1)
        ans -= (v[x].size() - 1) * (v[x].size() - 2) / 2;
    else
        ans -= (v[x].size() - 1) * (v[x].size()) / 2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1, -1);
    cout << ans << endl;
}