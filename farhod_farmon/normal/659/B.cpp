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

int n, m, i, j, h, x;
string s;
vector < pair < int, string > > v[10001];

int main()
{
    cin >> n >> m;
    for( i = 1; i <= n; i++ ){
        cin >> s >> h >> x;
        v[h].pb(mp(x, s));
    }
    for( i = 1; i <= m; i++ ){
        sort( v[i].begin(), v[i].end() );
        if( v[i].size() > 2 && v[i][v[i].size() - 2].fi == v[i][v[i].size() - 3].fi )
            cout << "?" << endl;
        else
            cout << v[i][v[i].size() - 1].se << " " << v[i][v[i].size() - 2].se << endl;
    }
}