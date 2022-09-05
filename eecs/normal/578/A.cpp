#include <bits/stdc++.h>
using namespace std;

int a, b;

int main() {
    scanf("%d %d", &a, &b);
    int c = a + b;
    // x >= 2b, c % x == 0
    b *= 2;
    if (c < b) puts("-1");
    else printf("%.9f\n", 0.5 * c / (c / b));
    return 0;
}