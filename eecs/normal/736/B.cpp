#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    bool flag = 1;
    for (int i = 2; i * i <= n; i++) {
        if (!(n % i)) { flag = 0; break; }
    }
    if (flag) puts("1"), exit(0);
    n -= 2, flag = 1;
    for (int i = 2; i * i <= n; i++) {
        if (!(n % i)) { flag = 0; break; }
    }
    if (flag) puts("2"), exit(0);
    n += 2;
    if (n % 2 == 0) puts("2");
    else puts("3");
    return 0;
}