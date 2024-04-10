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
int T, n;
int d[1000000];
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        d[0] = 0;
        for (int i = 1; i <= n; i ++) {
            int j = n / (n / i);
            d[++d[0]] = n / i;
            i = j;
        }
        printf("%d\n",d[0] + 1);
        printf("0 ");
        for (int i = d[0]; i >= 1; i --)
            printf("%d%c", d[i], " \n"[i == 1]);
    }
    return 0;
}