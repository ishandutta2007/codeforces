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

const int N = 200002;

using namespace std;

vector < pair < int, int > > v[N];
vector < int > ans[N];
int n;

void dfs( int x, int p, int pd )
{
    int day = 0;
    for( int i = 0; i < v[x].size(); i++ ){
        int to = v[x][i].fi;
        int l = v[x][i].se;
        if( to == p )
            continue;
        day++;
        if( day == pd )
            day++;
        ans[day].pb(l);
        dfs(to, x, day);
    }
}

int main()
{
    int i, x, y, h = 0;
    cin >> n;
    for( i = 1; i < n; i++ ){
        cin >> x >> y;
        v[x].pb(mp(y, i));
        v[y].pb(mp(x, i));
    }
    for( i = 1; i <= n; i++ )
        h = max(h, (int)v[i].size());
    dfs(1, -1, -1);
    cout << h << endl;
    for( i = 1; i <= h; i++ ){
        cout << ans[i].size() << " ";
        for( int j = 0; j < ans[i].size(); j++ )
            cout << ans[i][j] << " ";
        cout << endl;
    }
}