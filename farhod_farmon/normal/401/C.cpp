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
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )

using namespace std;

int n, m, i;

void F()
{
    if( m > n - 1 ){
        pr("1");
        m--;
    }
}

int main()
{
    sc( "%d%d", &n, &m );
    if( m < n - 1 || m > (n + 1) * 2 ){
        pr( "-1" );
        return 0;
    }
    F();
    F();
    for( i = 1; i <= n; i++ ){
        pr( "0" );
        if( i < n ){
            pr("1");
            F();
        }
        else{
            F();
            F();
        }
    }
}