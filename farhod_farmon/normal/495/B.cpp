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
#define fin freopen( "birthday.in", "r", stdin );
#define fout freopen( "birthday.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int a, b, i, j, cnt, x;

int main()
{
    cin >> a >> b;
    x = a - b;
    if( x < 0 )cout << 0 << endl;
    else if( x == 0 )cout << "infinity" << endl;
    else{
        for( i = 1; i * i <= x; i++ ){
            if( x % i )continue;
            j = x / i;
            if( a % i == b )cnt++;
            if( a % j == b && i != j )cnt++;
        }
        cout << cnt << endl;
    }
}