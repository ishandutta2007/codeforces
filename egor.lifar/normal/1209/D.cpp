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
const int MAXN = 200222;


int n, k;
int x[MAXN], y[MAXN];
vector<int > g[MAXN];
bool used[MAXN];
int cnt = 0;


void dfs(int u) {
    used[u] = true;
    cnt++;
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
    //read(FILENAME); 
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> x[i] >> y[i];
        g[x[i]].pb(y[i]);
        g[y[i]].pb(x[i]);
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            cnt = 0;
            dfs(i);
            res += cnt - 1;
        }
    }
    cout << k - res << endl;
    return 0; 
}