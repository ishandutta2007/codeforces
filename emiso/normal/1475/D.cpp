#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, m, ans, a[MN], b[MN];

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld %lld", &n, &m);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    vector<int> b1, b2;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
        if(b[i] == 1) b1.push_back(a[i]);
        if(b[i] == 2) b2.push_back(a[i]);
    }

    sort(b1.rbegin(), b1.rend());
    sort(b2.rbegin(), b2.rend());

    ans = INT_MAX;
    for(ll i = -1, j = -1, sum = 0, bad = 0; i < (int)b1.size(); i++, bad += 1) {
        if(i >= 0) sum += b1[i];
        while(sum < m && j + 1 < (int)b2.size()) {
            sum += b2[++j];
            bad += 2;
        }
        while(j >= 0 && sum - b2[j] >= m) {
            sum -= b2[j--];
            bad -= 2;
        }
        if(sum >= m) {
            ans = min(ans, bad);
        }
    }

    if(ans == INT_MAX) puts("-1");
    else printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}