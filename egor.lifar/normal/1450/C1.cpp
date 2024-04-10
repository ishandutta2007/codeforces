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
const int MAXN = 305;


int n;
string s[MAXN];
string s1[MAXN];


void solve() {
    cin >> n;
    int k = 0;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        s1[i] = s[i];
        for (auto y: s1[i]) {
            if (y != '.') {
                k++;
            }
        }
    }
    int cnts[3] = {0, 0, 0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] != '.') {
                cnts[(i + j) % 3]++;
            }
        }
    }
    int opt = 1e9;
    int t = -1;
    for (int j = 0; j < 3; j++) {
        if (cnts[j] < opt) {
            opt = cnts[j];
            t = j;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] != '.') {
                if ((i + j) % 3 == t) {
                    s[i][j] = s[i][j] ^ 'O' ^ 'X'; 
                    cnt++;
                }
            }
        }
    }
    assert(cnt <= k / 3);
    for (int i = 0; i < n; i++) {
        cout << s[i] << '\n';
    }
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
    return 0;
}