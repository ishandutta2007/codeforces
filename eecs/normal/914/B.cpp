#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, a[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    int lst = n;
    while (lst) {
        int i = lst;
        while (i && a[i] == a[lst]) i--;
        if ((lst - i) % 2 == 1) puts("Conan"), exit(0);
        lst = i;
    }
    puts("Agasa");
    return 0;
}