#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int mod = 998244353;

using namespace std;

int pw(int x, int n)
{
        int res = 1;
        for(; n > 0; n >>= 1){
                if(n & 1){
                        res = 1ll * res * x % mod;
                }
                x = 1ll * x * x % mod;
        }
        return res;
}

void add(int &x, int y)
{
        x += y;
        if(x >= mod){
                x -= mod;
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int n;
        cin >> n;
        vector < int > d(n + 1, 0), s(n + 1, 0);
        d[0] = s[0] = 1;
        for(int i = 1; i <= n; i++){
                d[i] = s[i - 1];
                s[i] = d[i];
                if(i >= 2){
                        add(s[i], s[i - 2]);
                }
        }
        cout << 1ll * d[n] * pw(pw(2, n), mod - 2) % mod << "\n";
}