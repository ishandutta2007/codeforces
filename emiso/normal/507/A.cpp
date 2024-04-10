#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll n, k;
pair<ll, ll> a[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld %lld", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i].first);
        a[i].second = i;
    }
    sort(a, a + n);

    ll ans = 0;
    vector<int> aa;

    for (int i = 0; i < n; i++) {
        if (k >= a[i].first) {
            ans++;
            aa.push_back(a[i].second);
            k -= a[i].first;
        }
    }

    printf("%lld\n", ans);
    for (int x : aa) printf("%d ", x + 1);
    return 0;
}