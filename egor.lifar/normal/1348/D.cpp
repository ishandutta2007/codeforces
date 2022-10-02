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


int n;


void solve() {
    cin >> n;
    //cnt -> 2 * cnt
    //val += cnt
    vector<int> ans;
    int cur = 1;
    int curcnt = 1;
    while (true) {
        if (cur + 2 * curcnt >= n) {
            ans.pb(n - cur - curcnt);
            break;
        }
        //cur + curcnt + t + curcnt + t <= n
        int val = (n - cur - curcnt - curcnt) / 2;
        chkmin(val, curcnt);
        ans.pb(val);
        curcnt += val;
        cur += curcnt;
    }
    cout << sz(ans) << '\n';
    for (auto x: ans) {
        cout << x << ' ';
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
}