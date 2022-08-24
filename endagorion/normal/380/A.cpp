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

//int a[100001];

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    vector<int> a;  
    int M;
    cin >> M;
    vector<i64> ls, cs;
    ls.pb(0);
    forn(i, M) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            if (a.size() < 100000) {
                a.pb(x);
            }
            cs.pb(-x);
            ls.pb(ls.back() + 1);
        } else {
            int l, c;
            cin >> l >> c;
            forn(i, c) {
                if (a.size() >= 100000) break;
                forn(j, l) {
                    if (a.size() >= 100000) break;  
                    a.pb(a[j]);
                }
            }
            cs.pb(l);
            ls.pb(ls.back() + 1LL * c * l);
        }
    }
  /*  forn(i, a.size()) {
        cout << a[i] << ' ';
    }
    cout << '\n';
    forn(i, ls.size()) {
        cout << ls[i] << ' ';
    }
    cout << '\n';
    forn(i, cs.size()) {
        cout << cs[i] << ' ';
    }
    cout << '\n';*/

    int N;
    cin >> N;
    forn(i, N) {
        i64 x;
        cin >> x;
        --x;
        int d = upper_bound(all(ls), x) - ls.begin() - 1;
//        cout << x << ' ' << d << ' ' << ls[d] << ' ' << cs[d] << '\n';
        if (cs[d] < 0) {
            cout << -cs[d] << ' ';
        } else {
            cout << a[(x - ls[d]) % cs[d]] << ' ';
        }
    }
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}