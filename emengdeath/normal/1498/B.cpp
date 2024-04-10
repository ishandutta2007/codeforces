#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int T;
int n, m;
int a[100001];
bool check(int h) {
    int r = n;
    int mm = m;
    while (r >= 1) {
        if (mm < a[r]) return 0;
        mm -= a[r];
        int v = a[r];
        r --;
        int hh = h - 2;
        if (hh < 0) continue;
        int vv = v;
        while (r >= 1) {
            if (vv >=a[r]) {
                vv -= a[r];
                r --;
            } else {
                if (hh) {
                    vv = v;
                    vv -= a[r];
                    r --;
                    hh --;
                } else {
                    break;
                }
            }
        }
    }
    return !r;
}
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i ++)
            scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        int l = 1, r = n, mid, s = n;
        while (l <= r) {
            if (check(mid = (l + r) / 2)) r = mid - 1, s = min(s, mid);
            else l = mid + 1;
        }
        printf("%d\n", s);
    }
    return 0;
}