#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

LL fen[11][100001];
int n, k;
int a[100000];

void fenAdd(LL *fen, int pos, LL val) {
    for (; pos < n; pos |= pos + 1) {
        fen[pos] += val;
    }
}

LL fenGet(LL *fen, int pos) {
    LL ret = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
        ret += fen[pos];
    }
    return ret;
}

int main() {
    scanf("%d%d", &n, &k);
    REP(i, n) scanf("%d", a + i);
    if (k == 0) {
        cout << n << endl;
        return 0;
    }
    LL ans = 0;
    REP(i, n) {
        ans += fenGet(fen[k - 1], a[i] - 1);
        for (int j = k - 2; j >= 0; --j) {
            fenAdd(fen[j + 1], a[i], fenGet(fen[j], a[i] - 1));
        }
        fenAdd(fen[0], a[i], 1);
    }
    cout << ans << endl;
    return 0;
}