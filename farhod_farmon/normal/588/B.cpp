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
lli a, i, j, h, x, y, z, maxa;
bool used[1000001];

bool f( lli x )
{
    for( j = 2; (j * j) <= x; j++ ){
        if( x % (j * j) == 0 && used[j] )return false;
    }
    return true;
}

int main()
{
    cin >> a;
    for( i = 2; i * i <= a; i++ )used[i] = true;
    if( f(a) ){
        cout << a << endl;
        return 0;
    }
    for( i = 2; i * i <= a; i++ ){
        if( a % i )continue;
        x = a / i;
        y = i;
        if( x > maxa && f(x) )maxa = x;
        if( y > maxa && f(y) )maxa = y;
    }
    cout << maxa << endl;
}