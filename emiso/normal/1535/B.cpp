#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN];

int main() {
    scanf("%lld", &t);
    st:
    ans = 0;
    scanf("%lld", &n);

    vector<ll> od, ev;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if(a[i] % 2) od.push_back(a[i]);
        else ev.push_back(a[i]);
    }
    ev.insert(ev.end(), od.begin(), od.end());
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            ans += (__gcd(ev[i], 2*ev[j]) > 1);


    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}