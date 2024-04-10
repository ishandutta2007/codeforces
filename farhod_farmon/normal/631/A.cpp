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

lli n, a[1001], b[1001], cnt1, cnt2, i, j, ans;

int main()
{
    cin >> n;
    for( i = 1; i <= n; i++ )cin >> a[i];
    for( i = 1; i <= n; i++ )cin >> b[i];
    for( i = 1; i <= n; i++ ){
        cnt1 = cnt2 = 0;
        for( j = i; j <= n; j++ ){
            cnt1 |= a[j];
            cnt2 |= b[j];
            ans = max(ans, cnt1 + cnt2);
        }
    }
    cout << ans << endl;
}