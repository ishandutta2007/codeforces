#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <algorithm>
#include <vector>
using std::vector;
#include <map>
using std::map;
#include <set>
using std::set;
#include <queue>
using std::queue; using std::priority_queue;
#include <utility>
using std::pair;
typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
#define pass printf("%s : Line.%d\n", __FUNCTION__, __LINE__);

inline int readint() {
	int a = 0, po = 1; char c = getchar();
	while(isspace(c)) c = getchar();
	if(c == '-') po = -1, c = getchar();
	while(isdigit(c)) a = a*10 + c - '0', c = getchar();
	return a * po;
}
inline LL readLL() {
	LL a = 0, po = 1; char c = getchar();
	while(isspace(c)) c = getchar();
	if(c == '-') po = -1, c = getchar();
	while(isdigit(c)) a = a*10 + c - '0', c = getchar();
	return a * po;
}
bool chmin(int &a, int b) { return a > b ? a = b, true : false; }
bool chmax(int &a, int b) { return a < b ? a = b, true : false; }
bool chmin(LL &a, LL b) { return a > b ? a = b, true : false; }
bool chmax(LL &a, LL b) { return a < b ? a = b, true : false; }

const int maxN = 100000 + 5;
const int NODE = 800000 + 233;
const int SIGMA = 26;
int n, cnt = 0;
LL ans = 0;
int ch[NODE][SIGMA];
vector<int> a[NODE], b[NODE];
vector<pii> result;

void insert(char *s, int len, int id) {
	int u = 0;
	for(int i = 0; i < len; ++i) {
		int c = (int)s[i] - 'a';
		if(!ch[u][c]) ch[u][c] = ++cnt;
		u = ch[u][c];
	}
	if(id > 0) a[u].push_back(id);
	else b[u].push_back(-id);
}

void dfs(int u, int d) {
	for(int c = 0; c < SIGMA; ++c) {
		int v = ch[u][c];
		if(!v) continue;
		dfs(v, d + 1);
		for(int x : a[v]) a[u].push_back(x);
		for(int y : b[v]) b[u].push_back(y);
		while(a[u].size() && b[u].size()) {
			result.push_back(pii(a[u].back(), b[u].back()));
			a[u].pop_back(); b[u].pop_back();
			ans += d;
		}
	}
	while(a[u].size() && b[u].size()) {
		result.push_back(pii(a[u].back(), b[u].back()));
		a[u].pop_back(); b[u].pop_back();
		ans += d;
	}
}


int main() {
	static char s[NODE];
	n = readint();
	for(int i = 1; i <= n; ++i) {
		scanf("%s", s);
		int len = strlen(s);
		insert(s, len, i);
	}
	for(int i = 1; i <= n; ++i) {
		scanf("%s", s);
		int len = strlen(s);
		insert(s, len, -i);
	}
	dfs(0, 0);
	printf("%lld\n", ans);
	for(pii p : result) printf("%d %d\n", p.first, p.second);
	return 0;
}