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
#define left left228
#define right right228
#define rank rank228
#define y1 y1228
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
using ld = long double;
// const int MAXMEM = 200 * 1000 * 1024;
// char _memory[MAXMEM];
// size_t _ptr = 0;
// void* operator new(size_t _x) { _ptr += _x; return _memory + _ptr - _x; }
// void operator delete (void*) noexcept {}
const string FILENAME = "input";
const int MAXN = 200229;


int n, t, a, b;
int type[MAXN];
int mom[MAXN];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    int tt;
    cin >> tt;
    for (int it = 0; it < tt; it++) {
        cin >> n >> t >> a >> b;
        ll cnts[2] = {0, 0};
        for (int i = 0; i < n; i++) {
            cin >> type[i];
            cnts[type[i]]++;
        }
        vector<pair<int, int> > st;
        vector<int> g;
        g.pb(t);
        int ans = 0;
        g.pb(0);
        for (int i = 0; i < n; i++) {
            cin >> mom[i];
            st.pb({mom[i], i});
            if (mom[i]) {
                g.pb(mom[i] - 1);
            }
            g.pb(mom[i]);
        }
        sort(all(st));
        sort(all(g));
        g.resize(distance(g.begin(), unique(all(g))));
        int uk = 0;
        ll sum = 0;
        int cnt = 0;
        for (auto x: g) {
            while (uk < sz(st) && st[uk].first <= x) {
                sum += (type[st[uk].second] ? b: a);
                cnts[type[st[uk].second]]--;
                cnt++;
                uk++;
            }
            if (sum <= x) {
                ll res = x - sum;
                ll p = min(cnts[0], res / a);
                ll p1 = min(cnts[1], (res - p * a) / b);
                chkmax(ans, cnt + p + p1);
            }
        }
        cout << ans << '\n';
    }
}