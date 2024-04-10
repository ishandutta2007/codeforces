#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 1e9 + 7;

using namespace std;

int pw(int x, int n)
{
        int res = 1;
        while(n){
                if(n & 1){
                        res = res * 1ll * x % mod;
                }
                x = 1ll * x * x % mod;
                n /= 2;
        }
        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int n, m;
        cin >> n >> m;
        m = pw(2, m) - 1;
        if(m < 0){
                m += mod;
        }
        cout << pw(m, n) << "\n";
}