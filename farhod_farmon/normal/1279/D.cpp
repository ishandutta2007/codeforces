#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1000100;
const long long mod = 998244353;

using namespace std;

long long pw(long long x, long long n)
{
        long long res = 1;
        while(n > 0){
                if(n & 1){
                        res = res * x % mod;
                }
                x = x * x % mod;
                n /= 2;
        }
        return res;
}

int n;
int c[N];
vector < int > a[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                int k;
                cin >> k;
                a[i].resize(k);
                for(int &x: a[i]){
                        cin >> x;
                        c[x] += 1;
                }
        }

        long long res = 0;
        for(int i = 1; i <= n; i++){
                long long A = 0, B = 0;
                for(int x: a[i]){
                        A += c[x];
                        B += n;
                }
                A %= mod;
                B %= mod;

                res += A * pw(B, mod - 2) % mod;
                if(res >= mod){
                        res -= mod;
                }
        }

        cout << res * pw(n, mod - 2) % mod << "\n";
}