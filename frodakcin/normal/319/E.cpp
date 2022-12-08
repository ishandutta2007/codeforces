#include <iostream>
#include <cstdio>

#include <vector>
#include <algorithm>

#include <cassert>

using namespace std;

const int MN = 1e5 + 100;

using vi = vector<int>;
#define pb push_back
#define sz size()
#define ALL(X) X.begin(),X.end()
struct ST
{
public:
	vi v;
	ST * l, * r;
	ST(void)
	{
		l = nullptr, r = nullptr;
		v.clear();
	}
};

ST * nd_pool;
int ndc;
const int R = 1e5;
ST * nn(void)
{
	if(!ndc)
		nd_pool = new ST[ndc = R];
	return nd_pool + --ndc;
}
ST * root;

int N;
vi vals;
int X;
int Q[MN][3];

template<int MS = MN> struct DSU
{
public:
	int p[MS], k[MS];
	int l[MS], r[MS];
	void init(int s)
	{
		for(int i = 1;i <= s;i++)
			p[i] = i, k[i] = 0, l[i] = r[i] = -1;
	}
	void set(int i, int vl, int vr)
	{
		l[i] = vl;
		r[i] = vr;
	}
	int find(int n)
	{
		if(p[n] == n)
			return n;
		else
			return p[n] = find(p[n]);
	}
	int operator [] (const int& n)
	{
		return find(n);
	}
	bool merge(int a, int b)
	{
		a = find(a), b = find(b);
		if(a == b) return 0;
		if(k[b] > k[a]) swap(a, b);
		p[b] = a, k[a] += k[a]==k[b], k[b] = -1;
		l[a] = min(l[a], l[b]), r[a] = max(r[a], r[b]);
		return 1;
	}
};
DSU<> dsu;

void query(int q, int v, ST * n, int l, int r)
{
	if(!n)
		return;
	for(int x : n->v)
		dsu.merge(v, x);
	n->v.clear();
	if(r-l>1)
	{
		int m = l + (r-l>>1);
		if(q < m) query(q, v, n->l, l, m);
		else query(q, v, n->r, m, r);
	}
}
void fill(int ql, int qr, int v, ST *& n, int l, int r)
{
	if(!n)
		n = nn();
	if(ql <= l&&r <= qr)
		n->v.pb(v);
	else
	{
		int m = l + (r-l>>1);
		if(ql < m) fill(ql, qr, v, n->l, l, m);
		if(m < qr) fill(ql, qr, v, n->r, m, r);
	}
}
bool can_to(int a, int b, int c, int d)
{
	cerr << a<< " " << b << " " << c << " " << d << "\n";
	return c < a&&a < d||c < b&&b < d;
}
int w[MN][2];
int main(void)
{
	root = nn();	//this line is probably not needed
	scanf("%d", &N);
	for(int i = 0;i < N;i++)
	{
		scanf("%d%d%d", Q[i], Q[i]+1, Q[i]+2);
		if(Q[i][0] == 1)
			vals.pb(Q[i][1]), vals.pb(Q[i][2]);
	}
	sort(ALL(vals));
	vals.resize(distance(vals.begin(), unique(ALL(vals))));
	X = vals.sz;
	dsu.init(N);
	for(int i = 0, j = 1;i < N;i++)
		if(Q[i][0] == 1)
		{
			for(int k : {1,2})
				Q[i][k] = distance(vals.begin(), lower_bound(ALL(vals), Q[i][k]));
			dsu.set(j, Q[i][1], Q[i][2]);
			w[j][0] = Q[i][1], w[j][1] = Q[i][2];
			query(Q[i][1], j, root, 0, X);
			query(Q[i][2], j, root, 0, X);
			int t = dsu[j];
			if(dsu.l[t] + 1 < dsu.r[t])
				fill(dsu.l[t] + 1, dsu.r[t], t, root, 0, X);
			j++;
		}
		else
			if(dsu[Q[i][1]]==dsu[Q[i][2]]||can_to(w[Q[i][1]][0], w[Q[i][1]][1], dsu.l[dsu[Q[i][2]]], dsu.r[dsu[Q[i][2]]]))
				printf("YES\n");
			else
				printf("NO\n");
	return 0;
}