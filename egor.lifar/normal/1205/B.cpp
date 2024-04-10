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
#define next next224
#define rank rank224
#define prev prev224
#define y1 y1224
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
const string FILENAME = "input";
const int MAXN = 100228;



int n;
long long a[MAXN];
vector<int> g[MAXN];
int res;
bool used[MAXN];
int deep[MAXN];


void dfs(int u) {
	used[u] = true;
	for (auto h: g[u]) {
		if (!used[h]) {
			deep[h] = deep[u] + 1;
			dfs(h);
		} else {
			if (deep[u] - deep[h] + 1 > 2) {
				chkmin(res, deep[u] - deep[h] + 1);
			}
		}
	}
}


map<int, int> dist;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME); 
    cin >> n;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    res = 1e9;
    for (int i = 0; i < 62; i++) {
    	int cnt = 0;
    	vector<int> st;
    	for (int j = 0; j < n; j++) {
    		if (a[j] & (1LL << i)) {
    			cnt++;
    			st.pb(j);
    		}
    	}
    	if (cnt >= 3) {
    		chkmin(res, 3);
    	} else {
    		if (cnt == 2) {
    			g[st[0]].pb(st[1]);
    			g[st[1]].pb(st[0]);
    		}
    	}
    }
    for (int i = 0; i < n; i++) {
    	sort(all(g[i]));
    	g[i].resize(distance(g[i].begin(), unique(all(g[i]))));
    }
    for (int i = 0; i < n; i++) {
    	for (auto x: g[i]) {
    		queue<int> q;
    		dist.clear();
    		q.push(i);
    		dist[i] = 0;
    		while (!q.empty()) {
    			int a = q.front();
    			q.pop();
    			for (auto y: g[a]) {
    				if (a == i && y == x) continue;
    				if (a == x && y == i) continue;
    				if (dist.find(y) == dist.end()) {
    					dist[y] = dist[a] + 1;
    					q.push(y);
    				}
    			}
    		}
    		if (dist.find(x) != dist.end()) {
    			chkmin(res, 1 + dist[x]);
    		}
    	}
    }
    if (res > n) {
    	res = -1;
    }
    cout << res << endl;
    return 0; 
}