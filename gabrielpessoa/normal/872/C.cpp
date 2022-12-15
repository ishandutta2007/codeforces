#include <bits/stdc++.h>
using namespace std;

int main() {
    int q, n;
    scanf("%d", &q);
    while(q--) {
        scanf("%d", &n);
        int total = 0;
        if(n > 15) {
            total = (n-12) / 4;
            n -= total * 4;
        }
        if(n == 15 || n == 13 || n == 10 || n == 8) {
            total += 2;
        } else if(n == 14 || n == 12) {
            total += 3;
        } else if(n == 4 || n == 6 || n == 9) {
            total += 1;
        } else {
            total = -1;
        }
        printf("%d\n", total);
    }
    return 0;
}