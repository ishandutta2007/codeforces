#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int size = 100 * 1000 + 100;
const long long inf = (long long) 1e18;

vector <pair <int, int> > vertex[size];
long long deep[size];
long long dist[size];
int n, m;
long long len[size];

void dfs1(int v, int fr) {
	deep[v] = 0;
	for (int i = 0; i < (int) vertex[v].size(); i++) {
		if (vertex[v][i].fs != fr) {
			dfs1(vertex[v][i].fs, v);
			deep[v] = max(deep[v], deep[vertex[v][i].fs] + vertex[v][i].sc);
		}
	}
}

void dfs2(int v, int fr, long long best) {
	dist[v] = max(deep[v], best);
//		cerr << v << ' ' << deep[v] << ' ' << dist[v] << endl;

	long long mx1 = best, mx2 = -inf;
	int b1 = -1;
	int b2 = -1;
	for (int i = 0; i < (int) vertex[v].size(); i++) {
		if (vertex[v][i].fs != fr) {
			long long d = deep[vertex[v][i].fs] + vertex[v][i].sc;
			if (d >= mx1) {
				mx2 = mx1;
				b2 = b1;
				mx1 = d;
				b1 = i;	
			} else {
				if (d > mx2) {
					mx2 = d;
					b2 = i;
				}
			}
		}
	} 

	for (int i = 0; i < (int) vertex[v].size(); i++) {
		if (vertex[v][i].fs != fr) {
			if (i != b1) {
				dfs2(vertex[v][i].fs, v, mx1 + vertex[v][i].sc);
			} else {
				dfs2(vertex[v][i].fs, v, mx2 + vertex[v][i].sc);
			}
		}	
	}
}

vector <long long> st;
vector <int> nums;
int ans[size];

void gosolve(int v, int fr, long long len) {
	st.pb(dist[v]);
	nums.pb(v);
	ans[v]++;

	int ps = lower_bound(st.begin(), st.end(), dist[v] - len) - st.begin();
	if (ps > 0) {
		ans[nums[ps - 1]]--;
	}

	for (int i = 0; i < (int) vertex[v].size(); i++) {
		if (vertex[v][i].fs != fr) {
			gosolve(vertex[v][i].fs, v, len);
			ans[v] += ans[vertex[v][i].fs];
		}
	}

	st.pop_back();
	nums.pop_back();
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
    	int v, u, d;
    	scanf("%d%d%d", &v, &u, &d);

    	v--, u--;
    	vertex[v].pb(mp(u, d));
    	vertex[u].pb(mp(v, d));
    }

    dfs1(0, 0);
    dfs2(0, 0, 0);

    int b = 0;
    for (int i = 1; i < n; i++) {
    	if (dist[i] < dist[b])
    		b = i;
    }
    
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
    	scanf("%I64d", &len[i]);

    	for (int j = 0; j < n; j++) {
    		ans[j] = 0;
    	}
    	gosolve(b, b, len[i]);
    	int best = 0;
    	for (int j = 0; j < n; j++)
    		best = max(best, ans[j]);

    	printf("%d\n", best);
    }


    return 0;
}