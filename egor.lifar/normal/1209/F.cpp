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
const int MAXN = 2200222;
const int Mod = 1000000007;


int n, m;
vector<pair<int, int> > g[MAXN];

int getlen(int a) {
    int cnt = 0;
    while (a > 0) {
        a /= 10;
        cnt++;
    }
    return cnt;
}


int uk;


void adde(int a, int b, int c) {
    g[a].pb({b, c});
}


void add(int i, int j, int k) {
    int cur = j;
    while (k >= 10) {
        adde(uk, cur, k % 10);
        k /= 10;
        cur = uk;
        uk++;
    }   
    adde(i, cur, k);
}

vector<int> kek[MAXN];
int classt[MAXN];
int res[MAXN];
bool used[MAXN];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME); 
    cin >> n >> m;
    uk = n;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        add(a, b, i + 1);
        add(b, a, i + 1);
    }
    kek[0].pb(0);
    res[0] = 0;
    used[0] = true;
    int ukh = 0;
    while (!kek[ukh].empty()) {
        vector<pair<pair<int, int>, pair<int, int> > > st;
        for (auto x: kek[ukh]) {
            for (auto z: g[x]) {
                if (!used[z.first]) {
                    st.pb({{classt[x], z.second}, {z.first, x}});
                }
            }
        }
        sort(all(st));
        int curt = 0;
        pair<int, int> last = mp(-1, -1);
        for (auto x: st) {
            if (last != x.first) {
                last = x.first;
                curt++;
            }
            int u = x.second.first;
            int h = x.second.second;
            if (!used[u]) {
                used[u] = true;
                kek[ukh + 1].pb(u);
                classt[u] = curt;
                res[u] = (1LL * res[h] * 10 + x.first.second) % Mod;
            }
        }
        ukh++;
    }
    for (int i = 1; i < n; i++) {
        cout << res[i] << '\n';
    }
    return 0; 
}