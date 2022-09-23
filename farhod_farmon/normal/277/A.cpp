#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <deque>
#include <queue>
#include <stack>

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
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int a, b, k, ans; 
vector < int > v[101], d[101];
bool used[101], b1;

void dfs( int x )
{
    if( used[x] )return;
    used[x] = true;
    for( int i = 0; i < v[x].size(); i++ )dfs(v[x][i]);
}

int main()
{
    int i, j, x, h;
    cin >> a >> b;
    for( i = 1; i <= a; i++ ){
        cin >> k;
        if(k)b1 = true;
        for( j = 1; j <= k; j++ ){
            cin >> x;
            d[x].pb(i);
        }
    }
    for( i = 1; i <= b; i++ ){
        for( j = 0; j < d[i].size(); j++ ){
            for( h = j + 1; h < d[i].size(); h++ ){
                v[d[i][j]].pb(d[i][h]);
                v[d[i][h]].pb(d[i][j]);
            }
        }
    }
    for( i = 1; i <= a; i++ ){
        if( !used[i] ){
            ans++;
            dfs(i);
        }
    }
    cout << ans - b1 << endl;
}