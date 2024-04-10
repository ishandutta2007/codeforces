#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int s, m, h, day, date, month, T;
int num[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
ll pre[200000];

bool match(int x, int y) { return !~x || x == y; }

int main() {
    scanf("%d %d %d %d %d %d", &s, &m, &h, &day, &date, &month);
    scanf("%d", &T);
    if (~day) day--;
    auto chk = [&](int y) {
        return !(y % 4) && (y % 100 || !(y % 400));
    };
    for (int i = 1971; i < 200000; i++) {
        pre[i] = pre[i - 1] + (365 + chk(i - 1)) * 24 * 3600;
    }
    while (T--) {
        ll n; scanf("%lld", &n);
        int l = 1970, r = 199999, y;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (pre[mid] <= n) l = (y = mid) + 1;
            else r = mid - 1;
        }
        auto solve = [&](int y) {
            if (!(~month || ~date || ~day || num[month] + (month == 2 && chk(y)) >= date)) return 0;
            int cday = (3 + pre[y] / 24 / 3600) % 7, cdate = 1, cmonth = 1;
            ll cur = pre[y];
            while (cmonth <= 12) {
                if (cur + 24 * 3600 - 1 > n && match(month, cmonth) && match(day, cday) + match(date, cdate) >= (~day && ~date ? 1 : 2)) {
                    for (int i = 0; i < 24; i++) if (match(h, i)) {
                        for (int j = 0; j < 60; j++) if (match(m, j)) {
                            for (int k = 0; k < 60; k++) if (match(s, k)) {
                                ll _cur = cur + i * 3600 + j * 60 + k;
                                if (_cur > n) { printf("%lld\n", _cur); return 1; }
                            }
                        }
                    }
                }
                ++cday %= 7, cdate++, cur += 24 * 3600;
                if (cdate > num[cmonth] + (cmonth == 2 && chk(y))) cdate = 1, cmonth++;
            }
            return 0;
        };
        while (!solve(y++));
    }
    return 0;
}