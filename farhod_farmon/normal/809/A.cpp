#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 300300;
const long long MX = 30030;
const long long MAGIC = 30;
const long long mod = 1e9 + 7;

using namespace std;

int n;
ll a[N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        ll p = 1;
        ll s = 0;
        ll ans = 0;
        for(int i = 1; i <= n; i++){
                if(i > 1){
                        ll g = a[i] * (p * 2 - 1) % mod;
                        g = (g - s + mod) % mod;
                        ans = (ans + g) % mod;
                        p = (p + p) % mod;
                }
                s = (s + s + a[i]) % mod;
        }
        ans = (ans % mod + mod) % mod;
        cout << ans << endl;
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("unionday.in");
        //fout("unionday.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}