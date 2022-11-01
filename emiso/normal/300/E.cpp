#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MAX 10001000
#define MN 1000100

int n, a[MN], seen[MAX];
ll ans, quant[MAX], freq[MAX];

ll factors(ll x, ll p) {
    ll ret = 0;
    for(ll tmp = p; tmp <= x; tmp *= p)
        ret += x / tmp;
    return ret;
}

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        freq[a[i]]++;
    }

    for(int i = 2; i < MAX; i++) {
        if(seen[i]) continue;
        seen[i] = i;
        for(int j = i + i; j < MAX; j += i)
            seen[j] = i;
    }

    for(int i = MAX-2; i >= 0; i--)
        freq[i] += freq[i+1];

    for(int i = 2; i <  MAX; i++)
        for(int tmp = i; tmp > 1; tmp /= seen[tmp])
            quant[seen[tmp]] += freq[i];

    for(int i = 2; i < MAX; i++) {
        ll l = 1, r = LLONG_MAX, m;
        while(l < r) {
            m = (l + r) / 2;
            if(factors(m, i) < quant[i]) l = m + 1;
            else r = m;
        }

        ans = max(ans, l);
    }


    printf("%lld\n", ans);
    return 0;
}