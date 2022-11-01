#include <bits/stdc++.h>

int main() {

int n, a, b, c, t, x, ans = 0;
scanf("%d %d %d %d %d", &n, &a, &b, &c, &t);
for(int i = 0; i < n; i++) {
scanf("%d", &x);
if(b < c) {
ans += a + (t - x) * (c - b);
} else {
ans += a;
}
}
printf("%d\n", ans);
    return 0;
}