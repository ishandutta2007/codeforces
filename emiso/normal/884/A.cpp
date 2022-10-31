#include <bits/stdc++.h>

using namespace std;

int td = 86400, t, n, a, ans, tot;

int main() {
    scanf("%d %d", &n, &t);
    for(int i = 0; i < n; i++) {
        if(tot < t) ans++;
        scanf("%d", &a);
        tot += (td - a);
    }

    printf("%d\n", ans);
    return 0;
}