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

const int N = 30003;

using namespace std;

int n, d, c[N], dp[N][555];
bool used[N][555];

int rec( int x, int p )
{
    int l = p - d + 250;
    if( x >= N )
        return 0;
    if( used[x][l] )
        return dp[x][l];
    used[x][l] = true;
    if( p > 1 )
        dp[x][l] = rec(x + p - 1, p - 1);
    dp[x][l] = max(dp[x][l], rec(x + p, p));
    dp[x][l] = max(dp[x][l], rec(x + p + 1, p + 1));
    dp[x][l] += c[x];
    return dp[x][l];
}

int main()
{
    int i, x;
    cin >> n >> d;
    for( i = 1; i <= n; i++ ){
        cin >> x;
        c[x]++;
    }
    cout << rec(d, d) << endl;
}