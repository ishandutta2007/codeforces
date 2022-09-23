#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

using namespace std;

long long c[31][31];

long long C(long long n, long long k)
{
    if(k > n)
        return 0;
    return c[n][k];
}

long long n, m, t;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> t;
    long long ans = 0;
    c[0][0] = 1;
    for(long long i = 1; i <= 30; i++){
        c[i][0] = 1;
        for(long long j = 1; j <= i; j++){
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
    for(long long i = 4; i < t; i++)
        ans += C(n, i) * C(m, t - i);
    cout << ans << endl;
}