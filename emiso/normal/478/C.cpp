#include <bits/stdc++.h>

using namespace std;

int r, g, b, ans;

int main() {
    scanf("%d %d %d", &r, &g, &b);
    if(r < g) swap(r, g);
    if(r < b) swap(r, b);
    if(g < b) swap(g, b);

    ans = g - b;
    ans = min(ans, r - g);

    r -= 2*ans;
    g -= ans;

    if(r == g) {
        ans += (g - b)/3*2;
        r -= (g - b)/3*3;
        g -= (g - b)/3*3;

        if(r == b + 2) {
            ans++;
            g -= 2;
            r--;
        }
    } else {
        assert(g == b);
        int tmp = b;
        tmp = min(tmp, (r-b)/3);

        r -= 4*tmp;
        g -= tmp;
        b -= tmp;
        ans += 2*tmp;
    }

    ans += min(r, min(g, b));
    printf("%d\n", ans);
    return 0;
}