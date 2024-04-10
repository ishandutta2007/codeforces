#include <bits/stdc++.h>
using namespace std;

int x, y, z, t1, t2, t3;

int main() {
    scanf("%d %d %d %d %d %d", &x, &y, &z, &t1, &t2, &t3);
    int foo = abs(x - y) * t1;
    int bar = abs(x - z) * t2 + t3 + abs(x - y) * t2 + t3 + t3;
    if (foo < bar) puts("NO");
    else puts("YES");
    return 0;
}