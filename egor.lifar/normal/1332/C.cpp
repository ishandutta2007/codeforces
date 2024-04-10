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
const int MAXN = 100228;

int n, k;
string s;
int cnt[MAXN][30];
bool used[MAXN];
vector<int> st;
vector<int> g[MAXN];


void dfs(int u) {
    used[u] = true;
    st.pb(u);
    for (auto h: g[u]) {
        if (!used[h]) {
            dfs(h);
        }
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
        cin >> n >> k;
        cin >> s;
        for (int i = 0; i < n; i++) {
            used[i] = false;
            g[i].clear();
        }
        int kek = 0;
        for (int i = 0; i < k; i++) {
            memset(cnt[i], 0, sizeof(cnt[i]));
            for (int j = 0; j < sz(s) / k; j++) {
                cnt[i][s[i + j * k] - 'a']++;
            }
        }
        for (int i = 0; i < sz(s) / 2; i++) {
            if (s[i] != s[sz(s) - i - 1]) {
                g[i % k].pb((sz(s) - i - 1) % k);
                g[(sz(s) - i - 1) % k].pb(i % k);
            }
        }
        int ans = 0;
        for (int i = 0; i < k; i++) {
            if (!used[i]) {
                st.clear();
                dfs(i);
                int cnt1[30];
                memset(cnt1, 0, sizeof(cnt1));
                for (auto x: st) {
                    for (int j = 0; j < 26; j++) {
                        cnt1[j] += cnt[x][j];
                    }
                }
                int cur = 0;
                for (int j = 0; j < 26; j++) {
                    chkmax(cur, cnt1[j]);
                }
                ans += (n / k) * sz(st) - cur;
            }   
        }
        cout << ans << '\n';
    }

    return 0;
}