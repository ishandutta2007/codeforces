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



int n;
string s, t;
mt19937 as;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  //  read(FILENAME);
    int tt;
    cin >> tt;
    for (int it = 0; it < tt; it++) {
        cin >> s >> t;
        n = sz(s);
        map<string, int> cnt;
        for (int i = 0; i < n; i+= 2) {
            string a;
            a += s[i];
            a += s[i + 1];
            if (a[0] > a[1]) {
                swap(a[0], a[1]);
            }
            cnt[a]++;
        }
        for (int i = 0; i < n; i+= 2) {
            string a;
            a += t[i];
            a += t[i + 1];
            if (a[0] > a[1]) {
                swap(a[0], a[1]);
            }
            cnt[a]--;
        }
        bool bad = false;
        for (auto x: cnt) {
            if (x.second != 0) {
                bad = true;
            }
        }
        if (bad) {
            cout << -1 << '\n';
            continue;
        }
        while (true) {
            int start = as() % (n / 2 + 1);
            vector<int> ord;
            if (start != 0) {
                ord.pb(start - 1);
            }
            string cur = s, target = t;
            reverse(cur.begin(), cur.begin() + 2 * start);
            int its = 0;
            bool bad = false;
            while (sz(cur) > 0) {
                int id = sz(target) - 2;
                vector<int> kek;
                for (int i = sz(cur) - 2; i >= 0; i -= 2) {
                    kek.pb(i);
                }
                shuffle(kek.begin() + 1, kek.end(), as);
                bool ok = false;
                for (auto i: kek) {
                    if (cur[i] == target[id] && cur[i + 1] == target[id + 1]) {
                        if (i + 2 != sz(cur)) {
                            ord.pb(i / 2);
                            reverse(cur.begin(), cur.begin() + i + 2);
                            ord.pb(id / 2);
                            reverse(all(cur));
                        }
                        ok = true;
                        break;
                    }
                }
                if (!ok) {
                    vector<int> kek;
                    for (int i = 0; i < sz(cur); i += 2) {
                        kek.pb(i);
                    }
                    shuffle(kek.begin(), kek.end(), as);
                    for (auto i: kek) {
                        if (cur[i] == target[id + 1] && cur[i + 1] == target[id]) {
                            ord.pb(i / 2);
                            reverse(cur.begin(), cur.begin() + i + 2);
                            ord.pb(0);
                            reverse(cur.begin(), cur.begin() + 2);
                            ord.pb(id / 2);
                            reverse(cur.begin(), cur.end());
                            break;
                        }
                    }
                }
                if (sz(ord) > n + 1) {
                    bad = true;
                    break;
                }
                for (int it = 0; it < 2; it++) {
                    cur.pop_back(); 
                    target.pop_back();
                }
            }
            if (bad) {
                continue;
            } else {
                cout << sz(ord) << '\n';
                for (auto x: ord) {
                    cout << 2 * (x + 1) << ' ';
                }
                cout << '\n';
                break;
            }
        }
    }
    return 0;
}