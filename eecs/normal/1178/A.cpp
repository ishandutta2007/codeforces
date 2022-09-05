#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int n, a[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int sum = a[1], all = 0, tmp = 1;
    for (int i = 2; i <= n; i++) {
        if (a[1] >= a[i] + a[i]) sum += a[i], tmp++;
        else all += a[i];
    }
    if (sum > all) {
        printf("%d\n1", tmp);
        for (int i = 2; i <= n; i++) {
            if (a[1] >= a[i] + a[i]) printf(" %d", i);
        }
    } else {
        printf("0\n");
    }
    return 0;
}