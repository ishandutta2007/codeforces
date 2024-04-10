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

int n;
long long f[33];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    long long ans = 0;
    sc("%d", &n);
    for(int i = 1; i <= n; i++){
        int x;
        sc("%d", &x);
        f[x + 12]++;
    }
    for(int i = 1; i <= 10; i++)
        ans += 1ll * f[i + 12] * f[-i + 12];
    cout << ans + 1ll * f[12] * (f[12] - 1) / 2ll << endl;
}