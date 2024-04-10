#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int T, n;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int v1 = INT_MAX, w1 = INT_MAX;
        int v2 = 0, w2 = INT_MAX;
        int v3 = 0, w3 = INT_MAX;
        while (n--) {
            int l, r, c;
            scanf("%d %d %d", &l, &r, &c);
            if (l < v1) v1 = l, w1 = c;
            else if (l == v1) w1 = min(w1, c);
            if (r > v2) v2 = r, w2 = c;
            else if (r == v2) w2 = min(w2, c);
            if (r - l > v3) v3 = r - l, w3 = c;
            else if (r - l == v3) w3 = min(w3, c);
            int ans = w1 + w2;
            if (v2 - v1 == v3) ans = min(ans, w3);
            printf("%d\n", ans);
        }
    }
    return 0;
}