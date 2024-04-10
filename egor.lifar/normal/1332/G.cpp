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
const int MAXN = 200228;


int n, q;
int a[MAXN];
int ss = 1;
int lastl[MAXN];
int lastr[MAXN];
vector<int> res[MAXN];
int nxt[MAXN];
int b[MAXN],c[MAXN],t[MAXN],sum[MAXN];
int st1[MAXN], st2[MAXN];
int ans[MAXN][4];
set<int> s;


bool comp1(int u, int v) {
    return a[u] < a[v];
}

bool comp2(int u, int v) {
    return a[u] > a[v];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    cin >> n >> q;
    while (ss < n) {
        ss <<= 1;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ps = -1, ps1 = -1;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] > a[i + 1]) {
            ps = i;
        } else if (a[i] < a[i + 1]) {
            ps1 = i;
        }
        lastl[i] = ps;
        lastr[i] = ps1;
    }
    int p1 = 0, p2 = 0;
    int r1 = 0, r2 = 0;
    s.insert(n);
    for (int i = n - 1; i >= 0; i--) {
        while (p1) {
            int u = st1[p1];
            if (a[u] > a[i]) {
                t[u]--;
                if (!t[u]) {
                    s.insert(u);
                }
                p1--;
                r1 = 0;
            } else{
                break;
            }
        }
        while (p2) {
            int u = st2[p2];
            if (a[u] < a[i]) {
                t[u]--;
                if (!t[u]) {
                    s.insert(u);
                }
                p2--;
                r2 = 0;
            } else{
                break;
            }
        }
        int s1 = lower_bound(st1 + 1, st1 + p1 + 1, i, comp1) - st1 - 1;
        int s2 = lower_bound(st2 + 1, st2 + p2 + 1, i, comp2) - st2 - 1;
        if (s1 && s2) {
            c[i] = *s.lower_bound(max(st1[s1], st2[s2]));
            if (c[i] < n){
                int u = lower_bound(st1 + 1, st1 + p1 + 1, c[i], greater<int>()) - st1;
                int v = lower_bound(st2 + 1, st2 + p2 + 1, c[i], greater<int>()) - st2;
                ans[i][0] = i;
                ans[i][1] = min(st1[u], st2[v]);
                ans[i][2] = max(st1[u], st2[v]);
                ans[i][3] = c[i];
            }
        } else {
            c[i] = n;
        }
        st1[++p1] = i;
        st2[++p2] = i;
        r1++;
        r2++;
        t[i] += 2;
        if (i + 1 < n && c[i] > c[i + 1]) {
            c[i] = c[i + 1];
            for (int j = 0; j < 4; j++) {
                ans[i][j] = ans[i + 1][j];
            }
        }
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (lastl[l] == -1 || lastr[l] == -1) {
            cout << 0 << '\n';
            continue;
        } 
        if (max(lastl[l], lastr[l]) > r - 1) {
            cout << 0 << '\n';
            continue;
        }
        if (r >= c[l]) {
            cout << 4 << '\n';
            for (int j = 0; j < 4; j++) {
                cout << ans[l][j] + 1 << ' ';
            }
            cout << '\n';
            continue;   
        }
        if (lastl[l] <= lastr[l]) {
            res[i].pb(lastl[l]);
            res[i].pb((a[lastl[l] + 1] < a[lastr[l]] ? lastl[l] + 1: lastr[l]));
            res[i].pb(lastr[l] + 1);
        } else {
            res[i].pb(lastr[l]);
            res[i].pb((a[lastr[l] + 1] > a[lastl[l]] ? lastr[l] + 1: lastl[l]));
            res[i].pb(lastl[l] + 1);
        }
        cout << 3 << '\n';
        for (auto x: res[i]) {
            cout << x + 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}