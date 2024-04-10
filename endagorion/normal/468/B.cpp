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

map<i64, int> s;

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    ios::sync_with_stdio(false);
    i64 N, A, B;
    cin >> N >> A >> B;
    vi64 a(N);
    i64 sum = 0;
    forn(i, N) {
        cin >> a[i];
        sum += a[i];
        s[a[i]] = i;
    }
    if (A == B) {
        bool ok = true;
        forn(i, N) {
            ok &= s.count(A - a[i]);
        }
        if (ok) {
            cout << "YES\n";
            forn(i, N) cout << "0 ";
            cout << '\n';
        } else {
            cout << "NO\n";
        }
        return 0;
    }
/*    int s1 = -1, s2;
    forn(i, N + 1) {
        if (i * A + (N - i) * B == sum) {
            s1 = i, s2 = N - i;
        }
    }
    if (s1 == -1) {
        cout << "NO\n";
        return 0;
    }*/

    vi ans(N, -1);
    bool ok = true;
    forn(i, N) {
        if (ans[i] == -1) {
            vi64 p;
            p.pb(a[i]);
            i64 t = A;
            i64 x = a[i];
            while (true) {
                if (s.count(t - x)) {
                    p.pb(t - x);
                    x = t - x;
                    t ^= A ^ B;
                } else {
                    break;
                }
            }
            reverse(all(p));
            t = B;
            x = a[i];
            while (true) {
                if (s.count(t - x)) {
                    p.pb(t - x);
                    x = t - x;
                    t ^= A ^ B;
                } else {
                    break;
                }
            }
//            forn(i, p.size()) cerr << p[i] << ' ';
//            cerr << '\n';
            if (p.size() % 2) {
                ok = false;
                break;
            }
            for (int j = 0; j < p.size(); j += 2) {
 //               if (!s.count(p[j])) continue;
                ans[s[p[j]]] = ans[s[p[j + 1]]] = (p[j] + p[j + 1] == B);
//                cerr << s[p[j]] << ' ' << s[p[j + 1]] << '\n';
//                s.erase(p[j]);
//                s.erase(p[j + 1]);
            }
//            forn(j, p.size()) s.erase(p[j]);
        }
    }
    if (ok) {
        cout << "YES\n";
        forn(i, N) cout << ans[i] << ' ';
        cout << '\n';
    } else {
        cout << "NO\n";
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}