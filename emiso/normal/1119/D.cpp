#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, q, a[MN], tot;
vector<ll> ds;
map<ll, ll> jonson;

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a, a + n);
    for(int i = 1; i < n; i++) {
        ds.push_back(a[i] - a[i-1]);
    }
    sort(ds.begin(), ds.end());

    for(int i = 0; i < ds.size(); i++) {
        tot += ds[i];
        jonson[ds[i]] = tot;
    }

    scanf("%lld", &q);
    while(q--) {
        ll l, r, len, ans = 0;
        scanf("%lld %lld", &l, &r);
        len = r - l + 1;

        auto tmp = jonson.upper_bound(len);
        if(tmp != jonson.begin()) {
            ans += prev(tmp)->second;
        }

        int pos = upper_bound(ds.begin(), ds.end(), len) - ds.begin();
        ans += (n - pos) * len;

        printf("%lld ", ans);
    }
    return 0;
}