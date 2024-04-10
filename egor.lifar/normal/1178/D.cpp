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



bool p[1002002];
bool can[1002][11001];
int pr[1002][11001];


void build(vector<int> degs) {
    int n = sz(degs);
    vector<pair<int, int> > st;
    set<pair<int, int> > s;
    for (int i = 0; i < n; i++) {
        s.insert({degs[i], i});
       // cout << degs[i] << endl;
    }
    while (!s.empty()) {
        auto x = *s.rbegin();
        s.erase(x);
        vector<pair<int, int> > sts;
        while (x.first) {
            //cout << x.first << endl;
            auto y = *s.rbegin();
            s.erase(y);
            st.pb({x.second, y.second});
            x.first--;
            y.first--;
            sts.pb(y);
        }
        for (auto x: sts) {
            if (!x.first) {
                continue;
            }
            s.insert(x);
        }
    }
    cout << sz(st) << '\n';
    for (auto x: st) {
        cout << x.first + 1 << ' ' << x.second + 1 << '\n';
    }
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    int n;
    cin >> n;
    vector<int> st;
    for (int i = 2; i <= 11000; i++) {
        if (!p[i]) {
            if (i < n && i <= 11) {
                st.pb(i);
            }
            if (11000 / i < i) {
                continue;
            }
            for (int j = i * i; j <= 11000; j += i) {
                p[j] = true;
            }
        }
    }
    can[0][0] = true;
    for (int i = 0; i < n; i++) {
        for (int cur = 0; cur <= 11000; cur++) {
            if (can[i][cur]) {
                for (auto x: st) {
                    can[i + 1][cur + x] = true;
                    pr[i + 1][cur + x] = x;
                }
            }
        }
    }
    for (int cur = 2; cur <= 11000; cur+= 2) {
        if (can[n][cur] && !p[cur / 2]) {
            //cout << cur << endl;
            int fk = cur;
            vector<int> degs;
            while (fk) {
                degs.pb(pr[n][fk]);
                fk -= pr[n][fk];
                n--;
            }
            build(degs);
            return 0;
        }
    }
    return 0;
}