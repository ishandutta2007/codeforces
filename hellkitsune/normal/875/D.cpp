#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[200000];
int st[18][200000];
int lg[200001];

void stBuild() {
    int cur = 0;
    forn(i, n + 1) {
        if ((2 << cur) < i) {
            ++cur;
        }
        lg[i] = cur;
    }
    forn(i, n) st[0][i] = i;
    forn(i, 17) forn(j, n - (2 << i) + 1) {
        if (a[st[i][j]] >= a[st[i][j + (1 << i)]]) {
            st[i + 1][j] = st[i][j];
        } else {
            st[i + 1][j] = st[i][j + (1 << i)];
        }
    }
}

int stGet(int from, int to) {
    int l = lg[to - from + 1];
    if (a[st[l][from]] >= a[st[l][to - (1 << l) + 1]]) {
        return st[l][from];
    }
    return st[l][to - (1 << l) + 1];
//    int br = from;
//    for (int i = from + 1; i <= to; ++i) {
//        if (a[i] > a[br]) {
//            br = i;
//        }
//    }
//    if (br != res) {
//        cout << "!" << endl;
//    }
//    return res;
}

int b[30], ord[30];

inline bool cmp(const int &lhs, const int &rhs) {
    return b[lhs] < b[rhs];
}

int main() {
    if (0) {
        mt19937 mt(123);
        n = 200000;
        forn(i, n) a[i] = mt() % 1000000000 + 1;
    } else {
        scanf("%d", &n);
        forn(i, n) scanf("%d", a + i);
    }
    stBuild();
    forn(i, 30) b[i] = n;
    forn(i, 30) ord[i] = i;
    LL ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        forn(j, 30) if (a[i] & (1 << j)) {
            b[j] = i;
        }
        sort(ord, ord + 30, cmp);
        int val = a[i];
        int eq = 1;
        int ind = i;
        forn(jj, 30) {
            int j = ord[jj];
            if (b[j] == n) {
                break;
            }
            if ((val | a[b[j]]) == val) {
                continue;
            }
            assert(b[j] > ind);
            if (!eq) {
                int pos = stGet(ind, b[j] - 1);
                if (a[pos] == val) {
                    ans += pos - ind;
                } else {
                    ans += b[j] - ind;
                }
            }
            val |= a[b[j]];
            ind = b[j];
            eq = (val == a[ind]);
        }
        if (!eq) {
            int pos = stGet(ind, n - 1);
            if (a[pos] == val) {
                ans += pos - ind;
            } else {
                ans += n - ind;
            }
        }
    }
    cout << ans << endl;
    return 0;
}