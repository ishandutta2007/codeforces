#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <unordered_map>
using namespace std;
int n;
int c, sum;
int main() {
    scanf("%d", &n);
    while (n --) {
        scanf("%d %d", &c, &sum);
        int x = sum / c, y = sum % c;
        printf("%lld\n", 1ll * x * x * (c - y) + 1ll * (x + 1) * ( x + 1) * y);
    }
    return 0;
}