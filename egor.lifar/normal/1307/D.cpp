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
const int MAXN = 300228;


int n, m, k;
int a[MAXN];
vector<int> g[MAXN];
int dist[MAXN][2];
bool used[MAXN][2];


void kek(int u, int t) {
    queue<int> q;
    q.push(u);
    used[u][t] = true;
    while (!q.empty()) {
        int a = q.front();
        q.pop();
        for (auto x: g[a]) {
            if (!used[x][t]) {
                q.push(x);
                used[x][t] = true;
                dist[x][t] = dist[a][t] + 1;
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME); 
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }   
    for (int i = 0; i < m; i++) {
        int c, d;
        cin >> c >> d;
        g[c].pb(d);
        g[d].pb(c);
    }
    kek(1, 0);
    kek(n, 1);
    vector<pair<int, int> > st;
    for (int i = 0; i < k; i++) {
        st.pb({dist[a[i]][0], a[i]});
    }
    sort(all(st));
    int mind = dist[n][0];
    int fuck = st[0].first;
    int res = 0;
    for (int i = 1; i < k; i++) {
        chkmax(res, min(mind, 1 + fuck + dist[st[i].second][1]));
        chkmax(fuck, st[i].first);
    }
    cout << res << '\n';
    return 0;
}