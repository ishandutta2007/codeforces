#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int n, k, z;
int a[N];

void solve()
{
        cin >> n >> k >> z;
        int res = 0, sum = 0, mx = 0;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                sum += a[i];
                mx = max(mx, a[i - 1] + a[i]);
                if(i - 1 <= k){
                        int rem = k - (i - 1);
                        if(rem / 2 <= z){
                                int to_add = (rem / 2) * mx;
                                if(rem % 2 && rem / 2 + 1 <= z){
                                        to_add += a[i - 1];
                                }
                                res = max(res, sum + to_add);
                        }
                }
        }
        cout << res << "\n";
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                solve();
        }
}