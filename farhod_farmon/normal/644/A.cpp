#include <bits/stdc++.h>

#define lli long long int
#define sc scanf
#define pr printf
#define pb push_back
#define p_b pop_back
#define mp make_pair
#define fi first
#define se second
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

using namespace std;

int n, a, b, x, y, d[101][101], i, j, h;
vector < pair < int, int > > v[2];
int main()
{
    cin >> n >> a >> b;
    for( i = 1; i <= a; i++ ){
        for( j = 1; j <= b; j++ ){
            v[(i + j) % 2].pb(mp(i, j));
        }
    }
    x = (n + 1) / 2;
    y = n / 2;
    if( (int)v[0].size() < (int)v[1].size() )swap(v[0], v[1]);
    if( (int)v[0].size() < x || (int)v[1].size() < y ){
        cout << -1 << endl;
        return 0;
    }
    for( i = 0; i < x; i++ )d[v[0][i].fi][v[0][i].se] = i * 2 + 1;
    for( i = 0; i < y; i++ )d[v[1][i].fi][v[1][i].se] = i * 2 + 2;
    for( i = 1; i <= a; i++ ){
        for( j = 1; j <= b; j++ ){
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
}