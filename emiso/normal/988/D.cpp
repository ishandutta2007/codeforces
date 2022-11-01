#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

int n, ans, a[MN];
ll ansL, ansJ;
map<ll, int> m;

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        m[a[i]] = i;
    }
    sort(a, a + n);
    ans = 1;
    ansL = a[0];

    for(ll b = 0; b < 32 && ans < 3; b++) {
        for(int i = 0; i < n && ans < 3; i++) {
            ll x = a[i];
            if(m.count(x + (1LL << b))) {
                ans = 2;
                ansL = x;
                ansJ = (1LL << b);

                ll y = x + (1LL << b);

                if(m.count(y + (1LL << b))) {
                    ans = 3;
                }
            }
        }
    }

    printf("%d\n", ans);
    for(ll i = 0; i < ans; i++, ansL += ansJ) {
        printf("%lld ", ansL);
    }
    return 0;
}