#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;


const int nax = 200 * 1000 + 10, qax = 500 * 1000 + 10;
int n, m, q;
int p[nax], last;
pi e[300 * 1000 + 10];
int t[300 * 1000 + 10], zap[qax];
int pr[nax*2], siz[nax*2];
vi g[nax*2];
vi ev[qax];
pi T[(1<<20)];
int R;

void update(int a, int x) {
	a += R;
	T[a] = {x, a - R};
	while(a > 1) {
		a/=2;
		T[a] = max(T[2*a], T[2*a+1]);
	}
}

pi query(int a, int b) {
	a += R; b += R;
	pi w = max(T[a], T[b]);
	while(a/2!=b/2) {
		if(a%2==0) w=max(w, T[a+1]);
		if(b%2==1) w=max(w, T[b-1]);
		a/=2;
		b/=2;
	}
	return w;
}

int Fund(int x) {
	if(pr[x] != x) {
		pr[x] = Fund(pr[x]);
	}
	return pr[x];
}

void Onion(int a, int b) {
	a = Fund(a); b = Fund(b);
	if(a == b) return;
	last++;
	pr[a] = last;
	pr[b] = last;
	pr[last] = last;
	g[last].PB(a);
	g[last].PB(b);
}

int in[2*nax], out[2*nax], nr = 1;
pi prz[qax];

void dfs(int x) {
	in[x] = nr++;
	for(int nbh : g[x]) {
		dfs(nbh);
	}
	out[x] = nr;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> q;
	for(int i = 1; i <= n; ++i) {
		cin >> p[i];
		pr[i] = i;
	}
	last = n;
	for(int i = 1; i <= m; ++i) {
		cin >> e[i].ST >> e[i].ND;
	}
	for(int i = 1; i <= m; ++i) {
		t[i] = q + 1;
	}
	for(int i = 1; i <= q; ++i) {
		int typ, a;
		cin >> typ >> a;
		if(typ == 1) {
			zap[i] = a;
		} else {
			t[a] = i;
		}
	}
	for(int i = 1; i <= m; ++i) {
		ev[t[i]].PB(i);
	}
	for(int i = q + 1; i >= 1; --i) {
		if(zap[i] != 0) {
			zap[i] = Fund(zap[i]);
		}
		for(int x : ev[i]) {
			Onion(e[x].ST, e[x].ND);
		}
	}
	for(int i = last; i>=1; --i) {
		if(in[i] == 0) dfs(i);
	}
	R = 1;
	while(R <= last) {
		R *= 2;
	}
	for(int i = 1; i <= n; ++i) {
		update(in[i], p[i]);
	}
	for(int i = 1; i <= q; ++i) {
		if(zap[i] != 0) {
			pi w = query(in[zap[i]], out[zap[i]] - 1);
			cout << w.ST << "\n";
			update(w.ND, 0);
		}
	}
	
	
}