#include <bits/stdc++.h>
#define MN 100010

using namespace std;

struct change {
	int *where, from;
	void unroll() {*where = from;};
};

struct union_find {
	int bipartite;
	vector<int> pai, rnk;
	union_find() {
		bipartite = 1;
		pai.resize(2*MN);
		rnk.resize(2*MN);
		for(int i = 0; i < 2*MN; i++)
			pai[i] = i, rnk[i] = 0;
	}
	int find(int x, vector<change> &buffer) {
		if(x == pai[x]) return x;
		int p = find(pai[x], buffer);
		buffer.push_back({&pai[x], pai[x]});
		return pai[x] = p;
	}
	void merge(int a, int b, vector<change> &buffer) {
		a = find(a, buffer), b = find(b, buffer);
		if(a == b) return;
		if(rnk[a] < rnk[b]) swap(a, b);
		buffer.push_back({&pai[b], pai[b]});
		pai[b] = a;
		if(rnk[a] == rnk[b]) {
			buffer.push_back({&rnk[a], rnk[a]});
			rnk[a]++;
		}
		if(a == find(a^1, buffer) || b == find(b^1, buffer)) {
			buffer.push_back({&bipartite, bipartite});
			bipartite = 0;
		} 
	}
};

struct node {
	vector<pair<int, int> > edges[4*MN];
	union_find DSU;
	
	void add(int id, int l, int r, int a, int b, int lq, int rq) {
		if(lq <= l && r <= rq) edges[id].emplace_back(a, b);
		else {
			int m = (l+r)>>1;
			if(lq <= m) add(id<<1, l, m, a, b, lq, rq);
			if(rq > m) add(id<<1|1, m+1, r, a, b, lq, rq);
		}
	}
	
	void roll(int id, vector<change> &buffer) {
		for(auto edge : edges[id])
			DSU.merge(edge.first, edge.second, buffer);
	}
	
	void walk(int id, int l, int r) {
		vector<change> buffer;
		roll(id, buffer);
		if(l == r) {
			printf("%s\n", DSU.bipartite ? "YES" : "NO");
		} else {
			int m = (l+r)>>1;
			walk(id<<1, l, m);
			walk(id<<1|1, m+1, r);
		}
		while(!buffer.empty()) {
			buffer.back().unroll();
			buffer.pop_back();
		}
	}
} root;

int main() {
	int n, q, a, b;
	scanf("%d %d", &n, &q);
	
	map<pair<int, int>, int> edg;
	for(int i = 1; i <= q; i++) {
		scanf("%d %d", &a, &b);
		if(edg.count({a, b})) {
			root.add(1, 1, q, a*2, b*2+1, edg[{a, b}], i-1);
			root.add(1, 1, q, a*2+1, b*2, edg[{a, b}], i-1);
			edg.erase({a, b});
		} else edg[{a, b}] = i;
	}
	for(auto e : edg) {
		a = e.first.first; b = e.first.second;
		root.add(1, 1, q, a*2, b*2+1, edg[{a, b}], q);
		root.add(1, 1, q, a*2+1, b*2, edg[{a, b}], q);
	}
	
	root.walk(1, 1, q);
	
	return 0;
}