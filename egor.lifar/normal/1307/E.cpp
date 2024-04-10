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
const int MAXN = 5105;
const int Mod = 1000000007;

int n, m;
int s[MAXN];
int f[MAXN], h[MAXN];
int lcnt[MAXN], rcnt[MAXN];
vector<int> who[MAXN];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME); 
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> f[i] >> h[i];
        who[f[i]].pb(h[i]);
    }
    for (int i = 1; i <= n; i++) {
        sort(all(who[i]));
    }
    int opt = 0;
    ll kek = 1;
    for (int i = 0; i <= m; i++) {
        int last = -1;
        int cnt = h[i];
        for (int j = 0; j < n; j++) {
            if (s[j] == f[i]) {
                cnt--;
                if (cnt == 0) {
                    last = j;
                    break;
                }
            }
        }
        if (i == m) {
            memset(lcnt, 0, sizeof(lcnt));
            memset(rcnt, 0, sizeof(rcnt));
            for (int j = 0; j < n; j++) {
                rcnt[s[j]]++;
            }
            int dp = 0;
            int ans = 1;
            for (int t = 1; t <= n; t++) {
                int cnt = 0;
                for (auto x: who[t]) {
                    if (x <= rcnt[t]) {
                        cnt++;
                    }
                }
                if (cnt) {
                    dp++;
                    ans = ((ll)ans * cnt) % Mod;
                }
            }
            if (dp > opt) {
                opt = dp;
                kek = ans;
            } else if (dp == opt) {
                kek = (kek + ans) % Mod;
            }
            continue;
        }
        if (last == -1) {
            continue;
        }
        memset(lcnt, 0, sizeof(lcnt));
        memset(rcnt, 0, sizeof(rcnt));
        for (int j = 0; j <= last; j++) {
            lcnt[s[j]]++;
        }
        for (int j = last + 1; j < n; j++) {
            rcnt[s[j]]++;
        }
        int dp = 1;
        ll ans = 1;
        for (int t = 1; t <= n; t++) {
            if (t == f[i]) {
                int g = rcnt[t];
                ll ps = 0;
                for (auto x: who[t]) {
                    if (x == h[i]) {
                        continue;
                    }
                    if (x <= g) {
                        ps++;
                    }
                }
                if (ps) {
                    dp++;
                    ans = ((ll)ans * ps) % Mod;
                }
            } else {
                int cnt = 0;
                int cnt1 = 0;
                int cnt2 = 0;
                for (auto x: who[t]) {
                    if (x <= lcnt[t]) {
                        cnt++;
                    } 
                    if (x <= rcnt[t]) {
                        cnt1++;
                    }
                    if (x <= lcnt[t] && x <= rcnt[t]) {
                        cnt2++;
                    }
                }
                bool bad = false;
                if (cnt2 == 0) {
                    if (cnt == 0 || cnt1 == 0) {
                        bad = true;
                    }
                } else {
                    if (cnt2 == 1) {
                        if (cnt <= cnt2 && cnt1 <= cnt2) {
                            bad = true;
                        }
                    }
                }
                if (bad) {
                    int val = cnt + cnt1;
                    if (val == 0) {
                        continue;
                    }
                    dp++;
                    ans = ((ll)ans * val) % Mod;
                    continue;
                }
                dp += 2;
                ll res = ((ll)(cnt - cnt2) * (cnt1 - cnt2)) % Mod;
                res += ((ll)(cnt2 * (cnt2 - 1))) % Mod;
                res += ((ll)(cnt - cnt2) * cnt2) % Mod;
                res += ((ll)(cnt1 - cnt2) * cnt2) % Mod;
                res %= Mod;
                ans = ((ll)ans * res) % Mod;
            }
        }
        if (dp > opt) {
            opt = dp;
            kek = ans;
        } else if (dp == opt) {
            kek = (kek + ans) % Mod;
        }
    }
    if (opt <= 0) {
        cout << 0 << ' ' << 1 << '\n';
        return 0;
    }
    cout << opt << ' ' << kek << '\n';
    return 0;
}