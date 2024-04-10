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
const string FILENAME = "input";


int n, k;
int a[10228];


void solve() {
    cin >> n >> k;
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    if (sz(s) == 1 || n == k) {
        cout << n << '\n';
        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';
        return;
    }
    if (k == 1) {
        if (sz(s) > k) {
            cout << -1 << '\n';
        } else {
            cout << n << '\n';
            for (int i = 0; i < n; i++) {
                cout << a[i] << ' ';
            }
            cout << '\n';
        }
        return;
    }
    if (sz(s) > k) {
        cout << -1 << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (sz(s) == k) {
            break;
        }
        s.insert(i);
    }
    vector<int> res;
    for (int i = 0; i < n; i++) {
        while (true) {
            bool bad = false;
            for (int j = max(0, sz(res) - k + 1); j < sz(res); j++) {
                if (res[j] == a[i]) {
                    bad = true;
                }
            }
            if (bad) {
                for (auto x: s) {
                    bool bad = false;
                    for (int j = max(0, sz(res) - k + 1); j < sz(res); j++) {
                        if (res[j] == x) {
                            bad = true;
                        }
                    }
                    if (!bad) {
                        res.pb(x);
                        break;
                    }
                }
            } else {
                res.pb(a[i]);
                break;
            }
        }
    }
    cout << sz(res) << '\n';
    for (auto x: res) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
   	ios_base::sync_with_stdio(false);
   	cin.tie(0);
   	cout.tie(0);
   // read(FILENAME);
   	int t;
    cin >> t;
    while (t--) {
        solve();
    }
}