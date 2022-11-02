#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <algorithm>
using std::sort; using std::min; using std::max;
#include <vector>
using std::vector;
#include <set>
using std::set;
#include <queue>
using std::queue; using std::priority_queue;
#include <utility>
using std::pair;
typedef pair<int, int> pii;
typedef long long LL;
typedef long double LD;
#define pass printf("%s : Line.%d\n", __FUNCTION__, __LINE__);

const int maxN = 100000 + 233;
const int INF = 0x3f3f3f3f;
int n, m, fa[maxN], c[maxN];
typedef int A[maxN];
A f, g;
vector<int> a;
int getfa(int u) {
	return fa[u] == u ? u : fa[u] = getfa(fa[u]);
}

bool __islucky(int x) {
	while(x) {
		int t = x % 10;
		if(t != 4 && t != 7) return false;
		x /= 10;
	}
	return true;
}
bool islucky[maxN];

void init() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) fa[i] = i;
	for(int i = 1; i <= m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		int fx = getfa(x), fy = getfa(y);
		if(fx != fy) fa[fx] = fa[fy];
	}
	memset(c, 0, sizeof(c));
	for(int u = 1; u <= n; ++u) ++c[getfa(u)];
	for(int i = 1; i <= n; ++i) if(c[i])
		a.push_back(c[i]);
	std::sort(a.begin(), a.end());
}

bool chmin(int &a, int b) {
	return a > b ? a = b, true : false;
}

int solve() {
	for(int v : a) if(islucky[v]) return 0;
	int ans = INF;
	memset(g, INF, sizeof(g));
	vector<int> pos, tmp;
	pos.clear(); pos.push_back(0); g[0] = 0;
//	for(int x : a) printf("%d ", x); printf("\n");
	for(int i = 0; i < (int)a.size(); ++i) {
		std::sort(pos.begin(), pos.end());
//		pos.erase(std::lower_bound(pos.begin(), pos.end(), ans - 1), pos.end());
		int j, v = a[i];
		for(j = i; j < (int)a.size() && a[j] == v; ++j);
		--j;
		int cnt = j - i + 1;
		i = j;
//		x * v costs (x-1)
		for(int x : pos) if(x) {
			int gx = g[x];
			if(islucky[x]) chmin(ans, x);
			for(int y = v, c = 1; c <= cnt; y += v, ++c) {
				chmin(g[x + y], gx + c);
//				printf("%d + %d freshed to %d + %d\n", x, y, gx, c);
				if(gx + c >= ans) break;
			}
		}
		for(int y = v, c = 0; c < cnt; y += v, ++c) {
			chmin(g[y], c);
			if(c >= ans) break;
		}
		tmp.clear();
//		printf("%d %d\n", cnt, v);
//		printf("pos = ");
//		for(int x : pos) printf("%d ", x); printf("\n");
//		
//		printf("g = ");
//		for(int i = 0; i <= n; ++i) printf("%d ", g[i]); printf("\n");
//		printf("\n");
		
		for(int i = 0; i <= pos[pos.size() - 1] + cnt*v; ++i) {
			if(g[i] <= ans - 2) tmp.push_back(i);
		}
		
		std::swap(tmp, pos);
	}
	for(int i = 1; i <= n; ++i) if(islucky[i]) chmin(ans, g[i]);
	return ans == INF ? -1 : ans;
}

int main() {
	/*
	int n;
	cin >> n;
	while(n--) {
		int x, y;
		cin >> x >> y;
		while(x--) a.push_back(y);
	}
	std::sort(a.begin(), a.end());
	*/
	for(int i = 1; i < maxN; ++i) islucky[i] = __islucky(i);
	islucky[0] = false;
	init();
	printf("%d\n", solve());
	return 0;
}