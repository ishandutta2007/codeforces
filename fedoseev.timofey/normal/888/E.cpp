#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int k = n / 2;
    vector <int> summs;
    for (int mask = 0; mask <= (1 << k); ++mask) {
        int s = 0;
        for (int i = 0; i < k; ++i)
            if (mask & (1 << i))
                s = (s + a[i]) % m;
        summs.push_back(s);
    }
    sort(summs.begin(), summs.end());
    summs.resize(unique(summs.begin(), summs.end()) - summs.begin());
    int ans = -1;
    int t = n - k;
    for (int mask = 0; mask <= (1 << t); ++mask) {
        int s = 0;
        for (int i = 0; i < t; ++i)
            if (mask & (1 << i))
                s = (s + a[i + k]) % m;
        ans = max(ans, (s + summs.back()) % m);
        int ind = lower_bound(summs.begin(), summs.end(), m - s) - summs.begin();
        if (ind != 0) {
            --ind;
            ans = max(ans, (s + summs[ind]) % m);
        }
    }
    cout << ans << endl;
}