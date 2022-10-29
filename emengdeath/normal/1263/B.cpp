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
char s[10];
int n, T, ans;
vector<int>a[10000];
int b[10000];
void output(int x) {
    int v = 1000;
    for (int i = 1; i <= 4; i ++, v /= 10)
        printf("%d", x / v % 10);
    printf("\n");
}
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        for (int i = 0; i < 10000; i ++) a[i].clear();
        for (int i = 1; i <= n; i ++) {
            scanf("%s", s);
            int v = 0;
            for (int i= 0; i < 4; i ++)
                v = v * 10 + s[i] - '0';
            a[v].push_back(i);
        }
        int ans = 0;
        for (int i = 0; i < 10000;i ++)
            if (a[i].size() > 1) {
                ans += a[i].size() - 1;
                while (a[i].size() > 1) {
                    int v = 1;
                    for (int j = 0; j < 4 && a[i].size() > 1; v *= 10, j ++)
                        for (int k = 0; k < 10; k ++) {
                            int w = (i / v / 10 * 10 + k) * v + i % v;
                            if (!a[w].size()) {
                                a[w].push_back(a[i][0]);
                                swap(a[i][0], a[i][a[i].size() - 1]);
                                a[i].pop_back();
                                break;
                            }
                        }
                }
            }
        printf("%d\n", ans);
        for (int i = 0; i < 10000; i ++)
            for (auto u:a[i])
                b[u] = i;
        for (int i = 1; i <= n; i ++)
            output(b[i]);
    }
    return 0;
}