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




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        map<pair<pair<int, int>, pair<int, int> >, bool> was;
        int curx = 0;
        int cury = 0;
        int ans = 0;
        for (auto x: s) {
            int dx, dy;
            if (x == 'E') {
                dx = 1;
                dy = 0;
            } else if (x == 'W') {
                dx = -1;
                dy = 0;
            } else if (x == 'N') {
                dx = 0;
                dy = 1;
            } else if (x == 'S') {
                dx = 0;
                dy = -1;
            }
            int cx = curx + dx;
            int cy = cury + dy;
            if (was.find(mp(mp(curx, cury), mp(cx, cy))) != was.end()) {
                ans++;
            } else {
                ans += 5;
                was[mp(mp(curx, cury), mp(cx, cy))] = true;
                was[mp(mp(cx, cy), mp(curx, cury))] = true;
            }
            curx = cx;
            cury = cy;
        }
        cout << ans << '\n';
    }
}