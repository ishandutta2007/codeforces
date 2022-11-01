#include <bits/stdc++.h>

using namespace std;

int a[10], b[10];

int main() {
    int n, x;
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        scanf("%d", &x);
        a[x]++;
    }
    for(int i=0;i<n;i++) {
        scanf("%d", &x);
        b[x]++;
    }

    int ans = 0;
    for(int i=1;i<=5;i++) {
        if((a[i] + b[i]) % 2 == 1) {
            printf("-1\n");
            return 0;
        }

        ans += abs((a[i] - b[i]) / 2);
    }

    printf("%d\n", ans / 2);
    return 0;
}