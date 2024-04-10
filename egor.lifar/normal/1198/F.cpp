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
const int MAXN = 100228;

int n;
int a[MAXN];
int pos[MAXN];
int fs[MAXN];


inline int gcd(int a, int b) {
    while (a) {
        b %= a;
        swap(a, b);
    }
    return b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    mt19937 as;
    as.seed(228);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            int g = 0;
            pos[i] = 1;
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    g = gcd(g, a[j]);
                    pos[j] = 2;
                }
            }
            if (g != 1) {
                cout << "NO\n";
                exit(0);
            }
            cout << "YES\n";
            for (int j = 0; j < n; j++) {
                cout << pos[j] << ' ';
            }
            cout << '\n';
            exit(0);
        }
    }
    if (n < 4) {
        cout << "NO\n";
        exit(0);
    }
    while (double(clock()) / CLOCKS_PER_SEC <= 0.45) {
        int id = as() % n;
        int pos1 = -1;
        vector<int> st;
        st.pb(id);
        memset(pos, 0, sizeof(pos));
        for (int i = 0; i < n; i++) {
            fs[i] = i;
        }
        shuffle(fs, fs + n, as);
        for (int i = 0; i < n; i++) {
            if (fs[i] != id && gcd(a[fs[i]], a[id]) == 1) {
                pos1 = fs[i];
                break;
            }
        }
        pos[id] = 1;
        if (pos1 == -1) {
            int cur = a[id];
            for (int i = 0; i < n; i++) {
                if (fs[i] != id) {
                    st.pb(fs[i]);
                    pos[fs[i]] = 1;
                    cur = gcd(cur, a[fs[i]]);
                    if (cur == 1) {
                        break;
                    }
                }
            }
            if (cur != 1) {
                continue;
            }
        } else {
            st.pb(pos1);
            pos[pos1] = 1;
        }
        int f = 0;
        for (int i = 0; i < n; i++) {
            if (!pos[i]) {
                pos[i] = 2;
                f = gcd(f, a[i]);
            }
        }
        if (f == 1) {
             cout << "YES\n";
            for (int j = 0; j < n; j++) {
                cout << pos[j] << ' ';
            }
            cout << '\n';
            exit(0);
        }
    }
    cout << "NO\n";
    exit(0);
    return 0;
}