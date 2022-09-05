#include <bits/stdc++.h>
using namespace std;

int T, n;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int mx = 0;
        while (n) mx = max(mx, n % 10), n /= 10;
        printf("%d\n", mx);
    }   
    return 0;
}