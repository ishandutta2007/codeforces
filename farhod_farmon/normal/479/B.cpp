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

#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define p_b pop_back
#define pf push_front
#define p_f pop_front
#define mp make_pair
#define lli long long int
#define p_q priority_queue
#define fin freopen( "milk.in", "r", stdin );
#define fout freopen( "input.txt", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int a, k, i, j;
vector < int > x, y;
pair < int, int > p[1001];
int main ()
{
    cin >> a >> k;
    for( i = 1; i <= a; i++ ){
        cin >> p[i].fi;
        p[i].se = i;
    }
    sort( p + 1, p + a + 1 );
    while( k && p[a].fi > p[1].fi ){
        k--;
        x.pb(p[a].se);
        y.pb(p[1].se);
        p[a].fi--;
        p[1].fi++;
        sort( p + 1, p + a + 1 );
    }
    cout << p[a].fi - p[1].fi << " " << x.size() << endl;
    for( i = 0; i < x.size(); i++ )cout << x[i] << " " << y[i] << endl;
}