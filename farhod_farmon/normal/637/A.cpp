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

int n, ans, x, i, d[1000001];

int main()
{
    cin >> n;
    for( i = 1; i <= n; i++ ){
        cin >> x;
        d[x]++;
        if( d[x] > d[ans] )ans = x;
    }
    cout << ans << endl;
}