#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int N = 200005;

int n;
int b[N], c[N], a[N];
int cnt[30] = {};

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", b + i);
    forn(i, n) scanf("%d", c + i);
    LL sum = 0;
    forn(i, n) {
        sum += b[i];
        sum += c[i];
    }
    if (sum % (2 * n) != 0) {
        cout << -1 << endl;
        return 0;
    }
    sum /= 2 * n;
    forn(i, n) {
        LL cur = b[i];
        cur += c[i];
        cur -= sum;
        if (cur < 0 || (cur % n != 0)) {
            cout << -1 << endl;
            return 0;
        }
        a[i] = cur / n;
    }
    forn(i, n) {
        forn(j, 30) if (a[i] & (1 << j)) {
            ++cnt[j];
        }
    }
    forn(i, n) {
        LL bb = 0, cc = 0;
        forn(j, 30) if (a[i] & (1 << j)) {
            bb += (LL)cnt[j] << j;
            cc += (LL)n << j;
        } else {
            cc += (LL)cnt[j] << j;
        }
        if (bb != b[i] || cc != c[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    forn(i, n) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}