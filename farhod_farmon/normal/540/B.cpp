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
#define fin freopen( "INPUT.TXT", "r", stdin );
#define fout freopen( "OUTPUT.TXT", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
#define INF 1000000000000000000ll
using namespace std;
int main()
{
    vector <int> v;
    int a, b, i, j, h, l, r, c[2000], d[2000], x, y, k, cnt = 0;
    cin >> a >> b >> k >> x >> y;
    l = a / 2;
    r = a - l;
    for( i = 1; i <= b; i++ ){
        cin >> c[i];
        if( c[i] < y )l--;
        else r--;
        cnt += c[i];
    }
    if( r < 0 )l += r;
    for( i = 1; i <= max(0, l); i++ )v.pb(1),cnt++;
    for( i = 1; i <= max(0, r); i++ )v.pb(k),cnt+=k;
    for( i = v.size() - 1; i >= 0; i-- ){
        while( v[i] > y && cnt > x )v[i]--,cnt--;
        while( v[i] < k && cnt < x )v[i]++,cnt++;
        d[i] = v[i];
    }
    j = v.size() - 1;
    for( i = 1; i <= b; i++ )v.pb(c[i]);
    sort( v.begin(), v.end() );
    if( l < 0 || v[v.size() / 2] < y || cnt > x )cout << -1;
    else{
        for( i = 0; i <= j; i++ )cout << d[i] << " ";
    }
}