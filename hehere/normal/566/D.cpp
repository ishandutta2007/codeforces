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

const int maxN = 200000 + 5;
const int maxQ = 500000 + 5;
int n, q;
int pa[maxN];
int findfa(int x) {
	return pa[x] == x ? x : pa[x] = findfa(pa[x]);
}
void merge(int x, int y) {
	int fx = findfa(x), fy = findfa(y);
	pa[fx] = fy;
}

set<pii> S;

void solve(int x, int y) {
	auto i = S.lower_bound(pii(x, x));
	if(x < i->first) --i;
	int lb = i->first;
	int rb = i->second;
	while(i->second < y) {
		rb = i->second;
		merge(lb, rb);
//		printf("remove(%d, %d)\n", i->first, i->second);
		i = S.erase(i);
	}
	rb = i->second; merge(lb, rb);
	S.erase(i);
//	printf("add(%d, %d)\n", lb, rb);
	S.insert(pii(lb, rb));
}

int main() {
	n = readint(); q = readint();
	S.clear();
	for(int i = 1; i <= n; ++i) pa[i] = i;
	S.insert(pii(0, 0));
	for(int i = 1; i <= n; ++i) S.insert(pii(i, i));
	S.insert(pii(n + 1, n + 1));

	for(int kase = 1; kase <= q; ++kase) {
		int t = readint();
		if(t == 1) {
			int x = readint(), y = readint();
			merge(x, y);
		} else if(t == 2) {
			int x = readint(), y = readint();
			solve(x, y);
		} else if(t == 3) {
			int x = readint(), y = readint();
			printf("%s\n", findfa(x) == findfa(y) ? "YES" : "NO");
		} else {
			assert(false);
		}
	}
	return 0;
}