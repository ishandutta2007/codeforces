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
const int MAXN = 200228;



int n;
string a, b;


void solve() {
    cin >> n;
    cin >> a;
    cin >> b;
    int cntp = 0;
    int cntp1 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '1') {
            cntp++;
        }
        if (b[i] == '1') {
            cntp1++;
        }
    }
    int cnts = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            cnts++;
        }
    }
    if (cnts == 0) {
        cout << 0 << '\n';
        return;
    }
    if (cntp == 0 || cntp1 == 0) {
        cout << -1 << '\n';
        return;
    }
    int cnt = 0, cnt1 = 0;
    int cnte0 = 0, cnte1 = 0;
    int cntd0 = 0, cntd1 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            if (a[i] == '0') {
                cnte0++;
            }  else {
                cnte1++;
            }
            cnt++;
        } else {
            if (a[i] == '0') {
                cntd0++;
            }  else {
                cntd1++;
            }
            cnt1++;
        }
    }
    int res = 1e9;
    if (cnt % 2 == 1) {
        if (cnte1 == cnte0 + 1) {
            chkmin(res, cnt);
        }
    }
    if (cnt1 % 2 == 0) {
        if (cntd1 == cntd0) {
            chkmin(res, cnt1);
        }
    }
    if (res > 1e8) {
        res = -1;
    }
    cout << res << '\n';
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