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
pair < int, int > ps[100001], pb[100001];
int a, s, p[1001], q[1001], i, j, h, k, l, r, m;
char c[1001];
vector < int  > v, v1;

int main()
{
    cin >> a >> s;
    for( i = 1; i <= a; i++ ){
        cin >> c[i] >> p[i] >> q[i];
        if( c[i] == 'B' ){
            pb[p[i]].fi += q[i];
            if( !pb[p[i]].se )pb[p[i]].se = i;
        }
        else {
            ps[p[i]].fi += q[i];
            if( !ps[p[i]].se )ps[p[i]].se = i;
        }
    }
    for( i = 0; i <= 100000; i++ ){
        if( ps[i].se ){
            if( l == s )break;
            l++;
            v.pb( ps[i].se );
        }
    }
    for( i = 100000; i >= 0; i-- ){
        if( pb[i].se ){
            if( r == s )break;
            r++;
            v1.pb( pb[i].se );
        }
    }
    for( i = v.size() - 1; i >= 0; i-- )cout << c[v[i]] << " " << p[v[i]] << " " << ps[p[v[i]]].fi << endl;
    for( i = 0; i < v1.size(); i++ )cout << c[v1[i]] << " " << p[v1[i]] << " " << pb[p[v1[i]]].fi << endl;
}