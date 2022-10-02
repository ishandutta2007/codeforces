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
const int MAXN = 50228;



int n;
int a[MAXN];
int x;
ll pref[MAXN];
int dp[MAXN];


struct fenw {
    vector<int> d;
    void init(int n) {
        d.resize(n + 1);
        for (auto &x: d) {
            x = -1e9;
        }
    }
    int get(int i) {
        int ans = -1e9;
        for (; i >= 0; i = (i & (i + 1)) - 1) {
            chkmax(ans, d[i]);
        }
        return ans;
    }
    void inc(int i, int val) {
        for (; i < sz(d); i |= (i + 1)) {
            chkmax(d[i], val);
        }
    }
};



int fg[MAXN];


void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }    
    cin >> x;
    pref[0] = 0;
    for (int i = 1; i <= n; i++) {
        pref[i] = a[i] - x;
        if (i) {
            pref[i] += pref[i - 1];
        }
    }
    fenw kek;
    kek.init(n + 1);
    dp[0] = 0;
    kek.inc(n, 0);
    vector<int> st;
    fg[0] = -1;
    for (int i = 1; i <= n; i++) {
        int lastbad = -1;
        for (int j = sz(st) - 1; j >= 0; j--) {
            if (pref[st[j]] > pref[i]) {
                lastbad = st[j];
                break;
            }
        }
        fg[i] = max(lastbad, fg[i - 1]);
        dp[i] = 1;
        chkmax(dp[i], dp[i - 1]);
        if (i >= 2) {
            chkmax(dp[i], dp[i - 2] + 1);
        }
        chkmax(dp[i], i + kek.get(n - (fg[i] + 1)));
        //cout << dp[i] << ' ' << fg[i] << endl;
        kek.inc(n - i, (i >= 1 ? dp[i - 1]: 0) - i);
        while (!st.empty() && pref[st.back()] <= pref[i - 1]) {
            st.pop_back();
        }
        st.pb(i - 1);
    }
    cout << dp[n] << '\n';
  //  exit(0);
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