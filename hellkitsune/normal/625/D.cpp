#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

char s[100005];
int a[100005], z[100005];
int b[100005];
int n;

void solve(int from) {
    if (from > n) return;
    bool ok = true;
    for (int i = from, j = n; i <= j; ++i, --j) {
        int need = a[i - 1] * 10 + a[i];
        if (i == j) {
            if (need % 2 == 1 || need > 18) {
                ok = false;
                break;
            }
            b[i] = need / 2;
            break;
        }
        int cur = -1;
        if (a[j] == need || a[j] + 1 == need || a[j] + 2 == need) cur = a[j];
        if (10 + a[j] == need || 11 + a[j] == need || 12 + a[j] == need) cur = 10 + a[j];
        if (cur == -1 || cur > 18) {
            ok = false;
            break;
        }
        a[i] = need - cur;
        if (cur > 9) {
            int k = j - 1;
            while (k > i && a[k] == 0) a[k] = 9, --k;
            if (a[k] == 0) {
                ok = false;
                break;
            }
            --a[k];
        }
        if (a[i] > 1 || (a[i] > 0 && i + 1 == j) || (cur == 0 && i == from)) {
            ok = false;
            break;
        }
        b[i] = min(cur, 9);
        b[j] = cur - min(cur, 9);
    }
    if (ok) {
        int st = 0;
        while (b[st] == 0) ++st;
        for (int i = st; i <= n; ++i) printf("%d", b[i]);
        printf("\n");
        exit(0);
    } else {
        memset(b, 0, sizeof b);
    }
}

int main() {
    scanf("%s", s);
    n = strlen(s);
    REP(i, n) a[i + 1] = s[i] - '0';
    a[0] = 0;
    memcpy(z, a, sizeof z);
    solve(1);
    memcpy(a, z, sizeof z);
    solve(2);
    cout << 0 << endl;
    return 0;
}