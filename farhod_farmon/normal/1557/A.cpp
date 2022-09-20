#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 110;
const int mod = 1e9 + 7;

using namespace std;

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
                vector<int> a(n);
                long double A = 0, B = 0;
                for(int i = 0; i < n; i++){
                        cin >> a[i];
                        B += a[i];
                }
                sort(a.begin(), a.end());
                long double res = -1e18;
                for(int i = 0; i < n - 1; i++){
                        A += a[i];
                        B -= a[i];
                        res = max(res, A / (i + 1) + B / (n - i - 1));
                }
                cout << fixed << setprecision(9) << res << "\n";
        }
}