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

const int N = 200200;

using namespace std;

int n, m, a, b[N], c[N], cnt1, cnt2, i, h;
map < int, int > used;

int main()
{
    sc( "%d", &n );
    for( i = 1; i <= n; i++ ){
        sc( "%d", &a );
        used[a]++;
    }
    sc( "%d", &m );
    for( i = 1; i <= m; i++ )
        sc( "%d", &b[i] );
    for( i = 1; i <= m; i++ )
        sc( "%d", &c[i] );
    h = 1;
    cnt1 = used[b[1]];
    cnt2 = used[c[1]];
    for( i = 2; i <= m; i++ ){
        if( used[b[i]] > cnt1 ){
            cnt1 = used[b[i]];
            cnt2 = used[c[i]];
            h = i;
        }
        else if( used[b[i]] == cnt1 && used[c[i]] > cnt2 ){
            cnt2 = used[c[i]];
            h = i;
        }
    }
    pr( "%d\n", h );
}