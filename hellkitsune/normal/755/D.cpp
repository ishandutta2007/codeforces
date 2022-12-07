#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;

int fen[2000005];

void fenAdd(int pos) {
    for (; pos < 2 * n + 3; pos |= pos + 1) {
        ++fen[pos];
    }
}

int fenGet(int pos) {
    int res = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
        res += fen[pos];
    }
    return res;
}

int main() {
    scanf("%d%d", &n, &k);
    if (n - k < k) {
        k = n - k;
    }
    int pos = 0;
    LL ans = 1;
    forn(i, n) {
        ans += fenGet(pos + k - 1) - fenGet(pos) + 1;
        fenAdd(pos);
        fenAdd(pos + n);
        pos += k;
        if (pos >= n) {
            pos -= n;
        }
        fenAdd(pos);
        fenAdd(pos + n);
        printf("%I64d ", ans);
    }
    puts("");
    return 0;
}