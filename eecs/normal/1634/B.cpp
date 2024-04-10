#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100010;
int T, n, x;
ll y;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %lld", &n, &x, &y);
        while (n--) {
            ll z;
            scanf("%lld", &z);
            x ^= z;
        }
        if (x % 2 == y % 2) puts("Alice");
        else puts("Bob");
    }
    return 0;
}