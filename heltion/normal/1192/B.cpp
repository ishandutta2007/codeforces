#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 120000;
struct edge{
	int u, v;
	LL e;
}E[maxn];
struct ch{
	int id, u, L, R;
};
vector<int> G[maxn];
vector<ch> CH[maxn];
bool vis[maxn];
int sz[maxn], ms[maxn], root, idn, inn;
multiset<LL, greater<LL>> fans, sans[maxn];
int tL[maxn], tR[maxn], tU[maxn];
LL added[maxn << 6], ma[maxn << 6];
void froot(int u, int pa = 0){
	ms[u] = 0;
	sz[u] = 1;
	for(int i : G[u]){
		int v = u ^ E[i].u ^ E[i].v;
		if(vis[v] or v == pa) continue;
		froot(v, u);
		sz[u] += sz[v];
		ms[u] = max(ms[u], sz[v]);
	}
	ms[u] = max(ms[u], ms[0] - sz[u]);
	if(ms[u] < ms[root]) root = u;
}
void DFS(int u, int pa){
	bool in = true;
	for(int i : G[u]){
		int v = u ^ E[i].u ^ E[i].v;
		if(vis[v] or v == pa) continue;
		int L = inn + 1;
		DFS(v, u);
		CH[i].push_back({idn, root, L, inn}); 
		in = false;
	}
	if(in) inn += 1;
}
void DFS(int u){
	vis[u] = true;
	for(int i : G[u]){
		int v = u ^ E[i].u ^ E[i].v;
		if(vis[v]) continue;
		idn += 1;
		tU[idn] = u;
		tL[idn] = inn + 1;
		DFS(v, u);
		tR[idn] = inn;
		CH[i].push_back({idn, u, tL[idn], tR[idn]});
	}
	for(int i : G[u]){
		int v = u ^ E[i].u ^ E[i].v;
		if(vis[v]) continue;
		ms[root = 0] = sz[v];
		froot(v);
		DFS(root);
	}
}
#define ls (v << 1)
#define rs ((v << 1) | 1)
#define tm ((tl + tr) >> 1)
void add(int v, LL d){
	added[v] += d;
	ma[v] += d;
}
void push_down(int v){
	add(ls, added[v]);
	add(rs, added[v]);
	added[v] = 0;
}
void add(int v, int tl, int tr, int L, int R, LL d){
	if(tl >= L and tr <= R) add(v, d);
	else{
		push_down(v);
		if(L <= tm) add(ls, tl, tm, L, R, d);
		if(R > tm) add(rs, tm + 1, tr, L, R, d);
		ma[v] = max(ma[ls], ma[rs]);
	}
}
LL query(int v, int tl, int tr, int L, int R){
	if(tl >= L and tr <= R) return ma[v];
	push_down(v);
	LL res = 0;
	if(L <= tm) res = max(res, query(ls, tl, tm, L, R));
	if(R > tm) res = max(res, query(rs, tm + 1, tr, L, R));
	return res;
}
LL ma2(LL u){
	if(sans[u].empty()) return 0;
	LL res = 0, c = 0;
	for(auto it = sans[u].begin(); it != sans[u].end() and c < 2; it ++, c += 1) res += *it;
	return res;
}
int main(){
	int n, q;
	LL w;
	cin >> n >> q >> w;
	for(int i = 0; i < n - 1; i += 1){
		cin >> E[i].u >> E[i].v >> E[i].e;
		G[E[i].u].push_back(i);
		G[E[i].v].push_back(i);
	}
	ms[0] = n;
	froot(1);
	DFS(root);
	for(int i = 0; i < n - 1; i += 1)
		for(auto ch : CH[i]){
			add(1, 1, inn, ch.L, ch.R, E[i].e);
		}
	for(int i = 1; i <= idn; i += 1) sans[tU[i]].insert(query(1, 1, inn, tL[i], tR[i]));
	for(int i = 1; i <= n; i += 1) fans.insert(ma2(i));
	LL last = 0;
	for(int i = 0; i < q; i += 1){
		int d;
		LL e;
		cin >> d >> e;
		d = (d + last) % (n - 1);
		e = (e + last) % w;
		for(auto ch : CH[d]){
			fans.erase(fans.find(ma2(ch.u)));
			sans[ch.u].erase(sans[ch.u].find(query(1, 1, inn, tL[ch.id], tR[ch.id])));
			add(1, 1, inn, ch.L, ch.R, e - E[d].e);
			sans[ch.u].insert(query(1, 1, inn, tL[ch.id], tR[ch.id]));
			fans.insert(ma2(ch.u));
		}
		E[d].e = e;
		cout << (last = *fans.begin()) << "\n";
	}
}