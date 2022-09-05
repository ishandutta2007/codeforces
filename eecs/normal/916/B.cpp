#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, k, tmp[200010];
ll& cnt(int x) { return tmp[x + 100000]; }

int main() {
    scanf("%lld %lld", &n, &k);
    int mn = 1e9;
    for (int i = 63; ~i; i--) {
        if (n >> i & 1) cnt(i)++, mn = i, k--;
    }
    if (k < 0) printf("No\n"), exit(0);
    printf("Yes\n");
    while (k--) {
        for (int i = 65; i >= -65; i--) {
            if (cnt(i) > k + 1) {
                cnt(mn)--, cnt(mn - 1)++, cnt(mn - 1)++, mn--; break;
                break;
            }
            if (cnt(i)) {
                cnt(i)--, cnt(i - 1)++, cnt(i - 1)++, mn = min(mn, i - 1); break;
            }
        }
    }
    for (int i = 100000; i >= -100000; i--) {
        while (cnt(i)--) {
            printf("%d ", i);
        }
    }
    return 0;
}