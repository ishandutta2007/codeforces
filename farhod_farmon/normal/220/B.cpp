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
#define fin freopen( "msched.in", "r", stdin );
#define fout freopen( "msched.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int a, b, i, j, h, c[100011], d[100011], l, r, dp[100001][500];
vector < int > v;

int main()
{
    sc("%d%d", &a, &b);
    for( i = 1; i <= a; i++ ){
        sc("%d", &c[i]);
        d[i] = c[i];
    }
    sort( c + 1, c + a + 1 );
    for( i = 1; i <= a; i++ ){
        int cnt = 1;
        while( c[i] == c[i + cnt] )cnt++;
        if( cnt >= c[i] )v.pb(c[i]);
        i = i + cnt - 1;
    }
    for( i = 1; i <= a; i++ ){
        for( j = 0; j < v.size(); j++ ){
            if( v[j] == d[i] )dp[i][j] = dp[i - 1][j] + 1;
            else dp[i][j] = dp[i - 1][j];
        }
    }
    for( i = 1; i <= b; i++ ){
        sc("%d%d", &l, &r);
        int cnt = 0;
        for( j = 0; j < v.size(); j++ ){
            if( dp[r][j] - dp[l - 1][j] == v[j] )cnt++;
        }
        pr("%d\n", cnt);
    }
}