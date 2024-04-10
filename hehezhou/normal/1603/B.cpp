#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int x, y;
ll ans;
void rmain() {
    scanf("%d%d", &x, &y);
    if (y < x) {
        printf("%d\n", ans = x + y);
    }
    else {
        x = x * (y / x);
        printf("%d\n", ans = (x + y) / 2);
    }
    assert(ans % x == y % ans);
}
int main() {
    scanf("%d", &t);
    while (t--) rmain();
}