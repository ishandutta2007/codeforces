#include <bits/stdc++.h> 
using namespace std; 
int gi() { 
	int res = 0, w = 1; 
	char ch = getchar(); 
	while (ch != '-' && !isdigit(ch)) ch = getchar(); 
	if (ch == '-') w = -1, ch = getchar(); 
	while (isdigit(ch)) res = res * 10 + ch - '0', ch = getchar(); 
	return res * w; 
}
typedef long long LL; 
const int MAX_N = 2e5 + 5; 
int N, K, Id[MAX_N], foo[MAX_N][10], nxt[125][125], cnt; 
void prepare() { 
	int p[10]; 
	for (int i = 1; i <= K; i++) p[i] = i; 
	do { 
		int res = 0; 
		for (int i = 1; i <= K; i++) res = res * K + p[i] - 1; 
		Id[res] = ++cnt; 
		for (int i = 1; i <= K; i++) foo[cnt][i] = p[i]; 
	} while (next_permutation(&p[1], &p[K + 1])); 
	for (int i = 1; i <= cnt; i++) 
		for (int j = 1; j <= cnt; j++) { 
			int res = 0; 
			for (int k = 1; k <= K; k++) p[k] = foo[i][foo[j][k]]; 
			for (int k = 1; k <= K; k++) res = res * K + p[k] - 1; 
			nxt[i][j] = Id[res]; 
		} 
} 
LL ans; 
struct node { int u, v, w; } ; 
int pa[125], sz[125]; 
int getf(int x) { while (x != pa[x]) x = pa[x] = pa[pa[x]]; return x; } 
vector<node> vec, pot; 
void unite(int x, int y, int w) { 
	if (getf(x) == getf(y)) return ; 
	vec.push_back((node){x, y, w}), x = getf(x), y = getf(y); 
	if (x == getf(1)) ans += 1ll * w * sz[y]; 
	if (y == getf(1)) ans += 1ll * w * sz[x]; 
	if (sz[x] > sz[y]) swap(x, y); 
	sz[y] += sz[x], pa[x] = y; 
} 
void solve(int pos) { 
	int now = 0; 
	for (int i = 1; i <= K; i++) now = now * K + gi() - 1; 
	now = Id[now]; 
	for (int i = 1; i <= cnt; i++) pa[i] = i, sz[i] = 1; 
	pot = vec, vec.clear(); 
	for (int i = 1; i <= cnt; i++) unite(i, nxt[i][now], pos); 
	for (auto it : pot) unite(it.u, it.v, it.w); 
	ans += pos; 
} 
int main () { 
#ifndef ONLINE_JUDGE 
    freopen("cpp.in", "r", stdin); 
#endif 
	N = gi(), K = gi(); 
	prepare(); 
	for (int i = 1; i <= N; i++) solve(i);
	printf("%lld\n", ans); 
    return 0; 
}