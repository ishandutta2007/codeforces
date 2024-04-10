/*














 */
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
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { x = (x > y ? y: x);}
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { x = (x < y ? y: x);}
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left224
#define right right224
#define rank rank224
#define y1 y1224
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
const string FILENAME = "input";
const int MAXN = 200208;


int n;
ll b[MAXN];
vector<ll> st[65];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME); 
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        ll bb = b[i];
        int cnt = 0;
        while (bb % 2 == 0) {
            bb /= 2;
            cnt++;
        }
        st[cnt].pb(b[i]);
    }
    int pos = -1;
    int t = 0;
    for (int i = 0; i < 64; i++) {
        if (t < sz(st[i])) {
            t = sz(st[i]);
            pos = i;
        }
    }
    vector<ll> sts;
    for (int i = 0; i < 64; i++) {
        if (pos != i) {
            for (auto x: st[i]) {
                sts.pb(x);
            }
        }
    }
    cout << sz(sts) << endl;
    for (auto y: sts) {
        cout << y << ' ';
    }
    cout << '\n';
    return 0; 
}