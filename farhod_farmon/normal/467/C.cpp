#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 5050;

using namespace std;

long long d[2][N];
long long n, m, k, p[N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        cin >> p[i];
        p[i] += p[i - 1];
    }
    for(int i = 1; i <= k; i++)
        for(int j = m; j <= n; j++)
            d[i % 2][j] = max(d[i % 2][j - 1], d[(i + 1) % 2][j - m] + p[j] - p[j - m]);
    long long ans = 0;
    for(int i = 1; i <= n; i++)
        ans = max(ans, d[k % 2][i]);
    cout << ans << endl;
}