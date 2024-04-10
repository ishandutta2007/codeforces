#include <bits/stdc++.h>

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

lli n, b, i, t, d;
vector < lli > tim;

int main()
{
    sc( "%I64d%I64d", &n, &b );
    for( i = 1; i <= b + 1; i++ ){
        tim.pb(0ll);
    }
    for( i = 1; i <= n; i++ ){
        sc( "%I64d%I64d", &t, &d );
        lli endt = tim[tim.size() - b - 1];
        if( endt > t ){
            pr( "-1 " );
            continue;
        }
        tim.pb(max(tim.back(), t) + d);
        pr( "%I64d ", tim.back() );
    }
}