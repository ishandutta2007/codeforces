#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a[100100], ans = 0, Max;

    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        scanf("%d", &a[i]);
    } sort(a, a + n);

    if(n <= 2) {
        printf("0\n");
        return 0;
    }

    Max = a[n-1];
    for(int i=0;i<n;i++) {
        if(a[i] > a[0] && a[i] < Max) ans++;
    }

    printf("%d\n", ans);

    return 0;
}