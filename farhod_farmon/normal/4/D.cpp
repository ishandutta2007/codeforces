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

using namespace std;

int n, a, b, d[5005], pre[5005], ans;
pair < pair < int, int >, int > p[5005];
vector < int > v;

bool istrue( int x, int y, int x1, int y1 )
{
    return x < x1 && y < y1;
}

int main()
{
    int i, j, h;
    cin >> n >> a >> b;
    for( i = 1; i <= n; i++ ){
        cin >> p[i].fi.fi >> p[i].fi.se;
        p[i].se = i;
    }
    sort( p + 1, p + n + 1 );
    for( i = n; i >= 1; i-- ){
        d[i] = 1;
        pre[i] = i;
        for( j = i + 1; j <= n; j++ ){
            if( istrue(p[i].fi.fi, p[i].fi.se, p[j].fi.fi, p[j].fi.se) ){
                if( d[j] + 1 > d[i] ){
                    d[i] = d[j] + 1;
                    pre[i] = j;
                }
            }
        }
    }
    ans = 0;
    for( i = 1; i <= n; i++ ){
        if( d[i] > d[ans] && istrue(a, b, p[i].fi.fi, p[i].fi.se) )ans = i;
    }
    while( ans != pre[ans] ){
        v.pb(p[ans].se);
        ans = pre[ans];
    }
    if( ans )v.pb(p[ans].se);
    cout << v.size() << endl;
    for( i = 0; i < v.size(); i++ )cout << v[i] << " ";
}