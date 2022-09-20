#include "bits/stdc++.h"

#define fi first
#define se second

const int N = 100100;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        long long k;
        cin >> k;
        vector<long long> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        for(int i = 1; i < n; i++){
            a[i] += a[i - 1];
        }
        if(a[n - 1] <= k){
            cout << 0 << "\n";
            continue;
        }
        long long res = 1e18;
        for(int i = 1; i <= n; i++){
            // i * g + sum <= k -> g <= (k - sum) / i
            long long g = (k - (a[n - i] - a[0])) / i + 1;
            while(a[n - i] - a[0] + i * g > k) g--;
            res = min(res, max(0ll, a[0] - g) + i - 1);
        }
        cout << res << "\n";
    }
}