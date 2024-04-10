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
        int a, b;
        scanf("%d %d", &a, &b);
        bool sig = 1;
        sig &= ((a + b) % 3 == 0);
        int xy = (a + b) / 3;
        int x = a - xy, y = b - xy;
        if (x >= 0 && y >= 0 && sig)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}