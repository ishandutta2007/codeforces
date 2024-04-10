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
vector < int > v;
int a, x[1000000], i, j, h;
map < int, int > d;

int main()
{
    cin >> a;
    a *= a;
    for( i = 1; i <= a; i++ ){
        cin >> x[i];
        d[x[i]]++;
    }
    sort( x + 1, x + a + 1 );
    for( i = a; i >= 1; i-- ){
        if( d[x[i]] > 0 ){
            d[x[i]]--;
            for( j = 0; j < v.size(); j++ )d[__gcd(v[j], x[i])] -= 2;
            v.pb(x[i]);
        }
    }
    for( i = 0; i < v.size(); i++ )cout << v[i] << " ";
}