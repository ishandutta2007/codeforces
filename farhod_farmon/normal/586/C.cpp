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
lli a, v[4001], d[4001], p[4001];
bool used[4001];
vector < lli > ans;

void f( lli x )
{
    if( used[x] )return;
    used[x] = true;
    lli i, j, h;
    for( i = x; i <= a; i++ )p[i] -= d[x];
    for( i = x; i <= a; i++ ){
        if( p[i] < 0 )f(i);
    }
}

int main()
{
    lli i, j, h;
    cin >> a;
    for( i = 1; i <= a; i++ ){
        cin >> v[i] >> d[i] >> p[i];
    }
    for( i = 1; i <= a; i++ ){
        if( used[i] )continue;
        ans.pb(i);
        for( j = i + 1; j <= a && v[i]; j++ ){
            if( used[j] )continue;
            p[j] -= v[i];
            v[i] -= 1;
        }
        for( j = i + 1; j <= a; j++ ){
            if( p[j] < 0 )f(j);
        }
    }
    cout << ans.size() << endl;
    for( i = 0; i < ans.size(); i++ )cout << ans[i] << " ";
}