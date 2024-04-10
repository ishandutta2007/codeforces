/*














 */
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>

using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left224
#define right right224
#define next next224
#define rank rank224
#define prev prev224
#define y1 y1224
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
const string FILENAME = "input";
const int MAXN = 200228;


int n, q;
int a[MAXN];
int last[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        last[i] = -1;
    }
    cin >> q;
    vector<pair<int, int> > g;
    for (int it = 0; it < q; it++) {
        int t;
        cin >> t;
        if (t == 1) {
            int id, val;
            cin >> id >> val;
            id--;
            a[id] = val;
            last[id] = it;
        } else {
            int x;
            cin >> x;
            g.pb({it, x});
        }
    }
    for (int i = sz(g) - 2; i >= 0; i--) {
        chkmax(g[i].second, g[i + 1].second);
    }
    for (int i = 0; i < n; i++) {
        int f = upper_bound(all(g), mp(last[i], 0)) - g.begin();
        if (f < sz(g)) {
            chkmax(a[i], g[f].second);
        }
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}