#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, x;
int a[100005], b[100005], win[100005], mo[100005];
int cnt[100005];
bool inv[100005] = {};

struct Cmp {
    inline bool operator()(const int &lhs, const int &rhs) const {
        if (win[lhs] != win[rhs]) return win[lhs] > win[rhs];
        return lhs < rhs;
    }
};

set<int, Cmp> q;

int main() {
    scanf("%d%d", &n, &x);
    forn(i, n) scanf("%d", a + i);
    forn(i, n) scanf("%d", b + i);
    LL sum = 0;
    forn(i, n) {
        mo[i] = a[i] % 100;
        win[i] = 0;
        if (mo[i] != 0) {
            win[i] = (100 - mo[i]) * b[i];
            sum += win[i];
        }
    }
    forn(i, n) {
        if (mo[i] != 0) {
            x += 100 - mo[i];
        }
        cnt[i] = x / 100;
    }
    int cur = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (i == 0) {
            cur += cnt[0];
        } else {
            cur += cnt[i] - cnt[i - 1];
        }
        if (mo[i] != 0) {
            q.insert(i);
        }
        while (cur && !q.empty()) {
            int ind = *q.begin();
            q.erase(q.begin());
            --cur;
            inv[ind] = true;
            sum -= win[ind];
        }
    }
    cout << sum << endl;
    forn(i, n) {
        if (mo[i] == 0) {
            printf("%d %d\n", a[i] / 100, 0);
        } else if (inv[i]) {
            printf("%d %d\n", a[i] / 100, mo[i]);
        } else {
            printf("%d %d\n", a[i] / 100 + 1, 0);
        }
    }
    return 0;
}