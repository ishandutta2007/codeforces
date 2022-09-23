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

lli x, y, i, j, h = 2, ans;
vector < lli > v;

int main()
{
    cin >> x >> y;
    while( h <= y ){
        h *= 2;
        v.pb(h - 1);
    }
    for( i = 0; i < v.size(); i++ ){
        for( j = 1; j * 2 < v[i]; j *= 2 ){
            if( x <= v[i] - j && v[i] - j <= y )ans++;
        }
    }
    cout << ans;
}