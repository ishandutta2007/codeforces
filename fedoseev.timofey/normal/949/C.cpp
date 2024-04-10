#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>
 
using namespace std;
 
typedef long long ll;
 
const int N = 1e5 + 11;
 
int c[N];
vector <int> g[N];
vector <int> gr[N];
bool used[N];
int ans[N];
vector <int> cnt[N];
bool bad[N];
 
vector <int> tpsort;
 
void get_tpsort(int u) {
    used[u] = 1;
    for (auto v : g[u]) {
        if (!used[v]) {
            get_tpsort(v);
        }
    }
    tpsort.push_back(u);
}
 
int cmp = 0;
 
void dfs(int u) {
    used[u] = 1;
    ans[u] = cmp;
    cnt[cmp].push_back(u);
    for (auto v : gr[u]) {
        if (!used[v]) {
            dfs(v);
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m, h;
    cin >> n >> m >> h;
    for (int i = 0; i < n; ++i) {
    	cin >> c[i];
    }
    for (int i = 0; i < m; ++i) {
    	int a, b;
    	cin >> a >> b;
    	--a, --b;
    	if ((c[a] + 1) % h == c[b]) {
    		g[a].push_back(b);
    		gr[b].push_back(a);
    	}
    	if ((c[b] + 1) % h == c[a]) {
    		g[b].push_back(a);
    		gr[a].push_back(b);
    	}
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            get_tpsort(i);
        }
    }
    reverse(tpsort.begin(), tpsort.end());
    for (int i = 0; i < N; ++i) {
        used[i] = 0;
    }
    for (auto u : tpsort) {
        if (!used[u]) {
            dfs(u);
            ++cmp;
        }
    }
    int res = 2e9;
    int ind = -1;
    for (int i = 0; i < N; ++i) {
    	bool flag = true;
    	for (auto u : cnt[i]) {
    		for (auto v : g[u]) {
    			if (ans[v] != ans[u]) {
    				flag = false;
    			}
    		}
    	}
    	if (flag && cnt[i].size() < res && cnt[i].size()) {
    		res = cnt[i].size();
    		ind = i;
    	}
    }
    cout << res << endl;
    for (auto e : cnt[ind]) {
    	cout << e + 1 << " ";
    }
}