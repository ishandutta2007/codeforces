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
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<pii> a(N);
    forn(i, N) cin >> a[i].first, a[i].second = i;
    sort(all(a));
    pii f = mp(-1, -1), s = mp(-1, -1);
    forn(i, N) forn(j, i) {
        if (a[i].first == a[j].first) {
            if (f == mp(-1, -1)) f = mp(i, j);
            else if (s == mp(-1, -1)) s = mp(i, j);
        }
    }

    if (s == mp(-1, -1))  {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    forn(i, N) cout << a[i].second + 1 << ' ';
    cout << '\n';
    swap(a[f.first], a[f.second]);
    forn(i, N) cout << a[i].second + 1 << ' ';
    cout << '\n';
    swap(a[s.first], a[s.second]);
    forn(i, N) cout << a[i].second + 1 << ' ';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}