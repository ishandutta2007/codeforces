#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int T, n, a, b, c;
char s[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d %s", &n, &a, &b, &c, s + 1);
        if (n == 1) { puts("0"); continue; }
        int num0 = 0, num1 = 0, len1 = 0, len2 = 0;
        vector<int> V;
        for (int i = 1, j; i <= n; i = j) {
            for (j = i; j <= n && s[i] == s[j]; j++);
            if (s[i] == '0') {
                num0 += j - i - 1;
                if (s[i - 1] == '1' && j <= n && s[j] == '1') V.push_back(j - i - 1);
                else if (i == 1) len1 = j - i;
                else len2 = j - i;
            } else {
                num1 += j - i - 1;
            }
        }
        sort(V.begin(), V.end());
        long long ans = 0;
        for (int fir : {0, 1}) {
            long long cur = 0;
            int c0 = 0, c1 = num1, p = 0, n0 = num0, l1 = len1, l2 = len2;
            for (int i = fir; ; i ^= 1) {
                if (!i) {
                    if (c0 < n0) ans = max(ans, cur + a);
                    if (c0 < n0 && c1) {
                        cur += a, c0++;
                    } else {
                        cur -= c;
                        if (c1 && max(l1, l2) && (p == V.size() || min(!l1 ? INT_MAX : l1, !l2 ? INT_MAX : l2) < V[p])) {
                            if (l1 && (!l2 || l1 < l2)) {
                                if (c0 >= l1 - 1) c0 -= l1 - 1, n0 -= l1 - 1, l1 = 0;
                                else n0--, l1--;
                            } else {
                                if (c0 >= l2 - 1) c0 -= l2 - 1, n0 -= l2 - 1, l2 = 0;
                                else n0--, l2--;
                            }
                        } else if (p == V.size() || c0 < V[p]) {
                            break;
                        } else {
                            c0 -= V[p], n0 -= V[p];
                            p++, c1++;
                        }
                    }
                } else {
                    if (!c1) break;
                    c1--, cur += b;
                }
                ans = max(ans, cur);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}