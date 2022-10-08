#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const int size = 200 * 1000 + 100;
vector <int> vertex[size];
int comp[size];
int maxd[size];
vector <long long> rads[size];
vector <long long> sum[size];
vector <long long> sumw[size];
int csize[size];
int cdiam[size];
int n, m, q;
vector <int> curvis;
int dist[size];
int bfscnt = 0;
int vis[size];
int compcnt = 0;
map <pair <int, int>, double> cach;

void bfs(int v) {
	bfscnt++;
	curvis.clear();

	dist[v] = 0;
	vis[v] = bfscnt;
	queue <int> q;
	q.push(v);

	while (!q.empty()) {
		int cur = q.front();
		curvis.pb(cur);
		q.pop();
		for (auto& u : vertex[cur]) {
			if (vis[u] != bfscnt) {
				vis[u] = bfscnt;
				dist[u] = dist[cur] + 1;
				q.push(u);
			}
		}
	}
}

void build_structure() {
	for (int i = 0; i < n; i++) {
		comp[i] = -1;
	}

	for (int i = 0; i < n; i++) {
		if (comp[i] == -1) {
			bfs(i);
			int m = (int) curvis.size();
			csize[compcnt] = m;
			for (int j = 0; j < m; j++) {
				comp[curvis[j]] = compcnt;
			}
			int b = curvis[0];
			for (int j = 0; j < m; j++) {
				if (dist[curvis[j]] > dist[b]) {
					b = curvis[j];
				}
			}
			bfs(b);
			int c = curvis[0];
			for (int j = 0; j < m; j++) {
				maxd[curvis[j]] = dist[curvis[j]];
				if (dist[curvis[j]] > dist[c])
					c = curvis[j];
			}			

			bfs(c);
			for (int j = 0; j < m; j++) {
				maxd[curvis[j]] = max(maxd[curvis[j]], dist[curvis[j]]);	
			}

			cdiam[compcnt] = dist[b];
			rads[compcnt].resize(cdiam[compcnt] + 1);
			sum[compcnt].resize(cdiam[compcnt] + 1);
			sumw[compcnt].resize(cdiam[compcnt] + 1);
			for (int j = 0; j < m; j++) {
				rads[compcnt][maxd[curvis[j]]]++;
			}

			for (int j = cdiam[compcnt]; j >= 0; j--) {
				sum[compcnt][j] = rads[compcnt][j];
				if (j < cdiam[compcnt])
					sum[compcnt][j] += sum[compcnt][j + 1];

				sumw[compcnt][j] = rads[compcnt][j] * j;
				if (j < cdiam[compcnt])
					sumw[compcnt][j] += sumw[compcnt][j + 1];
			}
		
			compcnt++;
		}
	}
}

double getans(int a, int b) {
	if (cdiam[a] < cdiam[b])
		swap(a, b);
	double ans = 0.0;
	int rd = max(cdiam[a], cdiam[b]);
	//cerr << "ok " << a << ' ' << b << endl;
	for (int i = 0; i <= cdiam[b]; i++) {
		int j = rd - i;
		ans += rads[b][i] * 1ll * (csize[a] - sum[a][j]) * 1ll * rd;
		ans += rads[b][i] * 1ll * i * 1ll * sum[a][j] + rads[b][i] * 1ll * sumw[a][j] + rads[b][i] * 1ll * sum[a][j];
	}

	return ans / (csize[a] * 1ll * csize[b]);
}

int main () {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < m; i++) {
    	int u, v;
    	scanf("%d%d", &u, &v);
    	u--, v--;

    	vertex[v].pb(u);
    	vertex[u].pb(v);
    }

    build_structure();

    for (int i = 0; i < q; i++) {
    	int u, v;
    	scanf("%d%d", &u, &v);
    	u--, v--;

    	int a = comp[u];
    	int b = comp[v];
    //	cerr << u << ' ' << v << ' ' << a << ' ' << b << endl;

    	if (a == b) {
    		printf("-1\n");
    	} else {
    		if (a > b)
    			swap(a, b);
    		if (cach.find(mp(a, b)) == cach.end())
    			cach[mp(a, b)] = getans(a, b);
    		printf("%.20lf\n", cach[mp(a, b)]);
    	}
    }

    return 0;
}