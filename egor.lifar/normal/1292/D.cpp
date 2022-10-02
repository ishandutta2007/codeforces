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
const int MAXN = 1000228;


int n;
int k[MAXN];
int cnt[5005];
bool bad[5005];
int curs[5005];



char readchar() {
    char c = _getchar_nolock();
    while (c <= 32) {
        c = _getchar_nolock();
    }
    return c;
}


int readint() 
{
    char c = readchar();
    int mag = 0;
    if (c == '-') {
        mag = 1;
        c = readchar();
    }
    int t = 0;
    while (c >= '0' && c <= '9') {
        t = ((t << 3) + (t << 1)) + c - '0';
        c = _getchar_nolock();
    }
    return (mag ? -t: t);
}



vector<pair<pair<int, int>, int> > nxt[MAXN];
int uks = 0;
ll adds[MAXN];
ll sum[MAXN];


void add(vector<pair<int, int> > &g, int mod) {
    int cur = 0;
    int uk = 0;
    while (uk < sz(g)) {
        auto &x = g[uk];
        bool was = false;
        for (auto &y: nxt[cur]) {
            if (y.first.first == x.first) {
                was = true;
                if (y.first.second == x.second) {
                    cur = y.second;
                    uk++;
                    break;
                } else if (y.first.second > x.second) {
                    uks++;
                    nxt[uks].pb({{y.first.first, y.first.second - x.second}, y.second});
                    y.first.second = x.second;
                    y.second = uks;
                    cur = uks;
                    uk++;
                    break;
                } else if (y.first.second < x.second) {
                    cur = y.second;
                    x.second -= y.first.second;
                }
                break;   
            }
        }
        if (!was) {
            uks++;
            nxt[cur].pb({{x.first, x.second}, uks});
            cur = uks;
            uk++;
        }
    }
    adds[cur] += mod;
}


void dfs(int u, int deep) {
    sum[u] = (ll)deep * adds[u];
    for (auto h: nxt[u]) {
        dfs(h.second, deep + h.first.second);
        sum[u] += sum[h.second];
        adds[u] += adds[h.second];
    }
}
 
 
ll res = 0;
ll ans = 1e18;
ll res1 = 0;
 
 
void dfs1(int u, int deep) {
    chkmin(ans, res + sum[u] - (ll)deep * adds[u]);
    int fk = adds[u];
    for (auto h: nxt[u]) {
        fk -= adds[h.second];
    }
    res1 += fk;
    ll sums = 0;
    for (auto h: nxt[u]) {
        sums += sum[h.second] - (ll)deep * adds[h.second];
        res1 += adds[h.second];
    }
    for (auto h: nxt[u]) {
        //cout << u << " -> " << h.second << ' ' << h.first.first << ' ' << h.first.second << endl;
        res1 -= adds[h.second];
        sums -= sum[h.second] - (ll)deep * adds[h.second];
        res += sums;
        res += res1 * h.first.second;
        dfs1(h.second, deep + h.first.second);
        res -= res1 * h.first.second;
        res -= sums;
        res1 += adds[h.second];
        sums += sum[h.second] - (ll)deep * adds[h.second];
    }
    for (auto h: nxt[u]) {
        res1 -= adds[h.second];
    }
    res1 -= fk;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);     
    n = readint();
    int tk = 0;
    for (int i = 0; i < n; i++) {
        k[i] = readint();
        if (k[i] == 0) {
            k[i] = 1;
        }
        cnt[k[i]]++;
        chkmax(tk, k[i]);
    }
    vector<int> st;
    for (int i = 2; i <= 5000; i++) {
        if (!bad[i]) {
            st.pb(i);
        }
        for (int j = i * i; j <= 5000; j += i) {
            bad[j] = true;
        }
    }
    for (int i = 1; i <= tk; i++) {
        int is = i;
        for (int j = 0; j < sz(st); j++) {
            while (is % st[j] == 0) {
                curs[j]++;
                is /= st[j];
            }
        }
        if (cnt[i]) {
            vector<pair<int, int> > g;
            for (int j = sz(st) - 1; j >= 0; j--) {
                if (curs[j]) {
                    g.pb({st[j], curs[j]});
                    // for (int js = 0; js < curs[j]; js++) {
                    //     cout << st[j] << ' ';
                    // }
                }   
            }
            add(g, cnt[i]);
         //   cout << '\n';
        }
    }
    dfs(0, 0);
    dfs1(0, 0);
    cout << ans << '\n';
    return 0;
}