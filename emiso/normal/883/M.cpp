#include <bits/stdc++.h>

using namespace std;

int a, b, c, d;

int main() {
    scanf("%d %d %d %d", &a, &b, &c, &d);

    if(a == c) printf("%d\n", 2*abs(b - d) + 6);
    else if(b == d) printf("%d\n", 2*abs(a - c) + 6);
    else printf("%d\n", 2*abs(a - c) + 2*abs(b - d) + 4);
    return 0;
}