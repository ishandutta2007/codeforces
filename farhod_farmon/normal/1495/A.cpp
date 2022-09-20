#include <bits/stdc++.h>

using namespace std;

#ifdef zxc
#include "debug.h"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#define debug_arr(...) 42
#endif

#define fi first
#define se second

const int N = 200200;
const int mod = 1e9 + 7;

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                int n;
                cin >> n;
                vector < long long > a, b;
                for(int i = 0; i < 2 * n; i++){
                        long long x, y;
                        cin >> x >> y;
                        if(x == 0){
                                a.push_back(y * y);
                        } else{
                                b.push_back(x * x);
                        }
                }

                sort(a.begin(), a.end());
                sort(b.begin(), b.end());

                long double res = 0;
                for(int i = 0; i < n; i++){
                        res += sqrt((long double)a[i] + b[i]);
                }
                cout << fixed << setprecision(9) << res << "\n";
        }
}