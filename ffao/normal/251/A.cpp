#include <stdio.h>

int n, d;
int points[100010];
long long int ans = 0;

int main() {
    scanf("%d %d", &n, &d);

    long long int a = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &points[i]);
        while (points[i] - points[a] > d) {
            if (i-a-1 >= 2) ans += (i-a-1)*(i-a-2)/2;
            a++;
        }
    }

    while (a != n) {
        if (n-a-1 >= 2) ans += (n-a-1)*(n-a-2)/2;
        a++; 
    }

    printf("%I64d", ans);
}