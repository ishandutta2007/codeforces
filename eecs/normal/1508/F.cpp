#include <bits/stdc++.h>
using namespace std;

const int maxn = 25010;
int n, q, ans, a[maxn], lb[maxn], rb[maxn];
int prel[maxn], prer[maxn], nxtl[maxn], nxtr[maxn];

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), lb[i] = rb[i] = i;
        prel[i] = prer[i] = nxtl[i] = nxtr[i] = -1;
    }
    while (q--) {
        int l, r; scanf("%d %d", &l, &r);
        for (int i = l; rb[i] < r; i++) {
            while (rb[i] < r) {
                int k = ++rb[i];
                if (a[k] < a[i]) {
                    if (~prer[i]) ans -= (nxtl[prer[i]] == i);
                    if (!~prer[i] || a[k] > a[prer[i]]) prer[i] = k;
                    if (~prer[i]) ans += (nxtl[prer[i]] == i);
                } else {
                    if (~nxtr[i]) ans -= (prel[nxtr[i]] == i);
                    if (!~nxtr[i] || a[k] < a[nxtr[i]]) nxtr[i] = k;
                    if (~nxtr[i]) ans += (prel[nxtr[i]] == i);
                }
            }
        }
        for (int i = r; lb[i] > l; i--) {
            while (lb[i] > l) {
                int k = --lb[i];
                if (a[k] < a[i]) {
                    if (~prel[i]) ans -= (nxtr[prel[i]] == i);
                    if (!~prel[i] || a[k] > a[prel[i]]) prel[i] = k;
                    if (~prel[i]) ans += (nxtr[prel[i]] == i);
                } else {
                    if (~nxtl[i]) ans -= (prer[nxtl[i]] == i);
                    if (!~nxtl[i] || a[k] < a[nxtl[i]]) nxtl[i] = k;
                    if (~nxtl[i]) ans += (prer[nxtl[i]] == i);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}