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

int n, a[1001], ans, i, j, x;
map < int, int > m;
map < pair < int, int >, bool > used;
vector < int > v;

int main()
{
    sc( "%d", &n );
    for( i = 1; i <= n; i++ ){
        sc( "%d", &a[i] );
        m[a[i]]++;
    }
    for( i = 1; i <= n; i++ ){
        for( j = 1; j <= n; j++ ){
            if( i == j )continue;
            if( used[mp(a[i], a[j])] )continue;
            used[mp(a[i], a[j])] = true;
            m[a[i]]--; m[a[j]]--;
            v.pb(a[i]); v.pb(a[j]);
            x = a[i] + a[j];
            while( m[x] ){
                m[x]--;
                v.pb(x);
                x += v[v.size() - 2];
            }
            ans = max(ans, (int)v.size());
            while( !v.empty() ){
                m[v.back()]++;
                v.p_b();
            }
        }
    }
    cout << ans << endl;
}