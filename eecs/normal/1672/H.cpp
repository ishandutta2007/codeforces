#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, q, len[maxn], cnt[maxn];
char a[maxn];

int main() {
    scanf("%d %d %s", &n, &q, a + 1);
    for (int i = 1; i <= n; i++) {
        len[i] = len[i - 1] + (a[i] == a[i - 1]);
        cnt[i] = cnt[i - 1] + (a[i] == a[i - 1] && a[i] == '1');
    }
    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        int m = len[r] - len[l];
        int one = cnt[r] - cnt[l], zero = m - one;
        printf("%d\n", max({one, zero}) + 1);
    }
    return 0;
}