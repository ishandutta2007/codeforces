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

int n, a[1001], i, j, cnt;
vector < pair < int, int > > v;

int main()
{
    cin >> n;
    for( i = 1; i <= n; i++ )cin >> a[i];
    sort( a + 1, a + n + 1 );
    for( i = 1; i <= n; i++ ){
        int in = -1;
        for( j = 0; j < v.size(); j++ ){
            if( a[i] > v[j].fi && (in == -1 || v[j].fi < v[in].fi) )in = j;
        }
        if( in != -1 ){
            v[in].fi = a[i];
            v[in].se++;
        }
        else v.pb(mp(a[i], 1));
    }
    for( i = 0; i < v.size(); i++ )cnt += v[i].se - 1;
    cout << cnt << endl;
}