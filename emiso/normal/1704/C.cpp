#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll t = 1, n, m, ans, a[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %lld", &n, &m);

    for(int i = 0; i < m; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a, a + m);

    vector<ll> segm;
    for(int i = 1; i < m; i++) {
        segm.push_back(a[i] - a[i-1] - 1);
    }
    segm.push_back(a[0] - 1 + n - a[m-1]);

    sort(segm.rbegin(), segm.rend());

    ll tmp = 0;
    for (ll s : segm) {
        s -= 2*tmp;
        if (s > 0) {
            ans++;
            tmp++;
            if (s > 2) {
                ans += s - 2;
                tmp++;
            }
        }
    }

    printf("%lld\n", n - ans);
    if(--t) goto st;
    return 0;
}