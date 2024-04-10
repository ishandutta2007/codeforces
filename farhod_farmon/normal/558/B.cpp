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
#define fin freopen( "typo.in", "r", stdin );
#define fout freopen( "typo.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int a, i, j, x, d[1000001], l, r;
vector < int > v;
pair < int, int > p[1000001];

int main()
{
    sc( "%d", &a );
    l = 1;
    r = a;
    for( i = 1; i <= a; i++ ){
        sc( "%d", &x );
        d[x]++;
        if( !p[x].fi )p[x].fi = i;
        p[x].se = i;
    }
    v.pb(1);
    for( i = 2; i <= 1000000; i++ ){
        if( d[i] > d[v[0]] ){
            v.clear();
            v.pb(i);
        }
        else if( d[i] == d[v[0]] )v.pb(i);
    }
    for( i = 0; i < v.size(); i++ ){
        if( r - l > p[v[i]].se - p[v[i]].fi ){
            l = p[v[i]].fi;
            r = p[v[i]].se;
        }
    }
    cout << l << " " << r;
}