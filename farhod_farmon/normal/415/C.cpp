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
int a, b, i, x = 0, y = 999999998;

int main()
{
    cin >> a >> b;
    if( a % 2 ){
        x = y + 1;
        a--;
    }
    if( b < a / 2 || !a && b )cout << -1;
    else{
        for( i = 1; i < a / 2; i++, y -= 2 )cout << y << ' ' << y - 1 << " ";
        b -= (a / 2) - 1;
        if( a )cout << b << " " << b * 2;
        if( x )cout << " " << x;
    }
}