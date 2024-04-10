#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;

int main() {
    ios_base::sync_with_stdio(false);

    vector<ll> v;
    for (int len = 2; len <= 10; ++len) {
        for (int mask = 1 << len; mask--; ) {
            if (__builtin_popcount(mask) * 2 != len)
                continue;
            ll cur = 0;
            for (int i = 0; i < len; ++i)
                cur = cur * 10 + (((mask >> i) & 1) ? 4 : 7);
            v.push_back(cur);
        }
    }
    sort(v.begin(), v.end());
    int n;
    cin >> n;
    cout << *lower_bound(v.begin(), v.end(), n);
}