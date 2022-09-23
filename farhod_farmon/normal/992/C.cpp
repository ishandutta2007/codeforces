#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 100000001;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

long long pw(long long x, long long n)
{
        x %= mod;
        if(n == 0){
                return 1;
        }
        if(n % 2){
                return x * pw(x, n - 1) % mod;
        }
        else{
                return pw(x * x, n / 2);
        }
}

long long x, k;

void solve()
{
        cin >> x >> k;
        if(k == 0 || x == 0){
                cout << (x + x) % mod << "\n";
                return;
        }
        x %= mod;
        long long ans = x * pw(2, k + k) % mod - pw(2, k - 1) * (pw(2, k) - 1) % mod;
        ans %= mod;
        if(ans < 0){
                ans += mod;
        }
        ans = ans * pw(pw(2, k - 1), mod - 2) % mod;
        cout << ans << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("maze.in");
        //fout("maze.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}