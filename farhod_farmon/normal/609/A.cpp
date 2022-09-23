#include <bits/stdc++.h>
#define lli long long int
#define sc scanf
#define pr printf
#define pb push_back
#define p_b pop_back
#define mp make_pair
#define fi first
#define se second
#define fin freopen( "odd.in", "r", stdin );
#define fout freopen( "odd.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int n, i, m, b[102], cnt;

int main()
{
    cin >> n >> m;
    for( i = 1; i <= n; i++ )cin >> b[i];
    sort( b + 1, b + n + 1 );
    i = n;
    while( i >= 1 ){
        if( b[i] >= m )break;
        b[i - 1] += b[i];
        cnt++;
        i--;
    }
    cout << cnt + 1 << endl;
}