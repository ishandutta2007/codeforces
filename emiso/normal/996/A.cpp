#include <bits/stdc++.h>

using namespace std;

int n, x;

int main() {
    scanf("%d", &n);

    x = (n / 100) + ((n % 100) / 20) + ((n % 20) / 10) + ((n % 10) / 5) + (n % 5);

    printf("%d\n", x);
    return 0;
}