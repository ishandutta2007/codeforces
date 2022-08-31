#include <iostream>
#include <vector>
#include <cassert>
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
#define rall(x) (x).rbegin(), (x).rend()
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

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N, K;
    cin >> N >> K;
    vi a(N);
    forn(i, N) cin >> a[i];
    vi ans;
    int best = 0;
    int r = 0;
    multiset<int> h;
    forn(i, N) {
        while (r < N && (h.empty() || *(--h.end()) - *h.begin() <= K)) {
            h.insert(a[r++]);
        }
        if (*(--h.end()) - *h.begin() > K) {
            --r;
            h.erase(h.find(a[r]));
        }
        if (r - i > best) {
            best = r - i;
            ans.clear();
        }
        if (r - i == best) {
            ans.pb(i + 1);
        }
        h.erase(h.find(a[i]));
    }
    cout << best << ' ' << ans.size() << '\n';
    forn(i, ans.size()) cout << ans[i] << ' ' << ans[i] + best - 1 << '\n';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}