#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

vector<PII> st;
int n, m;
int a[200000], b[200000];

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) scanf("%d", a + i);
    REP(i, m) {
        int t, r;
        scanf("%d%d", &t, &r);
        while (!st.empty() && st.back().first <= r) {
            st.pop_back();
        }
        st.push_back(mp(r, t));
    }
    int lo = 0, hi = st[0].first - 1, place = hi;
    sort(a, a + hi + 1);
    REP(i, hi + 1) b[i] = a[i];
    REP(i, st.size()) {
        int cnt = st[i].first;
        if (i != (int)st.size() - 1) {
            cnt -= st[i + 1].first;
        }
        if (st[i].second == 1) {
            REP(times, cnt) {
                a[place] = b[hi];
                --place;
                --hi;
            }
        } else {
            REP(times, cnt) {
                a[place] = b[lo];
                --place;
                ++lo;
            }
        }
    }
    REP(i, n) printf("%d ", a[i]);
    printf("\n");
    return 0;
}