#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 555;
const long long mod = 1e9 + 7;

using namespace std;

void upd(int &x, int y)
{
        x += y;
        if(x < 0){
                x += mod;
        } else if(x >= mod){
                x -= mod;
        }
}

int solve(long long n)
{
        int res = 0;
        long long a = 0, b = 0, sz = 1;
        for(int it = 0; n > 0; it ^= 1){
                if(it == 0){
                        long long len = min(n, sz);
                        a += len;
                        n -= len;
                } else{
                        long long len = min(n, sz);
                        b += len;
                        n -= len;
                }
                sz += sz;
        }
        a %= mod;
        b %= mod;
        upd(res, a * (a + 1) % mod);
        upd(res, b * (b + 1) % mod);
        upd(res, - a);

        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        long long l, r;
        cin >> l >> r;

        int res = solve(r);
        upd(res, - solve(l - 1));

        cout << res << "\n";
}