#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e5 + 5;
const int MAXM = 5e4 + 5;
const int MAXL = 1e5 + 5;
const int MAXP = MAXL * 2;

int lb[MAXP];

namespace SegT
{
	const int MAXP = ::MAXP * 40;
	int ls[MAXP], rs[MAXP], pcnt = 0;
	pii mx[MAXP];
	#define lson(u) ls[u],l,mid
	#define rson(u) rs[u],mid+1,r
	inline void push_up(int u){ mx[u] = max(mx[ls[u]], mx[rs[u]]);}
	inline int copy(int u)
	{
		++pcnt; ls[pcnt] = ls[u]; rs[pcnt] = rs[u]; mx[pcnt] = mx[u];
		return pcnt;
	}
	void update(int &u,int l,int r,int q)
	{
		u = copy(u);
		if(l == r){ ++mx[u].first; mx[u].second = -l; return;}
		int mid = (l+r)>>1;
		if(q<=mid) update(lson(u),q);
		else update(rson(u),q);
		push_up(u);
	}
	void merge(int &u,int v,int l,int r)
	{
		if(!u || !v){ u = u | v; return;}
		u = copy(u);
		if(l == r){ mx[u].first += mx[v].first; return;}
		int mid = (l+r)>>1;
		merge(ls[u],lson(v)); merge(rs[u],rson(v));
		push_up(u);
	}
	pii query(int u,int l,int r,int ql,int qr)
	{
		if(ql<=l && r<=qr) return mx[u];
		int mid = (l+r)>>1;
		pii res = make_pair(0,0);
		if(ql<=mid) res = max(res, query(lson(u),ql,qr));
		if(mid<qr) res = max(res, query(rson(u),ql,qr));
		return res;
	}
};

struct SAM
{
	int len[MAXP], son[MAXP][27], fail[MAXP], pcnt;
	SAM(void){ clear();}
	inline void clear(void){ pcnt = 0; new_Node(0);}
	inline int size(void) const { return pcnt;}
	inline int new_Node(int _len)
	{
		len[++pcnt] = _len; fail[pcnt] = 0;
		memset(son[pcnt],0,sizeof(son[pcnt]));
		return pcnt;
	}
	inline int get_nq(int p,int c)
	{
		int q = son[p][c];
		if(len[q] == len[p] + 1) return q;
		int nq = new_Node(len[p] + 1);
		memcpy(son[nq], son[q], sizeof(son[q]));
		fail[nq] = fail[q]; fail[q] = nq;
		for(; p && son[p][c] == q; p = fail[p]) son[p][c] = nq;
		return nq;
	}
	inline int insert(int p,int c)
	{
		int np = new_Node(len[p] + 1);
		for(; p && !son[p][c]; p = fail[p]) son[p][c] = np;
		fail[np] = p? get_nq(p, c): 1;
		return np;
	}
	inline pii trans(pii lst,int c)
	{
		int p = lst.first, pl = lst.second;
		while(p && !son[p][c]) p = fail[p], pl = len[p];
		return p? make_pair(son[p][c], pl + 1): make_pair(1, 0);
	}
}sam;

int m;
char s[MAXN];
string t[MAXM];

int val[MAXP], rt[MAXP];
vector<int> g[MAXP];
int dep[MAXP], anc[MAXP][20];

void dfs_g(int u)
{
	for(int i=1; i<=lb[dep[u]]; ++i)
		anc[u][i] = anc[anc[u][i-1]][i-1];
	if(val[u]) SegT::update(rt[u],1,m,val[u]);
	for(int i=0; i<(int)g[u].size(); ++i)
	{
		int v = g[u][i];
		anc[v][0] = u; dep[v] = dep[u] + 1;
		dfs_g(v);
		SegT::merge(rt[u],rt[v],1,m);
	}
}

pii pos[MAXN];
inline int get_p(int l,int r)
{
	int need = r - l + 1, p = pos[r].first;
	for(int i=lb[dep[p]]; i>=0; --i)
		if(i<=lb[dep[p]] && sam.len[anc[p][i]] >= need)
			p = anc[p][i];
	return p;
}

int main(void)
{
	lb[0] = -1;
	for(int i=1; i<MAXP; ++i) lb[i] = lb[i>>1] + 1;
	
	scanf("%s%d",s+1,&m);
	int n = strlen(s+1);
	for(int i=1; i<=m; ++i) cin >> t[i];
	
	int lst = 1;
	for(int i=1; i<=m; ++i)
	{
		for(int j=0; j<(int)t[i].size(); ++j)
		{
			lst = sam.insert(lst, t[i][j] - 'a');
			val[lst] = i;
		}
		lst = sam.insert(lst, 26);
	}
	
	for(int i=2; i<=sam.size(); ++i)
		g[sam.fail[i]].push_back(i);
	dfs_g(1);
	
	pos[0] = make_pair(1,0);
	for(int i=1; i<=n; ++i)
		pos[i] = sam.trans(pos[i-1], s[i] - 'a');
	
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int l,r,pl,pr;
		scanf("%d%d%d%d",&l,&r,&pl,&pr);
		if(pos[pr].second < pr - pl + 1)
		{
			printf("%d 0\n",l);
			continue;
		}
		
		int p = get_p(pl, pr);
		pii mx = SegT::query(rt[p],1,m, l,r);
		printf("%d %d\n",max(-mx.second,l),mx.first);
	}
	return 0;
}