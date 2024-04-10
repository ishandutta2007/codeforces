#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN], freq[105];

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &n);

    memset(freq, 0, sizeof freq);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        freq[a[i]]++;
    }

    ans = 0;
    for(int s = 1; s <= 2 * n; s++) {
        ll tmp = 0;
        for(int i = 1; i + i < s; i++) {
            tmp += min(freq[i], freq[s-i]);
        }
        if(s % 2 == 0) tmp += freq[s/2] / 2;
        ans = max(ans, tmp);
    }

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}