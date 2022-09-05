#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, L, x, y, a[maxn];
unordered_set<int> S;

int main() {
    scanf("%d %d %d %d", &n, &L, &x, &y);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), S.insert(a[i]);
    }
    bool fx = 0, fy = 0;
    vector<int> cand;
    for (int i = 1; i <= n; i++) {
        if (S.count(a[i] + x)) fx = 1;
        if (S.count(a[i] + y)) fy = 1;
        cand.push_back(a[i] - x);
        cand.push_back(a[i] + x);
        cand.push_back(a[i] - y);
        cand.push_back(a[i] + y);
    }
    if (fx && fy) {
        puts("0");
    } else if (fx) {
        printf("1\n%d\n", y);
    } else if (fy) {
        printf("1\n%d\n", x);
    } else {
        bool flag = 0;
        int ans;
        for (int i : cand) if (i >= 0 && i <= L) {
            bool fx = S.count(i - x) || S.count(i + x);
            bool fy = S.count(i - y) || S.count(i + y);
            if (fx && fy) { flag = 1, ans = i; break; }
        }
        if (flag) {
            printf("1\n%d\n", ans);
        } else {
            printf("2\n%d %d\n", x, y);
        }
    }
    return 0;
}