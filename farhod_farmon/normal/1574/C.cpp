#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 3003;

using namespace std;


int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int n;
        cin >> n;
        vector<long long> a(n);
        long long s = 0;
        for(int i = 0; i < n; i++){
                cin >> a[i];
                s += a[i];
        }
        long long inf = 4e18;
        sort(a.begin(), a.end());
        int q;
        cin >> q;
        for(int i = 0; i < q; i++){
                long long x, y;
                cin >> x >> y;
                int j = lower_bound(a.begin(), a.end(), x) - a.begin();
                long long res = inf, cur;
                for(int h : {j - 1, j}){
                        if(h < 0 || h >= n){
                                continue;
                        }
                        res = min(res, max(0ll, x - a[h]) + max(0ll, y - (s - a[h])));
                }
                cout << res << "\n";
        }
}