#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const LL MX = LL(1e18);
const int LEN = 4686825;

int len = 0;
int v[LEN][9];
int cur[10];

void gen(LL x, int dig) {
    forn(i, 9) v[len][i] = cur[i];
    ++len;
    for (int i = dig; i <= 9; ++i) {
        LL nx = x * 10 + i;
        if (nx <= MX) {
            ++cur[i - 1];
            gen(nx, i);
            --cur[i - 1];
        }
    }
}

LL from, to;
int f[19];
int r[19];

int main() {
    if (0) {
        mt19937_64 mt(123);
        from = mt() % LL(0.89e18) + LL(0.1e18);
        to = mt() % LL(0.89e18) + LL(0.1e18);
        if (from > to) {
            swap(from, to);
        }
        cerr << from << ' ' << to << endl;
    } else {
        cin >> from >> to;
    }
    for (int i = 1; i <= 9; ++i) {
        memset(cur, 0, sizeof cur);
        cur[i - 1] = 1;
        gen(i, i);
    }
    assert(len == LEN);

    forn(i, 19) {
        f[18 - i] = from % 10;
        from /= 10;
    }
    assert(from == 0);

    int ans = 0;
    forn(_, len) {
        cur[0] = 19;
        forn(i, 9) {
            cur[i + 1] = v[_][i];
            cur[0] -= v[_][i];
        }
        bool more = false;
        forn(i, 19) {
            bool done = false;
            for (int j = f[i]; j <= 9; ++j) {
                if (cur[j] > 0) {
                    done = true;
                    --cur[j];
                    r[i] = j;
                    if (j > f[i]) {
                        more = true;
                    }
                    break;
                }
            }
            if (!done) {
                while (true) {
                    --i;
                    ++cur[r[i]];
                    bool done = false;
                    for (int j = r[i] + 1; j <= 9; ++j) if (cur[j]) {
                        r[i] = j;
                        --cur[j];
                        done = true;
                        break;
                    }
                    if (done) {
                        break;
                    }
                }
                more = true;
            }
            if (more) {
                int k = 0;
                for (int j = i + 1; j < 19; ++j) {
                    while (cur[k] == 0) ++k;
                    r[j] = k;
                    --cur[k];
                }
                break;
            }
        }
        unsigned long long val = 0;
        forn(i, 19) val = 10 * val + r[i];
        if (val <= (unsigned long long) to) {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}