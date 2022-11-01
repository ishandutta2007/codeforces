#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN];

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &n);

    ans = 0;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for(int i = 1; i + 1 < n; i++) {
        if(a[i] > a[i-1] && a[i] > a[i+1]) ans++;
        if(a[i] < a[i-1] && a[i] < a[i+1]) ans++;
    }

    ll tmp = 0, best = ans;
    for(int j = 0; j < n; j++) {
        ll last = a[j], b4 = ans;

        for(int i = max(j-1, 1); i <= min(n-2, j+1LL); i++) {
            if(a[i] > a[i-1] && a[i] > a[i+1]) ans--;
            if(a[i] < a[i-1] && a[i] < a[i+1]) ans--;
        }

        if(j) {
            tmp = 0;
            a[j] = a[j-1];
            for(int i = max(j-1, 1); i <= min(n-2, j+1LL); i++) {
                if(a[i] > a[i-1] && a[i] > a[i+1]) tmp++;
                if(a[i] < a[i-1] && a[i] < a[i+1]) tmp++;
            }
            best = min(best, ans + tmp);
        }
        if(j + 1 < n) {
            tmp = 0;
            a[j] = a[j+1];
            for(int i = max(j-1, 1); i <= min(n-2, j+1LL); i++) {
                if(a[i] > a[i-1] && a[i] > a[i+1]) tmp++;
                if(a[i] < a[i-1] && a[i] < a[i+1]) tmp++;
            }
            best = min(best, ans + tmp);
        }

        a[j] = last;
        ans = b4;
    }

    printf("%lld\n", best);
    if(--t) goto st;
    return 0;
}