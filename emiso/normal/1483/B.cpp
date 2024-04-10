#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, a[MN];

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &n);

    set<int> look, cur;
    vector<int> ans;

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        look.insert(i);
    }
    cur = look;

    int last = 0;
    while(!cur.empty() && !look.empty()) {
        auto ub = cur.upper_bound(last);
        if(ub == cur.end())
            ub = cur.upper_bound(-1);

        int val = *ub;
        if (__gcd(a[last], a[val]) == 1) {
            cur.erase(val);
            ans.push_back(val);
            look.erase(val);
        } else {
            look.erase(last);
        }

        auto nxt = look.upper_bound(last);
        if(nxt == look.end())
            nxt = look.lower_bound(0);
        if(nxt == look.end())
            break;
        last = *nxt;
    }

    printf("%d", ans.size());
    for(ll x : ans) printf(" %lld", x + 1);
    printf("\n");

    if(--t) goto st;
    return 0;
}