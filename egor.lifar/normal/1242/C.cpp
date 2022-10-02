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
#define next next228
#define rank rank228
#define prev prev228
#define y1 y1228
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
using ld = long double;
const string FILENAME = "input";
const int MAXN = 5028;


int k;
int n[17];
ll a[17][MAXN];
ll diff[17];
unordered_map<ll, pair<int, int> > who;
pair<int, int> g[17][MAXN];
bool used[17][MAXN];
vector<pair<int, int> > good[40000];
bool can[40000];
int pr[40000];
pair<ll, int> ans[17];


void restore(int id) {
    for (int i = 0; i < sz(good[id]); i++) {
        ans[good[id][i].first] = mp(a[good[id][i].first][good[id][i].second], 1 + good[id][(i + 1) % sz(good[id])].first);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    cin >> k;
    ll tot = 0;
    for (int i = 0; i < k; i++) {
        cin >> n[i];
        for (int j = 0; j < n[i]; j++) {
            cin >> a[i][j];
            tot += a[i][j];
            who[a[i][j]] = mp(i, j);
        }
    }
    if (tot % k != 0) {
        cout << "No\n";
        return 0;
    }
    tot /= k;
    for (int i = 0; i < k; i++) {
        ll sum = 0;
        for (int j = 0; j < n[i]; j++) {
            sum += a[i][j];
        }
        diff[i] = sum - tot;
    } 
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n[i]; j++) {
            ll val = -(diff[i] - a[i][j]);
            if (who.find(val) != who.end()) {
                g[i][j] = who[val];
            } else {
                g[i][j] = mp(-1, -1);
            }
        }
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n[i]; j++) {
            if (!used[i][j]) {
                int cur = i;
                int cur1 = j;
                bool bad = false;
                vector<pair<int, int> > t;
                while (true) {
                    t.pb({cur, cur1});
                    used[cur][cur1] = true;
                    auto x = g[cur][cur1];
                    if (x.first == -1) {
                        bad = true;
                        break;
                    }
                    cur = x.first;
                    cur1 = x.second;
                    if (used[cur][cur1]) {
                        break;
                    }
                }
                if (!bad) {
                    bool need = false;
                    vector<pair<int, int> > t1;
                    for (auto x: t) {
                        if (x.first == cur && x.second == cur1) {
                            need = true;
                        }
                        if (need) {
                            t1.pb(x);
                        }
                    }
                    if (!t1.empty()) {
                        int f = 0;
                        reverse(all(t1));
                        bool was = false;
                        for (auto x: t1) {
                            if (f & (1 << x.first)) {
                                was = true;
                                break;
                            }
                            f |= (1 << x.first);
                        }
                        if (!was) {
                            good[f] = t1;
                        }
                    }
                }
            }
        }
    }
    can[0] = true;
    for (int i = 1; i < (1 << k); i++) {
        vector<int> st;
        for (int j = 0; j < k; j++) {
            if (i & (1 << j)) {
                st.pb(j);
            }
        }
        for (int t = 1; t < (1 << sz(st)); t++) {
            int mask = 0;
            for (int f = 0; f < sz(st); f++) {
                if (t & (1 << f)) {
                    mask |= 1 << st[f];
                }
            }
            if (!good[mask].empty()) {
                if (can[i ^ mask]) {
                    can[i] = true;
                    pr[i] = mask;
                }
            }
        }
    }
    int fk = (1 << k) - 1;
    if (!can[fk]) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    while (fk) {
        int t = pr[fk];
        fk ^= t;
        restore(t);
    }
    for (int i = 0; i < k; i++) {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
}