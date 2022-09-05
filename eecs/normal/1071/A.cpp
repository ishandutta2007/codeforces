#include <bits/stdc++.h>
using namespace std;

long long a, b;
bool used[100010];

int main() {
    scanf("%lld %lld", &a, &b);
    auto chk = [&](int x) {
        memset(used, 0, sizeof(used));
        long long o = a;
        for (int i = x; i; i--) if (o >= i) {
            used[i] = 1, o -= i;
        }
        long long s = 0;
        for (int i = 1; i <= x; i++) {
            if (!used[i]) s += i;
        }
        return s <= b;
    };
    int l = 0, r = 100000, ans;
    while (l <= r) {
        int mid = (l + r) >> 1;
        chk(mid) ? l = (ans = mid) + 1 : r = mid - 1;
    }
    memset(used, 0, sizeof(used));
    vector<int> V;
    for (int i = ans; i; i--) if (a >= i) {
        V.push_back(i), a -= i, used[i] = 1;
    }
    printf("%d\n", V.size());
    for (int x : V) printf("%d ", x);
    putchar('\n'), V.clear();
    for (int i = 1; i <= ans; i++) {
        if (!used[i]) V.push_back(i);
    }
    printf("%d\n", V.size());
    for (int x : V) printf("%d ", x);
    putchar('\n');
    return 0;
}