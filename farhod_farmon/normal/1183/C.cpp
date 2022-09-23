#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 998244353;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                long long k, n, a, b;
                cin >> k >> n >> a >> b;
                if(n * b >= k){
                        cout << -1 << "\n";
                        continue;
                }
                long long l = 0, r = n;
                while(l < r){
                        long long m = (l + r) / 2 + 1;
                        if(m * a >= k){
                                r = m - 1;
                        } else if((k - m * a - 1) / b + m >= n){
                                l = m;
                        } else{
                                r = m - 1;
                        }
                }
                cout << l << "\n";
        }
}