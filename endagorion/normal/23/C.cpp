#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fornn(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

typedef long long i64;
typedef pair<i64, i64> pi64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

bool maj(pii a, pii b) {
    return a.first >= b.first && a.second >= b.second;
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int T;
    scanf("%d", &T);
    forn(t, T) {
        int N;
        scanf("%d", &N);
        N = 2 * N - 1;
        vector< pair<pii, int> > a(N);
        forn(i, N) {
            pii x;
            scanf("%d%d", &x.first, &x.second);
            a[i] = mp(x, i);
        }
        sort(all(a));
        vector< pair<pii, int> > ans, st;
        forn(i, N) {
            if (!st.empty() && maj(a[i].first, st.back().first)) {
                ans.pb(a[i]);
                st.pop_back();
            } else {
                st.pb(a[i]);
            }
        }
        forn(i, st.size() / 2 + 1) {
            ans.pb(st[i * 2]);
        }
        sort(all(ans));
        printf("YES\n");
        forn(i, ans.size()) {
            printf("%d ", ans[i].second + 1);
        }
        printf("\n");
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}