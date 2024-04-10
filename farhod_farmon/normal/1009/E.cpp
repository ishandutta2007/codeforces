#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1000100;
const long long Q = N * 30;
const long long mod = 998244353;
const long long MAGIC = 30;

using namespace std;

int n;
int a[N];
int d[N];
int p[N];

void add(int &x, int y)
{
        x += y;
        if(x < 0) x += mod;
        if(x >= mod) x -= mod;
}

void solve()
{
        cin >> n;
        p[0] = 1;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                add(a[i], a[i - 1]);
                add(p[i], p[i - 1] + p[i - 1]);
        }
        int ans = 0, f = 0;
        for(int i = 1; i < n; i++){
                add(d[i], d[i - 1]);
                add(d[i], f);
                add(f, f);
                add(f, a[i]);
                add(d[i], a[i]);
                add(ans, (1ll * p[i - 1] * a[n - i]) % mod);
                add(ans, d[i]);
                add(d[i], d[i - 1]);
        }
        add(ans, a[n]);
        cout << ans << "\n";
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