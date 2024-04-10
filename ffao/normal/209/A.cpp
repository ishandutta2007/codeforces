#include <stdio.h>

const int mod = 1000000007;
int n;

int main() {
    int a = 1;
    int b = 1;
    scanf("%d", &n);
    for (int i = 0; i < n+1; i++) {
        int t = b;
        b = (b+a)%mod;
        a = t;
    }
    printf("%d\n", b-2);
}