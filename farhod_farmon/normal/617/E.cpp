#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

using namespace std;

int n, m, k;
int l, r;
lli cnt;
int pre[100001];
int d[5000001];
lli ans[1000001];
pair < pair < int, int >, int > p[1000001];

bool cmp( pair < pair < int, int >, int > x, pair < pair < int, int >, int > y )
{
    if( x.fi.fi / 333 == y.fi.fi / 333 )
        return x.fi.se < y.fi.se;
    return x.fi.fi / 333 < y.fi.fi / 333;
}

void add( int x )
{
    cnt += d[x ^ k];
    d[x]++;
}

void sub( int x )
{
    d[x]--;
    cnt -= d[x ^ k];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    for( int i = 1; i <= n; i++ ){
        cin >> pre[i];
        pre[i] ^= pre[i - 1];
    }
    for( int i = 1; i <= m; i++ ){
        cin >> p[i].fi.fi >> p[i].fi.se;
        p[i].fi.fi--;
        p[i].se = i;
    }
    sort( p + 1, p + m + 1, cmp );
    d[0] = 1;
    for( int i = 1; i <= m; i++ ){
        int j = p[i].fi.fi, h = p[i].fi.se;
        while( l < j )
            sub(pre[l++]);
        while( l > j )
            add(pre[--l]);
        while( r < h )
            add(pre[++r]);
        while( r > h )
            sub(pre[r--]);
        ans[p[i].se] = cnt;
    }
    for( int i = 1; i <= m; i++ )
        cout << ans[i] << endl;
}