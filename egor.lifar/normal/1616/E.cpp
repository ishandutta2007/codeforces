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
template<typename T1, typename T2> inline void chkmin(T1 &a, T2 b) {if (a > b) a = b;}
template<typename T1, typename T2> inline void chkmax(T1 &a, T2 b) {if (a < b) a = b;}
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define left left228
#define right right228
#define y1 y1228
#define mp make_pair
#define pb push_back
#define y2 y2228
#define rank rank228
using ll = long long;
using ld = long double; 
const string FILENAME = "input";



int n;
string s, t;
vector<int> where[26];


struct fenw {
    vector<int> d;
    void init(int n) {
        d.resize(n + 1, 0);
    }
    int get(int i) {
        int ans = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1) {
            ans += d[i];
        }
        return ans;
    }
    int get(int l, int r) {
        return get(r) - get(l - 1);
    }
    void inc(int i, int val) {
        for (; i < sz(d); i |= (i + 1)) {
            d[i] += val;
        }
    }
};


void solve() {
    cin >> n;
    cin >> s;
    cin >> t;
    for (int i = 0; i < 26; i++) {
        where[i].clear();
    }
    for (int i = 0; i < n; i++) {
        where[s[i] - 'a'].pb(i);
    } 
    for (int i = 0; i < 26; i++) {
        reverse(all(where[i]));
    }
    fenw kek, kek1;
    kek.init(n);
    kek1.init(n);
    for (int i = 0; i < n; i++) {
        kek1.inc(i, 1);
    }
    ll ans = 1e18;
    ll cur = 0;
    for (int i = 0; i < n; i++) {
        // if (n == 5) {
        //     cout << cur << endl;
        // }
        for (char c = t[i] - 1; c >= 'a'; c--) {
            if (!where[c - 'a'].empty()) {
                int pos = where[c - 'a'].back();
                int td = 0;//i - kek.get(pos);
                ll cur1 = cur + td;
                cur1 += kek1.get(0, pos) - 1;
                chkmin(ans, cur1);
            }
        }
        if (where[t[i] - 'a'].empty()) {
            break;
        }
        int d = where[t[i] - 'a'].back();
        where[t[i] - 'a'].pop_back();
        int td = 0; //i - kek.get(d);
        cur += kek1.get(0, d) - 1;
        cur += td;
        kek.inc(d, 1);
        kek1.inc(d, -1);
    }
    if (ans > 1e17) {
        ans = -1;
    }
    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}