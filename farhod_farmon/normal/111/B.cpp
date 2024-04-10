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

set < pair < int, int > > s;
set < pair < int, int > > :: iterator it;
int n, i, j, h, x, y, cnt;

int main()
{
    s.insert(mp(1e9, 1e9));
    sc( "%d", &n );
    for( i = 1; i <= n; i++ ){
        sc( "%d%d", &x, &y );
        cnt = 0;
        for( j = 1; j * j < x; j++ ){
            if( x % j )continue;
            h = x / j;
            it = s.lower_bound(mp(j, i - y));
            if( it->fi != j )cnt++;
            it = s.lower_bound(mp(h, i - y));
            if( it->fi != h )cnt++;
            s.insert(mp(j, i));
            s.insert(mp(h, i));
        }
        if( j * j == x ){
            it = s.lower_bound(mp(j, i - y));
            if( it->fi != j )cnt++;
            s.insert(mp(j, i));
        }
        pr( "%d\n", cnt );
    }
}