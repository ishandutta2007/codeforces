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
#define fin freopen( "shield.in", "r", stdin );
#define fout freopen( "shield.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
lli a, b, i, g, cnt;

int main()
{
    cin >> a;
    for( i = 1; i <= a; i++ ){
        cin >> b;
        cnt = b * (b + 1) / 2;
        g = 1;
        while( g <= b ){
            cnt -= 2 * g;
            g *= 2;
        }
        cout << cnt << endl;
    }    
}