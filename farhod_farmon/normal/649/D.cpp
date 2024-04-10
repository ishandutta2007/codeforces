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

int n, i, j, h, g, a[200002], in[200002], ans;
int used[200002];

int f( int l, int r, int tl, int tr )
{
    int cl = max(l, tl);
    int cr = min(r, tr);
    int x = tr - tl + 1;
    int y = max(0, cr - cl + 1);
    return x - y;
}

int main()
{
    int x;
    sc( "%d", &n );
    for( i = 1; i <= n; i++ ){
        sc( "%d", &x );
        if( !x )
            continue;
        if( !used[x] ){
            used[x] = ++g;
            in[g] = i;
        }
        a[used[x]]++;
    }
    h = 1;
    for( i = 1; i <= g; i++ ){
        ans += f(in[i], in[i] + a[i] - 1, h, h + a[i] - 1);
        h += a[i];
    }
    pr( "%d\n", ans );
}