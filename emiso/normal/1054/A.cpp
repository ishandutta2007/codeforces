#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

int x, y, z, t1, t2, t3, esc, ele;

int main() {
    scanf("%d %d %d %d %d %d", &x, &y, &z, &t1, &t2, &t3);

    esc = abs(x - y) * t1;
    if(z == x) {
        ele = 2*t3 + abs(x - y) * t2 + t3;
    } else {
        ele = abs(x - z) * t2 + 2*t3 + abs(x - y) * t2 + t3;
    }

    if(ele <= esc) puts("YES");
    else puts("NO");
    return 0;
}