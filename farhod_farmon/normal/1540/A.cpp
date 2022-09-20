#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 400400;

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
                vector < int > a(n);
                for(int i = 0; i < n; i++) {
                        cin >> a[i];
                }
                sort(a.begin(), a.end());
                long long res = a[n - 1], s = 0;
                for(int i = 0; i < n; i++){
                        res -= 1ll * a[i] * i - s;
                        s += a[i];
                }
                cout << res << "\n";
        }
}