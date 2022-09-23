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
#include <iomanip>

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

int n, g = 0, ans;
bool used[1 << 18], can[18][18];
map < string, int > m;
string s, t, gg[18];

void dfs( int x )
{
    if( used[x] )return;
    used[x] = true;
    bool b1[17] = {0};
    int i, j;
    for( i = 0; i < n; i++ ){
        if( !(x & (1 << i)) )continue;
        for( j = 0; j < n; j++ ){
            if( x & (1 << j) )continue;
            b1[j] |= can[i][j];
        }
    }
    for( i = 0; i < n; i++ ){
        if( x & (1 << i) || b1[i] )continue;
        dfs(x | (1 << i));
    }
    if( __builtin_popcount(x) > __builtin_popcount(ans) )ans = x;
}

int main()
{
    int i, j, h, k;
    cin >> n >> k;
    for( i = 1; i <= n; i++ ){
        cin >> s;
        gg[g] = s;
        m[s] = g++;
    }
    for( i = 1; i <= k; i++ ){
        cin >> s >> t;
        can[m[s]][m[t]] = can[m[t]][m[s]] = true;
    }
    dfs(0);
    vector < string > v;
    cout << __builtin_popcount(ans) << endl;
    for( i = 0; i < n; i++ ){
        if( ans & (1 << i) )v.pb(gg[i]);
    }
    sort( v.begin(), v.end() );
    for( i = 0; i < v.size(); i++ )cout << v[i] << endl;
}