#include <bits/stdc++.h>
using namespace std;

const int maxn = 500010;
int n, K, c[maxn];

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }
    int l = 0, r = 1000000000, ans1, ans2;
    auto chk1 = [&](int x) {
        long long sum1 = 0, sum2 = 0;
        for (int i = 1; i <= n; i++) {
            if (c[i] < x) sum1 += x - c[i];
            else sum2 += c[i] - x;
        }
        return sum1 <= K && sum2 >= sum1;
    };
    while (l <= r) {
        int mid = (l + r) >> 1;
        chk1(mid) ? l = (ans1 = mid) + 1 : r = mid - 1;
    }
    auto chk2 = [&](int x) {
        long long sum1 = 0, sum2 = 0;
        for (int i = 1; i <= n; i++) {
            if (c[i] > x) sum1 += c[i] - x;
            else sum2 += x - c[i];
        }
        return sum1 <= K && sum2 >= sum1;
    };
    l = 0, r = 1000000000;
    while (l <= r) {
        int mid = (l + r) >> 1;
        chk2(mid) ? r = (ans2 = mid) - 1 : l = mid + 1;
    }
    printf("%d\n", max(0, ans2 - ans1));
    return 0;
}