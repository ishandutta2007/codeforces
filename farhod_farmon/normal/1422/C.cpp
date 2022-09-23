#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;
const int mod = 1e9 + 7;

using namespace std;

void add(int &x, int y)
{
        x += y;
        if(x >= mod){
                x -= mod;
        }
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        string s;
        cin >> s;
        int n = s.size();
        s = "#" + s;
        vector < int > pw(n + 1, 1);
        for(int i = 1; i <= n; i++){
                pw[i] = pw[i - 1] * 10ll % mod;
        }
        vector < int > suf(n + 1, 0);
        for(int i = n; i >= 1; i--){
                suf[i] = (1ll * (s[i] - '0') * pw[n - i] + (i < n ? suf[i + 1] : 0)) % mod;
        }
        int res = 0, pref = 0, sum_pref = 0;
        for(int i = 1; i <= n; i++){
                add(res, sum_pref * 1ll * pw[n - i] % mod);
                add(res, (i < n ? suf[i + 1] : 0) * 1ll * i % mod);

                pref = (1ll * pref * 10 + s[i] - '0') % mod;
                add(sum_pref, pref);
        }

        cout << res << "\n";
}