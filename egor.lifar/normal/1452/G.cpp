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
template<typename T1, typename T2> inline void chkmin(T1 &a, T2 b) {if (a > b) a = b;}
template<typename T1, typename T2> inline void chkmax(T1 &a, T2 b) {if (a < b) a = b;}
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define left left228
#define right right228
#define y1 y1228
#define mp make_pair
#define pb push_back
#define y2 y2228
#define rank rank228
using ll = long long;
using ld = long double; 
const string FILENAME = "input";
const int MAXN = 200043;
const int LN = 18;
const int INF = 1000000000;


vector<int> g[MAXN];
vector<int> dist[MAXN];
int sz[MAXN];
int par[MAXN];
bool used[MAXN];
int mDist[MAXN];
vector<int> val[MAXN];


int	dfsc(int x, int p = -1) {
    sz[x] = 1;
    for (auto y: g[x]) {
        if (y != p && !used[y]) {
            sz[x] +=	dfsc(y, x);
        }
    }
    return sz[x];   
}


int find_centroid(int x, int p, int s) {
    int ans = -1;
    bool good = true;
    for (auto y: g[x]) {
        if(y != p && !used[y]) {
            good &= sz[y] * 2 <= s;
        } else if(y == p && !used[y]) {
            good &= (s - sz[x]) * 2 <= s;
        }
    }
    if (good) {
        ans = x;
    }
    for (auto y : g[x]) {
        if (y != p && !used[y]) {
            chkmax(ans, find_centroid(y, x, s));
        }
    }
    return ans;
}


void calc_dist(int x, int p, int d, int s) {
    dist[x].pb(d);
    for (auto y: g[x]) {
        if (y != p && !used[y]) {
            calc_dist(y, x, d + 1, s);
        }
    }
    chkmax(mDist[s], d);  
}


int decomposition(int v) {
   	dfsc(v);
    int c = find_centroid(v, v, sz[v]);
    used[c] = true;
    for (auto y : g[c]) {
        if (!used[y]) {
            par[decomposition(y)] = c;
        }
    }
    used[c] = false;
    calc_dist(c, c, 0, c); 
    return c;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
    int n;
   	cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    decomposition(0);
    for (int i = 0; i < n; i++) {
        val[i].resize(mDist[i] + 1);    
    }
    int k;
    cin >> k;
    vector<int> d(n, INF);
    queue<int> q;
    for (int i = 0; i < k; i++) {
        int x;
      	cin >> x;
      	x--;
        q.push(x);
        d[x] = 0;
    }
    while (!q.empty())  {
        int x = q.front();
        q.pop();
        for (auto y: g[x]) {
            if (d[y] > d[x] + 1) {
                q.push(y);
                d[y] = d[x] + 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (d[i] == 0) {
        	continue;
        }
        int curc = i;
        for (int j = 0; j < sz(dist[i]); j++) {
            int dd = dist[i][j];
            if (dd > d[i] - 1) {
                curc = par[curc];
                continue;
            }
            dd = d[i] - 1 - dd;
            if (dd >= sz(val[curc])) {
                dd = sz(val[curc]) - 1; 
            }
           	chkmax(val[curc][dd], d[i]);
            curc = par[curc];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = mDist[i]; j >= 1; j--) {
            chkmax(val[i][j - 1], val[i][j]); 
        }
    }
    for (int i = 0; i < n; i++) {
        int ans = 0; 
        int curc = i;
        for (int j = 0; j < sz(dist[i]); j++) {
            int dd = dist[i][j];
            chkmax(ans, val[curc][dd]);
            curc = par[curc];
        }
        if (d[i] == 0) {
            ans = 0;
        }
       	cout << ans << ' ';
    }
    cout << '\n';
}