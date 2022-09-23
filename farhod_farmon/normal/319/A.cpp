#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 2e18;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int p[N];
string s;

void solve()
{
        cin >> s;
        n = s.size();
        s = '0' + s;
        p[0] = 1;
        for(int i = 1; i < N; i++){
                p[i] = 2 * p[i - 1];
                if(p[i] >= mod){
                        p[i] -= mod;
                }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
                if(s[i] == '1'){
                        ans += 1ll * p[i - 1] * p[n + n - i - i] % mod;
                }
                if(ans >= mod){
                        ans -= mod;
                }
        }
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