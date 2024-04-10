#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <deque>
#include <set>
#include <vector>
#include <unordered_map>
using namespace std;
int n;
const int N = 8e6 + 1;
int f[N];
int a[N];
int main() {
    int T = 1;
   // scanf("%d", &T);
    while (T --) {
        for (int i = 0; i < (1 << 22); i ++)f[i] = -1;
        scanf("%d", &n);
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            f[a[i]] = a[i];
        }
        for (int i = 0; i <= 21; i++)
            for (int j = 0; j < (1 << 22); j++)
                if (j & (1 << i) && f[j] == -1)
                    f[j] = f[j ^ (1 << i)];
        for (int i = 1; i <= n; i++)
            printf("%d%c",f[a[i] ^ ((1 << 22) - 1)], " \n"[i == n]);
    }
    return 0;
}