#include <bits/stdc++.h>

using namespace std;

int d(char a, char b) {
    if(a > b) swap(a, b);
    return min(b - a, 26 + a - b);
}

int n, p, ans, minP = 100010, maxP = -1;
char s[100010];

int main() {
    scanf("%d %d %s", &n, &p, s);
    p--;

    for(int i = 0, j = n-1; i < j; i++, j--) {
        ans += d(s[i], s[j]);
        if(p == j) p = i;

        if(d(s[i], s[j])) {
            minP = min(minP, i);
            maxP = max(maxP, i);
        }
    }
    if(ans == 0) puts("0");
    else {
        ans += min(abs(p - minP), abs(p - maxP)) + (maxP - minP);
        printf("%d\n", ans);
    }
    return 0;
}