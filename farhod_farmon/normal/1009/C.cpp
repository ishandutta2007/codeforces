#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = N * 30;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int m;
long long S;

long long g(long long x)
{
        return x * (x + 1) / 2;
}

void solve()
{
        cin >> n >> m;
        long long ans = 0, mx = 0, mn = 1e18;
        for(int i = 1; i <= n; i++){
                mx = max(mx, g(i - 1) + g(n - i));
                mn = min(mn, g(i - 1) + g(n - i));
        }
        for(int i = 1; i <= m; i++){
                long long x, d;
                cin >> x >> d;
                ans += max(d * mx, d * mn) + x * n;
        }
        cout << fixed << setprecision(9) << 1.0 * ans / n << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("island.in");
        //fout("island.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}