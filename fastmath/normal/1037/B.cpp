#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e5 + 7;

int n, k;
int a[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];

    int l = 0, r = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] < k) {
            ++l;
        }
        else if (a[i] > k) {
            ++r;
        }
    }

    int ans = 0;

    if (l > (n / 2)) {
        vector <int> v;
        for (int i = 0; i < n; ++i) {
            if (a[i] < k) v.push_back(a[i]);
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        int t = l - (n / 2);
        for (int i = 0; i < t; ++i) {
            ans += k - v[i];
        }
    }

    if (r > (n / 2)) {
        vector <int> v;
        for (int i = 0; i < n; ++i) {
            if (a[i] > k) v.push_back(a[i]);
        }
        sort(v.begin(), v.end());
        int t = r - (n / 2);
        for (int i = 0; i < t; ++i) {
            ans += v[i] - k;
        }
    }

    cout << ans << '\n';
    return 0;
}