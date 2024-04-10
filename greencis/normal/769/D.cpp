#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

int n, k, x, cnt[30005];
vector<int> v;

int main()
{
    cin >> n >> k;
    while (n--) {
        cin >> x;
        ++cnt[x];
    }

    if (k == 0) {
        ll ans = 0;
        for (int i = 0; i <= 10000; ++i)
            ans += (ll)cnt[i] * (ll)(cnt[i] - 1) / 2LL;
        cout << ans << endl;
        return 0;
    }

    for (int mask = 0; mask < (1 << 14); ++mask) {
        if (__builtin_popcount(mask) == k)
            v.push_back(mask);
    }

    ll ans = 0;
    for (int i = 0; i <= 10000; ++i)
        for (size_t j = 0; j < v.size(); ++j)
            ans += (ll)cnt[i] * (ll)cnt[i ^ v[j]];
    ans /= 2LL;
    cout << ans << endl;

    return 0;
}