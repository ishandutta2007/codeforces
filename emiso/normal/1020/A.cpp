#include <bits/stdc++.h>

using namespace std;

int n, h, a, b, k, ta, fa, tb, fb;

int main() {
    scanf("%d %d %d %d %d", &n, &h, &a, &b, &k);
    while(k--) {
        scanf("%d %d %d %d", &ta, &fa, &tb, &fb);

        int ans = abs(ta - tb);
        if(ans == 0) ans = abs(fa - fb);
        else {
            if(fa > b && fb > b) {
                ans += (fa - b);
                ans += (fb - b);
            } else if(fa < a && fb < a) {
                ans += (a - fa);
                ans += (a - fb);
            } else ans += abs(fa - fb);
        }
        printf("%d\n", ans);
    }
    return 0;
}