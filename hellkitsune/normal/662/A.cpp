#include <bits/stdc++.h>

using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define mp make_pair
#define pb push_back
typedef long long LL;
typedef pair<int, int> PII;

int n;
LL a[500001], b[500001];

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    REP(i, n) scanf("%I64d%I64d", a + i, b + i);
    REP(i, n) b[i] ^= a[i];
    LL tot = 0;
    REP(i, n) tot ^= a[i];
    int cnt = 0;
    REP(i, 60) {
        LL x = 1ll << i;
        int pos = -1;
        for (int j = cnt; j < n; ++j) if (b[j] & x) {
            pos = j;
            break;
        }
        if (pos == -1) continue;
        swap(b[pos], b[cnt]);
        for (int j = cnt + 1; j < n; ++j) if (b[j] & x) {
            b[j] ^= b[cnt];
        }

        if (tot & x) {
            tot ^= b[cnt];
        }
        ++cnt;
    }
    if (tot != 0) {
        cout << "1/1" << endl;
    } else {
        cout << (1ll << cnt) - 1 << "/" << (1ll << cnt) << endl;
    }
    return 0;
}