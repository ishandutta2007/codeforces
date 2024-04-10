#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN], freq[MN];

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
    int flag = 0;
    for(int i = 0; i <= 101; i++) {
        if(flag == 0 && freq[i] < 2) {
            flag = 1;
            ans += i;
        }
        if(freq[i] == 0) {
            ans += i;
            break;
        }
    }

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}