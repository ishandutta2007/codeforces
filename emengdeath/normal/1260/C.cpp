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
        long long a, b, k;
        scanf("%lld %lld %lld", &a, &b, &k);
        if (a == b) {
            printf("OBEY\n");
            continue;
        }
        bool sig = 1;
        int v = __gcd(a, b);
        sig &= (max((b - v) / a - ((b - v) % a == 0) + 1, (a - v) / b - ((a - v) % b == 0) + 1) < k);
        sig?puts("OBEY"):puts("REBEL");
    }
    return 0;
}