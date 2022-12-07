#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[100];

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    int ans = 0;
    for (int beg = 0; beg < n; ) if (a[beg]) {
        int mx = 0;
        if (a[beg] & 1) {
            int end = beg + 1;
            int cur = 2;
            while (end < n && (a[end] & cur)) {
                ++end;
                cur = 3 - cur;
            }
            mx = end;
        }
        if (a[beg] & 2) {
            int end = beg + 1;
            int cur = 1;
            while (end < n && (a[end] & cur)) {
                ++end;
                cur = 3 - cur;
            }
            mx = max(mx, end);
        }
        ans += mx - beg;
        beg = mx + 1;
    } else {
        ++beg;
    }
    cout << n - ans << endl;
    return 0;
}