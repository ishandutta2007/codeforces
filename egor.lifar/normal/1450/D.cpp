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
const int MAXN = 300228;


int n;
int a[MAXN];
bool good[MAXN];
vector<int> where[MAXN];


void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        where[i].clear();
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        where[a[i]].pb(i);
    }
    for (int i = 1; i <= n; i++) {
        good[i] = false;
    }
    vector<int> st;
    for (int i = 0; i < n; i++) {
        st.pb(a[i]);
    }
    sort(all(st));
    good[1] = true;
    for (int i = 0; i < n; i++) {
        if (st[i] != i + 1) {
            good[1] = false;
        }
    }
    if (!where[1].empty()) {
        int l = 0;
        int r = n - 1;
        for (int t = 1; t <= n; t++) {
            if (where[t].empty()) {
                break;
            }
            good[r - l + 1] = true;
            if (sz(where[t]) == 1) {
                if (where[t][0] == l) {
                    l++;
                    continue;
                }
                if (where[t][0] == r) {
                    r--;
                    continue;
                }
                break;
            } else {
                break;
            }
        }
    }
    for (int t = 1; t <= n; t++) {
        cout << (int)good[t];
    }
    cout << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}