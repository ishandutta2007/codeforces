#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 120000;
struct edge{int v,w;edge(int v, int w):v(v),w(w){}};
struct node{int u,d,s;node(int u, int d, int s):u(u),d(d),s(s){}};
bitset<maxn> done;
int maxs[maxn], sz[maxn], tag[maxn << 2], ord[maxn], tsz[maxn], w[maxn],
	ansp, ansu, ansv, tmpu, tmpv, maxd, ll, rr, rt, tot_sz, n;
vector<edge> G[maxn];
vector<node> P[maxn];
void getrt(int u, int par){
	maxs[u] = 0;
	sz[u] = 1;
	for(const edge &e : G[u])
		if(e.v != par and not done.test(e.v)){
			getrt(e.v, u);
			sz[u] += sz[e.v];
			maxs[u] = max(maxs[u], sz[e.v]);
		}
	maxs[u] = max(maxs[u], tot_sz - sz[u]);
	if(maxs[u] < maxs[rt]) rt = u;
}
void DFS(int num, int u, int par, int d, int M, int s){
	maxd = max(maxd, d);
	sz[u] = 1;
	P[num].push_back(node(u, d, s)); 
	for(const edge &e : G[u]) if(e.v != par and not done.test(e.v)){
		sz[u] += sz[e.v];
		DFS(num, e.v, u, d + 1, M, s + (e.w >= M ? 1 : -1));
	}
}
void clear(int o, int l, int r){
	tag[o] = - maxn;
	if(l != r){
		int m = (l + r) >> 1;
		clear(o * 2, l, m);
		clear(o * 2 + 1, m + 1, r);
	}
}
int query(int o, int l, int r, int L, int R){
	if(l >= L and r <= R) return tag[o];
	int m = (l + r) >> 1, res = -maxn;
	if(L <= m) res = max(res, query(o * 2, l, m, L, R));
	if(R > m) res = max(res, query(o * 2 + 1, m + 1, r, L, R));
	return res;
}
void update(int o, int l, int r, int x, int v){
	if(l == r) tag[o] = max(tag[o], v);
	else{
		int m = (l + r) >> 1;
		if(x <= m) update(o * 2, l, m, x, v);
		else update(o * 2 + 1, m + 1, r, x, v);
		tag[o] = max(tag[o * 2], tag[o * 2 + 1]);
 	}
}
void CD(int u){
	//cout << "CD" << " " << u << endl;
	done.set(u);
	int L = ansp, R = n + 1;
	while(L + 1 < R){
		int M = w[(L + R) >> 1], ok = 0, num = 0;
		maxd = 1;
		for(const edge &e : G[u]) if(not done.test(e.v)){
			num += 1;
			P[num].clear();
			DFS(num, e.v, 0, 1, M, e.w >= M ? 1 : - 1);
			tsz[num] = sz[e.v];
			ord[num] = num;
		}
		sort(ord + 1, ord + num + 1, [&](const int &a, const int &b){
			return tsz[a] < tsz[b];
		});
		clear(1, 1, maxd); 
		for(int i = 1; i <= num and not ok; i += 1){
			for(const node &p : P[ord[i]]){
				if(p.d >= ll and p.d <= rr and p.s >= 0){
					ok = 1;
					ansu = u;
					ansv = p.u;
					break;
				}
				if(i > 1){
					int L = max(1, ll - p.d), R = min(maxd, rr - p.d);
					if(R < L) continue;
					int x = query(1, 1, maxd, L, R);
					if(p.s + x >= 0)
						for(int j = 1; j < i and not ok; j += 1)
							for(const node &q : P[ord[j]])
								if(q.d + p.d >= ll and q.d + p.d <= rr and p.s + q.s >= 0){
									ansu = p.u;
									ansv = q.u;
									ok = 1;
									break;
								}
				}
			}
			if(not ok) for(const node &p : P[ord[i]])
				update(1, 1, maxd, p.d, p.s);
		}
		//cout << M << " " << ok << endl;
		if(ok) L = (L + R) >> 1;
		else R = (L + R) >> 1;
	}
	ansp = L;
	for(const edge &e : G[u]) if(sz[e.v] >= ll and not done.test(e.v)){
		maxs[rt = 0] = tot_sz = sz[e.v];
		getrt(e.v, 0);
		CD(rt);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> ll >> rr;
	for(int i = 1; i < n; i += 1){
		int a, b, c;
		cin >> a >> b >> c;
		G[a].push_back(edge(b, c));
		G[b].push_back(edge(a, c));
		w[i] = c;
	}
	sort(w + 1, w + n + 1);
	maxs[0] = tot_sz = n;
	getrt(1, 0);
	CD(rt);
	cout << ansu << " " << ansv;
}