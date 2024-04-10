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
const int Mod = 1000000009;


int sum(int a, int b) {
    return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(int a, int b) {
    return ((ll)a * b) % Mod;
}


int powm(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}


int inv(int a) {
    return powm(a, Mod - 2);
}



int n;



int myask(vector<int> a, vector<int> b) {
    if (a.empty() || b.empty()) {
        return 0;
    }
    cout << "? " << ' ' << sz(a) << ' ' << sz(b) << endl;
    for (auto x: a) {
        cout << x + 1 << ' ';
    }
    cout << endl;
    for (auto x: b) {
        cout << x + 1 << ' ';
    }
    cout << endl;
    int res;
    cin >> res;
    return res;
}



void solve() {
    cin >> n;
    vector<int> st;
    st.pb(0);
    int target = 0;
    int re = -1;
    for (int i = 1; i < n; i++) {
        target = myask(st, vector<int>{i});
        if (target != 0) {
            re = i;
            break;
        }
        st.pb(i);
    }   
    assert(re != -1);
    int l = 0;
    int r = sz(st) - 1;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        vector<int> keker;
        for (int k = mid; k <= sz(st) - 1; k++) {
            keker.pb(st[k]);
        }
        if (myask(keker, vector<int>{re}) != 0) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    vector<int> res;
    for (int i = 0; i < l; i++) {
        res.pb(st[i]);
    }
    for (int i = l + 1; i < sz(st); i++) {
        res.pb(st[i]);
    }
    for (int i = re + 1; i < n; i++) {
        if (myask(vector<int>{st[l], i}, vector<int>{re}) == target) {
            res.pb(i);
        }
    }
    cout << "! " << sz(res);
    for (auto x: res) {
        cout << ' ' << x + 1;
    }
    cout << endl;
}


int main() {
    ios_base::sync_with_stdio(false);;
 //   read(FILENAME);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}