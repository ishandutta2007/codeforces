#include <bits/stdc++.h>
using namespace std;

int y, b, r;

int main() {
    scanf("%d %d %d", &y, &b, &r);
    int t = min({y, b - 1, r - 2});
    printf("%d\n", (t + 1) * 3);
    return 0;
}