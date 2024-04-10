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
#define fin freopen( "cipher.in", "r", stdin );
#define fout freopen( "cipher.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int n, m, i, j, h, x;
bool used[1001], used1[1001];

int main()
{
    sc( "%d%d", &n, &m );
    if( n >= m ){
        cout << "YES";
        return 0;
    }
    for( i = 1; i <= n; i++ ){
        sc( "%d", &x );
        used[x % m] = true;
        for( j = 0; j < m; j++ ){
            if( used1[j] )used[(j + x) % m] = used[j] = true;
        }
        for( j = 0; j < m; j++ ){
            used1[j] = used[j];
            used[j] = false;
        }
    }
    if( used1[0] )cout << "YES";
    else cout << "NO";
}