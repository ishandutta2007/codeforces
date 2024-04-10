#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 200200;
const long long inf = 2e18;

void solve()
{
        int n;
        long long k;
        cin >> n >> k;
        vector < long long > f(n + 1, 0);
        f[0] = 1;
        long long sum = 1;
        for(int i = 1; i <= n; i++){
                f[i] = sum;
                sum = min(sum + f[i], inf);
        }

        if(k > f[n]){
                cout << -1 << "\n";
                return;
        }

        vector < int > res;
        for(int i = 1; i <= n; i++){
                for(int j = 0; ; j++){
                        if(k > f[n - i - j]){
                                k -= f[n - i - j];
                                continue;
                        }
                        i += j;
                        for(int x = 0; x <= j; x++){
                                res.push_back(i - x);
                        }
                        break;
                }
        }
        for(int x: res){
                cout << x << " ";
        }
        cout << "\n";
}

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
                solve();
        }
}