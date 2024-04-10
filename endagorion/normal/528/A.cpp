#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
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
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

template<class T>
bool uin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool uax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int W, H, N;
    scanf("%d%d%d\n", &W, &H, &N);
    set<int> hc, vc;
    multiset<int> hl, vl;
    hc.insert(0); hc.insert(H); hl.insert(H);
    vc.insert(0); vc.insert(W); vl.insert(W);
    forn(i, N) {
        char c;
        int x;
        scanf("%c %d\n", &c, &x);
//        cerr << c << ' ' << x << '\n';
        if (c == 'H') {
            int l = *(--hc.lower_bound(x));
            int r = *hc.lower_bound(x);
            hl.erase(hl.find(r - l));
            hl.insert(x - l);
            hl.insert(r - x);
            hc.insert(x);
        } else {
            int l = *(--vc.lower_bound(x));
            int r = *vc.lower_bound(x);
            vl.erase(vl.find(r - l));
            vl.insert(x - l);
            vl.insert(r - x);
            vc.insert(x);
        }
        cout << 1LL * *vl.rbegin() * *hl.rbegin() << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}