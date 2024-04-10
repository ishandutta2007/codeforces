#include <ctime>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
int a, b;
long long ans;
int main() {
    scanf("%d %d", &a, &b);
    for (int l = 1; l <= a + b ; l ++) {
        int g = (a + b) / l ;
        int r = (a + b) / g;
        int ra = a / g, la = a / (1 + g) + (a % (1 +g) > 0);
        int rb = b / g, lb = b / (1 + g) + (b % (1 +g) > 0);
        if (ra >= la && rb >= lb)
            ans += 1 + min(r, ra + rb) - max(l, la + lb);
        l = r;
    }
    printf("%lld\n", ans);
    return 0;
}