#include <bits/stdc++.h>
#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);
#define pb push_back
#define INF (0x3f3f3f3f)
using namespace std;
static unsigned char str[5500055], *p=str;
void fg(vector<int> G[], int a, int b) { G[a].pb(b); G[b].pb(a); }

const int MAXN = 100005;

multiset<int> PQ[MAXN];
vector<int> G[MAXN];

int prt[MAXN][17];
int dep[MAXN], cnt[MAXN];
int T[MAXN];

int N, K;

int lca(int a, int b) {
	if(dep[a] > dep[b]) swap(a, b);
	const int dt = dep[b] - dep[a];
	for(int i = 0; i < 17; i++) if((dt >> i) & 1)
		b = prt[b][i];
	if(a == b) return a;
	for(int i = 16; ~i; i--) if(prt[a][i] != prt[b][i]) {
		a = prt[a][i]; b = prt[b][i];
	}
	return prt[a][0];
}
int dist(int a, int b) {
	return dep[a] + dep[b] - (dep[lca(a, b)] << 1);
}

void cent(int &r) {
	const int n = cnt[r];
	for(int hi, hc;;) {
		hc = -1;
		for(int v : G[r]) if(cnt[v] < n && hc < cnt[v]) {
			hc = cnt[v];
			hi = v;
		}
		if(hc <= n/2) return;
		cnt[r] = n - cnt[hi];
		cnt[hi] = n;
		r = hi;
	}
}

void f(int i, int d) {
	dep[i] = d; cnt[i] = 1;
	for(int v : G[i]) if(!dep[v]) {
		prt[v][0] = i;
		f(v, d+1);
		cnt[i] += cnt[v];
	}
}

int g(int i) {
	cent(i);
	for(int v : G[i]) if(cnt[v] < cnt[i])
		T[g(v)] = i;
	return i;
}

void add(int i) {
	for(int v = i; v; v = T[v])
		PQ[v].insert(dist(i, v));
}
void rmv(int i) {
	for(int v = i; v; v = T[v])
		PQ[v].erase(PQ[v].find(dist(i, v)));
}
int get(int i) {
	int r = INF;
	for(int v = i, t ; v; v = T[v]) {
		if(PQ[v].empty()) continue;
		t = (*PQ[v].begin()) + dist(i, v);
		if(t < r) r = t;
	}
	return r;
}

int main() {
	fread(str, 1, 5500055, stdin);
	rf(N) rf(K)
	for(int i = 1, a, b; i < N; i++) {
		rf(a) rf(b)
		fg(G, a, b);
	}
	f(1, 1);
	for(int j = 1; j < 17; j++) for(int i = 1; i <= N; i++)
		prt[i][j] = prt[prt[i][j-1]][j-1];
	g(1);

	add(1);
	for(int a, b; K--;) {
		rf(a) rf(b)
		if(1 == a) {
			add(b);
		} else {
			int r = get(b);
			printf("%d\n", r);
		}
	}
	return 0;
}