#include <cstdio>
#include <cstring>
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <algorithm>
#include <list>
using std::list;
typedef long long LL;
typedef unsigned long long ULL;
const int maxN = 10000 + 5;
const int maxQ = 10000 + 5;
int n, q;
struct Query {
	int lb, rb, d;
	void read() {
		scanf("%d%d%d", &lb, &rb, &d);
	}
}query[maxQ];
list<int> pos[maxN], neg[maxN];
ULL f[maxN];
const LL P = 1000000000000000003LL;
LL g[maxN];
bool ans[maxN];

/*
10 3
1 6 2
5 8 3
3 6 6
*/

void add(LL &x, LL y) {
	(x += y) >= P ? x -= P : x;
}
void dec(LL &x, LL y) {
	(x -= y) < 0 ? x += P : x;
}

bool prime(LL x) {
	for(LL i = 2; i * i <= x; ++i) if(x % i == 0) {
		printf("min_divisor of %lld is %lld\n", x, i);
		return false;
	}
	return true;
}

int main() {
//	printf("Memory: %.3lfMB\n", sizeof(rec) / 1000.0 / 1000.0);
	
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= q; ++i) query[i].read();
	for(int i = 1; i <= q; ++i) {
		pos[query[i].lb].push_back(i);
		neg[query[i].rb].push_back(i);
	}
	
	memset(ans, 0, sizeof(ans));
	memset(f, 0, sizeof(f));
	f[0] = 1; g[0] = 1;
	
	for(int L = 1; L <= n; ++L) {
		for(list<int>::iterator it = pos[L].begin(); it != pos[L].end(); ++it) {
			int d = query[*it].d;
			for(int i = n - d; i >= 0; --i) f[i + d] += f[i], add(g[i + d], g[i]);
		}
		for(int i = 0; i <= n; ++i) (f[i] || g[i]) ? ans[i] = 1 : 233;
//		printf("L = %d\n", L);
//		for(int i = 0; i <= n; ++i) printf("%d ", f[i]);
//		printf("\n");
		for(list<int>::iterator it = neg[L].begin(); it != neg[L].end(); ++it) {
			int d = query[*it].d;
			for(int i = 0; i <= n - d; ++i) f[i + d] -= f[i], dec(g[i + d], g[i]);
		}
	}
	
	int cnt = 0;
	for(int i = 1; i <= n; ++i) if(ans[i]) ++cnt;
	printf("%d\n", cnt);
	for(int i = 1; i <= n; ++i) if(ans[i]) printf("%d ", i);
	printf("\n");
	
	return 0;
}