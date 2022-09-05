#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    int k = 0;
    while ((1 << k) <= n) k++;
    printf("%d\n", k);
    return 0;
}