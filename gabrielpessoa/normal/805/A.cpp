#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    if(b - a == 0 || b - a == 1) {
        printf("%d", b);
    } else if(b - a == 3 && a % 3 == 0) {
        printf("3");
    } else {
        printf("2");
    }
    return 0;
}