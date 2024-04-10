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

const int N = 1e5 + 5;

using namespace std;

int n;
long long ans, t[4 * N];
long double pi = acos(-1);
pair < long long, int > p[N];

void M( int x, int l, int r, int g, long long y )
{
    if( l == r ){
        t[x] = y;
        return;
    }
    int m = (l + r) / 2;
    if( g <= m )M(x * 2, l, m, g, y);
    else M(x * 2 + 1, m + 1, r, g, y);
    t[x] = max(t[x * 2], t[x * 2 + 1]);
}

long long get( int x, int l, int r, int tl, int tr )
{
    if( tl > tr )return 0;
    if( tl == l && tr == r )return t[x];
    int m = (l + r) / 2;
    return max(get(x * 2, l, m, tl, min(tr, m)), get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr));
}

int main()
{
    int i, j;
    long long r, h;
    cin >> n;
    for( i = 1; i <= n; i++ ){
        cin >> r >> h;
        p[i] = mp(r * 1ll * r * 1ll * h, -i);
    }
    sort( p + 1, p + n + 1 );
    for( i = 1; i <= n; i++ ) M(1, 1, n, -p[i].se, get(1, 1, n, 1, -p[i].se) + p[i].fi);
    cout << fixed << setprecision(9) << pi * get(1, 1, n, 1, n) << endl;
}