#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
int s[100], d[100], c[100];

struct Cmp {
    inline bool operator()(const int &lhs, const int &rhs) const {
        if (d[lhs] != d[rhs]) {
            return d[lhs] < d[rhs];
        }
        return lhs < rhs;
    }
};

int exams[100];
set<int, Cmp> se;
int ans[100];

int main() {
    scanf("%d%d", &n, &m);
    forn(i, m) {
        scanf("%d%d%d", s + i, d + i, c + i);
        --s[i], --d[i];
    }
    memset(exams, -1, sizeof exams);
    forn(i, m) {
        if (exams[d[i]] != -1) {
            cout << -1 << endl;
            return 0;
        }
        exams[d[i]] = i;
    }
    forn(i, n) {
        forn(j, m) {
            if (s[j] == i) {
                se.insert(j);
            }
        }
        int ind = exams[i];
        if (ind != -1) {
            if (c[ind] != 0) {
                cout << -1 << endl;
                return 0;
            }
            ans[i] = m + 1;
            continue;
        }
        if (!se.empty()) {
            int v = *se.begin();
            --c[v];
            ans[i] = v + 1;
            if (c[v] == 0) {
                se.erase(se.begin());
            }
        }
    }
    forn(i, n) printf("%d ", ans[i]);
    puts("");
    return 0;
}