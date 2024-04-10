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
const int MAXN = 2028;



int n;
string s[MAXN];
bitset<2001> b[MAXN];


bool check() {
    bitset<2001> cur, cur1;
    for (int i = 0; i < n; i++) {
        cur.reset();
        cur[i] = true;
        queue<int> q;
        q.push(i);
        int cnt = 0;
        while (!q.empty()) {
            int a = q.front();
            q.pop();
            cnt++;
            cur1 = b[a] ^ (b[a] & cur);
            cur |= cur1;
            int t = cur1.count();
            for (int j = 0; j < t; j++) {
                int g = cur1._Find_first();
                cur1[g] = 0;
                q.push(g);
            }
        }
        if (cnt != n) {
            return false;
        }
    }
    return true;
}


bool checks(int i) {
    bitset<2001> cur, cur1;
    cur.reset();
    cur[i] = true;
    queue<int> q;
    q.push(i);
    int cnt = 0;
    while (!q.empty()) {
        int a = q.front();
        q.pop();
        cnt++;
        cur1 = cur;
        cur |= b[a];
        cur1 ^= cur;
        int t = cur1.count();
        for (int j = 0; j < t; j++) {
            int g = cur1._Find_first();
            cur1[g] = 0;
            q.push(g);
        }
    }
    if (cnt != n) {
        return false;
    }
    return true;
}


int cntk[MAXN];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < n; j++) {
            b[i][j] = s[i][j] - '0';
            cntk[i] += b[i][j];
        }
    }
    if (n <= 6) {
        int opt = 1e9;
        int cnt = 0;
        for (int it = 0; it < (1 << n); it++) {
            vector<int> st;
            for (int i = 0; i < n; i++) {
                if (it & (1 << i)) {
                    st.pb(i);
                }
            }
            for (auto x: st) {
                for (int j = 0; j < n; j++) {
                    b[x][j].flip();
                    b[j][x].flip();
                }
            }
            int cnst = 1;
            for (int g = 0; g < sz(st); g++) {
                cnst *= g + 1;
            }
            if (check()) {
                if (opt > sz(st)) {
                    opt = sz(st);
                    cnt = cnst;
                } else {
                    if (opt == sz(st)) {
                        cnt+= cnst;
                    }
                }
            }
            for (auto x: st) {
                for (int j = 0; j < n; j++) {
                    b[x][j].flip();
                    b[j][x].flip();
                }
            }
        }
        if (opt > n) {
            cout << -1 << '\n';
            return 0;
        }   
        cout << opt << ' ' << cnt << '\n';
        return 0;
    }
    bool bad = false;
    for (int j = 0; j < n; j++) {
        if (cntk[j] == 0) {
            bad = true;
            break;
        }
    }
    for (int t = 0; t < n && !bad; t++) {
        if (!checks(t)) {
            bad = true;
            break;
        }
    }
    if (!bad) {
        cout << 0 << ' ' << 1 << '\n';
        return 0;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (b[i][j]) {
                cntk[i]--;
                cntk[j]++;
            } else {
                cntk[j]--;
                cntk[i]++;
            }
            b[i][j].flip();
            b[j][i].flip();
        }
        bool bad = false;
        for (int j = 0; j < n; j++) {
            if (cntk[j] == 0) {
                bad = true;
                break;
            }
        }
        if (!bad && checks(i) && checks((i + 1) % n)) {
            cnt++;
        }
        for (int j = 0; j < n; j++) {
            b[i][j].flip();
            b[j][i].flip();
            if (b[i][j]) {
                cntk[i]++;
                cntk[j]--;
            } else {
                cntk[j]++;
                cntk[i]--;
            }
        }           
    }
    cout << 1 << ' ' << cnt << '\n';
}