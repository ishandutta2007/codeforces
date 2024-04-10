#include <bits/stdc++.h>

#define MN 1001000

using namespace std;

int n, ans, a[MN];

int main() {
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        ans += (a[i] == i);
    }

    if(ans >= n / 1000) puts("Petr");
    else puts("Um_nik");

    return 0;
}