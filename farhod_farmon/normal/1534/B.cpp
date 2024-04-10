#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;

using namespace std;

void solve()
{
        int n;
        cin >> n;
        vector < int > a(n + 2, 0);
        long long res = 0;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                res += abs(a[i] - a[i - 1]);
        }
        res += a[n];
        for(int i = 1; i <= n; i++){
                if(a[i] > a[i - 1] && a[i] > a[i + 1]){
                        res -= a[i] - max(a[i - 1], a[i + 1]);
                }
        }
        cout << res << "\n";
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