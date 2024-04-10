#include <bits/stdc++.h>
using namespace std;

int a[6];

int sqr(int x) { return x * x; }

int main() {
    for (int i = 0; i < 6; i++) scanf("%d", &a[i]);
    printf("%d\n", sqr(a[0] + a[1] + a[2]) - sqr(a[0]) - sqr(a[2]) - sqr(a[4]));
    return 0;
}