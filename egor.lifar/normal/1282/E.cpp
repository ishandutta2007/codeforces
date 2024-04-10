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
const int MAXN = 100229;



int n;
int a[MAXN], b[MAXN], c[MAXN];
map<pair<int, int>, vector<int> > who;
set<pair<int, pair<int, int> > > g[MAXN];
pair<int, int> kek[MAXN];
int nxt[MAXN];


void add(int x, int y, int id) {
    if (x > y) {
        swap(x, y);
    }
    who[{x, y}].pb(id);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  //  read(FILENAME);
    int tt;
    cin >> tt;
    for (int it = 0; it < tt; it++) {
        cin >> n;
        who.clear();
        for (int i = 0; i < n - 2; i++) {
            g[i].clear();
        }
        for (int i = 0; i < n - 2; i++) {
            cin >> a[i] >> b[i] >> c[i];
            a[i]--, b[i]--, c[i]--;
            add(a[i], b[i], i);
            add(b[i], c[i], i);
            add(a[i], c[i], i);
        }
        for (auto x: who) {
            for (int i = 0; i < sz(x.second); i++) {
                for (int j = i + 1; j < sz(x.second); j++) {
                    g[x.second[i]].insert({x.second[j], x.first});
                    g[x.second[j]].insert({x.second[i], x.first});
                }
            }
        }
        set<pair<int, int> > st;
        for (int i = 0; i < n - 2; i++) {
            st.insert({sz(g[i]), i});
        }
        vector<int> order;
        while (!st.empty()) {
            auto x = *st.begin();
            st.erase(x);
            order.pb(x.second);
            for (auto y: g[x.second]) {
                st.erase({sz(g[y.first]), y.first});
                kek[x.second] = y.second;
                g[y.first].erase({x.second, y.second});
                st.insert({sz(g[y.first]), y.first});
            }
            g[x.second].clear();
        }
        reverse(all(order));
        for (auto x: order) {
            if (x == order[0]) {
                nxt[a[x]] = b[x];
                nxt[b[x]] = c[x];
                nxt[c[x]] = a[x];
            } else {
                int t = kek[x].first;
                int t1 = kek[x].second;
                if (nxt[t] != t1) {
                    swap(t, t1);
                }
                int val = a[x] ^ b[x] ^ c[x] ^ t ^ t1;
                nxt[t] = val;
                nxt[val] = t1;
            }
        }
        int cur = 0;
        for (int i = 0; i < n; i++) {
            cout << cur + 1 << ' ';
            cur = nxt[cur];;
        }
        cout << '\n';
        reverse(all(order));
        for (auto x: order) {
            cout << x + 1 << ' ';
        }
        cout << '\n';
    }
}