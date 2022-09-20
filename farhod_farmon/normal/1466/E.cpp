#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
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
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                int n;
                cin >> n;
                vector < long long > a(n);
                for(int i = 0; i < n; i++){
                        cin >> a[i];
                }
                vector < int > A(n, 0), B(n, 0);
                for(int i = 0; i < 60; i++){
                        int x = 0, y = 0;
                        long long P = (1ll << i);
                        for(int j = 0; j < n; j++){
                                if(a[j] & P){
                                        x += 1;
                                } else{
                                        y += 1;
                                }
                        }
                        long long p2 = P % mod;
                        for(int j = 0; j < n; j++){
                                if(a[j] & P){
                                        add(A[j], p2 * x % mod);
                                        add(B[j], p2 * n % mod);
                                } else{
                                        add(B[j], p2 * x % mod);
                                }
                        }
                }
                int res = 0;
                for(int i = 0; i < n; i++){
                        add(res, 1ll * A[i] * B[i] % mod);
                }
                cout << res << "\n";
        }
}