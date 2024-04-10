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
// const int MAXMEM = 200 * 1000 * 1024;
// char _memory[MAXMEM];
// size_t _ptr = 0;
// void* operator new(size_t _x) { _ptr += _x; return _memory + _ptr - _x; }
// void operator delete (void*) noexcept {}
const string FILENAME = "input";




int n, k;
string s;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    cin >> n >> k;
    cin >> s;
    int maxcnt = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            maxcnt += cnt;
        }
        if (s[i] == 'R') {
            cnt++;
        }
    }
    if (maxcnt < k) {
        cout << -1 << '\n';
        return 0;
    }
    vector<vector<int> > ans;
    while (k) {
        vector<int> st;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == 'R' && s[i + 1] == 'L') {
                st.pb(i);
            }
        }
        int t = maxcnt - k + 1;
        if (t == 1) {
            for (int i = n - 2; i >= 0; i--) {
                int t = i;
                while (t + 1 < n && s[t] == 'R' && s[t + 1] == 'L') {
                    ans.pb(vector<int>{t + 1});
                    swap(s[t], s[t + 1]);
                    t++;
                    maxcnt--;
                    k--;
                    if (k == 0) {
                        break;
                    }
                }
                if (k == 0) {
                    break;
                }
            }
            break;
        }
        k--;
        chkmin(t, sz(st));
        vector<int> g;
        for (int i = 0; i < t; i++) {
            g.pb(st[i] + 1);
            swap(s[st[i]], s[st[i] + 1]);
        }
        ans.pb(g);
        maxcnt -= t;
        //maxcnt - val >= k - 1
        //maxcnt - k + 1 >= val;
        //maxcnt - val >= k - 1;
    }
    if (maxcnt != 0) {
        cout << -1 << '\n';
        return 0;
    }
    for (int i = 0; i < sz(ans); i++) {
        cout << sz(ans[i]);
        for (auto x: ans[i]) {
            cout << ' ' << x;
        }
        cout << '\n';
    }
    return 0;   
}