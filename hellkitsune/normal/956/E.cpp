#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

bitset<10001> bs, cur, tot, wone;
bool was[10001];
int n, l, r;
int a[10000], b[10000], c[10000], cnt = 0;
int sum = 0;

bool firstTime = true;
void nextStep() {
    firstTime = false;
    --cnt;
    tot |= tot << c[cnt];
    cur |= cur << c[cnt];
    sum = min(10001, sum + c[cnt]);
    for (int i = sum - 1; i >= 0; --i) {
        if (cur.test(i)) {
            if (!was[i]) {
                was[i] = true;
                wone |= bs << i;
            }
        }
    }
}

int main() {
    if (0) {
        mt19937 mt(123);
        n = 10000;
        l = 1000;
        r = 10000;
        forn(i, n) a[i] = mt() % 10000;
        forn(i, n) b[i] = mt() % 2;
    } else {
        scanf("%d%d%d", &n, &l, &r);
        forn(i, n) scanf("%d", a + i);
        forn(i, n) scanf("%d", b + i);
    }

    bs.set(0);
    cur.set(0);
    forn(i, n) if (b[i] == 0) {
        bs |= bs << a[i];
    } else {
        c[cnt++] = a[i];
    }
    sort(c, c + cnt);
    int ans = 0;
    tot = bs;
    wone = bs;
    while (true) {
        int st = l;
        while (st <= r && !tot.test(st)) {
            ++st;
        }
        if (st > r) {
            if (cnt == 0) break;
            nextStep();
            continue;
        }
        int i = 0;
        while (i < cnt && st + c[i] <= r) {
            st += c[i];
            ++i;
        }
        if (i < cnt) ++i;
        ans = max(ans, i);

        if (!firstTime) {
            st = l;
            while (st <= r && !wone.test(st)) {
                ++st;
            }
            if (st > r) {
                if (cnt == 0) break;
                nextStep();
                continue;
            }
            int i = 0;
            while (i < cnt && st + c[i] <= r) {
                st += c[i];
                ++i;
            }
            ++i;
            ans = max(ans, i);
        }

        if (cnt == 0) break;
        nextStep();
    }
    cout << ans << endl;
    return 0;
}