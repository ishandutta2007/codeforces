#include <bits/stdc++.h>

#define lli long long int
#define sc scanf
#define pr printf
#define pb push_back
#define p_b pop_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

int n, m, s, d;
vector < int > v;
vector < pair < string, int > > ans;

int main()
{
    v.pb(0);
    sc( "%d%d%d%d", &n, &m, &s, &d );
    for( int i = 1; i <= n; i++ ){
        int a;
        sc( "%d", &a );
        v.pb(a + 1);
    }
    sort( v.begin(), v.end() );
    if( d == 1 ){
        pr( "IMPOSSIBLE\n" );
        return 0;
    }
    if( v[1] - v[0] - 2 < s ){
        pr( "IMPOSSIBLE\n" );
        return 0;
    }
    for( int i = 0; i < n; i++ ){
        int g = v[i + 1] - 2;
        ans.pb(mp("RUN", g - v[i]));
        int j = i + 1;
        while( j < n && v[j + 1] - v[j] - 2 < s )j++;
        if( v[j] - g > d ){
            pr( "IMPOSSIBLE\n" );
            return 0;
        }
        ans.pb(mp("JUMP", v[j] - g));
        i = j - 1;
    }
    if( v[n] != m )ans.pb(mp("RUN", m - v[n]));
    for( int i = 0; i < ans.size(); i++ ){
        int g = ans[i].se;
        if( ans[i].fi == "RUN" )pr( "RUN " );
        else pr( "JUMP " );
        pr( "%d\n", g );
    }
}