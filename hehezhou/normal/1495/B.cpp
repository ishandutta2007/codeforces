#include <bits/stdc++.h>
using namespace std;
int n, p[100010];
int cnt;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", p + i);
    int lst = 1, tag = 1, _max = 1, ans = 0;
    for (int l = 1, r; ; l = r) {
        for (r = l; r < n && (p[r + 1] > p[r]) == tag; r++);
        int cur = r - l + 1;
        if (tag == 0) {
            if (cur == _max || lst == _max) ans = -1;
            if (cur > _max || lst > _max) _max = max(cur, lst), ans = 0;
            if (cur == lst && cur == _max && cur % 2 == 1 && ans != -1) ans = 1;
            if (r == n) break;
        }
        lst = cur;
        tag ^= 1;
    }
    cout << max(0, ans) << endl;
}