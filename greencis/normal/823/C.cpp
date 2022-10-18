#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n;
ll k, a[105];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);

    ll sum = k;
    for (int i = 0; i < n; ++i)
        sum += a[i];
    ll ans = 0;
    for (int d = 300000; d >= 1; --d) {
        ll cur = 0;
        for (int i = 0; i < n; ++i)
            cur += (a[i] + d - 1) / d;
        cur *= d;
        if (cur <= sum) {
            ans = d;
            break;
        }
    }

    vector<ll> v;
    for (int i = 0; i < n; ++i) {
        for (int val = 1; val <= 3334; ++val) {
            int mn = (a[i] + 1 + val + 1 - 1) / (val + 1);
            int mx = a[i] / val;
            if (mn > mx)
                continue;
            if (mn < sum / n + 1)
                v.push_back(mn);
            if (mx + 1 < sum / n + 1)
                v.push_back(mx + 1);
        }
        if (a[i] + 1 < sum / n + 1)
            v.push_back(a[i] + 1);
    }
    v.push_back(sum / n + 1);
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());

    for (int i = 0; i + 1 < v.size(); ++i) {
        ll cursum = 0;
        ll d = v[i];
        for (int j = 0; j < n; ++j)
            cursum += (a[j] + d - 1) / d;
        ll mxd = sum / cursum;
        if (mxd >= d)
            ans = max(ans, min(v[i + 1] - 1, mxd));
    }

    cout << ans << endl;

    return 0;
}