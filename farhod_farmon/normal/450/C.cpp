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

const int N = 100100;

using namespace std;

lli n, m, k, ans1, ans2;

int main()
{
    cin >> n >> m >> k;
    if( n + m - 2 < k ){
        cout << -1 << endl;
        return 0;
    }
    if( k < n )
        ans1 = (n / (k + 1)) * m;
    else
        ans1 = m / (k - n + 2);
    if( k < m )
        ans2 = (m / (k + 1)) * n;
    else
        ans2 = n / (k - m + 2);
    cout << max(ans1, ans2) << endl;
}