#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100010;
int nowarn;

int n, m;

namespace Graph {
	int head[MAXN], nxt[MAXN<<1], to[MAXN<<1], w[MAXN<<1], eidx = 0;
	void init() {
		memset( head, -1, sizeof(head) );
	}
	void adde( int u, int v, int wei ) {
		to[eidx] = v, nxt[eidx] = head[u], w[eidx] = wei, head[u] = eidx++;
		to[eidx] = u, nxt[eidx] = head[v], w[eidx] = wei, head[v] = eidx++;
	}
}

namespace Basis {
	int b[31] = {0};
	void insert( int x ) {
		for( int i = 30; i >= 0 && x; --i ) {
			if( !(x & (1<<i)) ) continue;
			if( !b[i] ) {
				b[i] = x;
				break;
			} else {
				x ^= b[i];
			}
		}
	}
	int query_min( int x ) {
		for( int i = 30; i >= 0 && x; --i )
			x = min(x, x^b[i]);
		return x;
	}
}

int dfn[MAXN] = {0}, dfn_cnt = 0;
int xorval[MAXN];
void dfs( int u, int fae, int val ) {
	using namespace Graph;
	xorval[u] = val, dfn[u] = ++dfn_cnt;
	for( int i = head[u]; ~i; i = nxt[i] ) {
		if( i == (fae^1) ) continue;
		int v = to[i];
		if( !dfn[v] ) {
			dfs(v, i, val^w[i]);
		} else if( dfn[v] < dfn[u] ) {
			Basis::insert(val ^ xorval[v] ^ w[i]);
		}
	}
}

int main() {
	scanf( "%d%d", &n, &m );
	Graph::init();
	for( int i = 0; i < m; ++i ) {
		int u, v, w;
		scanf( "%d%d%d", &u, &v, &w );
		if( u != v ) Graph::adde(u, v, w);
		else Basis::insert(w);
	}
	dfs(1, 1e9, 0);
	printf( "%d\n", Basis::query_min(xorval[n]) );
	return 0;
}