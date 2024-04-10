#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 5000050;
const long long mod = 1e9 + 7;

using namespace std;

ll p[N];
vector < int > v;

void solve()
{
        for(int i = 2; i < N; i++){
                if(p[i] == 0){
                        p[i] = i;
                        v.pb(i);
                }
                for(int j = 0; j < v.size() && v[j] <= p[i] && 1ll * i * v[j] < N; j++){
                        p[i * v[j]] = v[j];
                }
                p[i] = p[i / p[i]] + 1ll * i * (p[i] - 1) / 2;
                p[i] %= mod;
        }
        ll t, l, r, ans = 0, pw = 1;
        cin >> t >> l >> r;
        for(int i = l; i <= r; i++){
                ll x = pw * p[i] % mod;
                ans = (ans + x) % mod;
                pw = (pw * t) % mod;
        }
        cout << ans << endl;
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("landscape.in");
        //fout("landscape.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}