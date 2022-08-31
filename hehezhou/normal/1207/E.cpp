#include <bits/stdc++.h>
using namespace std;
int main() {
    int ans = 0;
    printf("?");
    for(int i = 0; i < 100; i++) printf(" %d", i);
    puts("");
    fflush(stdout);
    scanf("%d", &ans);
    ans ^= ans & 127;
    printf("?");
    for(int i = 0; i < 100; i++) printf(" %d", (i << 7) + 101);
    puts("");
    fflush(stdout);
    int tmp;
    scanf("%d", &tmp);
    ans += (tmp & 127) ^ 101;
    return printf("! %d\n", ans), fflush(stdout), 0;
}