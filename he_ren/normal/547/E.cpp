#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXP = MAXN * 2;
const int MAXSEG = MAXN * 18 * 2;

namespace SegT
{
	int ls[MAXSEG], rs[MAXSEG], sum[MAXSEG], pcnt = 0, n;
	#define lson(u) ls[u],l,mid
	#define rson(u) rs[u],mid+1,r
	void insert(int &u,int l,int r,int q)
	{
		if(!u) u = ++pcnt;
		++sum[u];
		if(l == r) return;
		int mid = (l+r)>>1;
		if(q<=mid) insert(lson(u),q);
		else insert(rson(u),q);
	}
	void merge(int &u,int l,int r,int v1,int v2)
	{
		if(!v1 || !v2){ u = v1 | v2; return;}
		u = ++pcnt; sum[u] = sum[v1] + sum[v2];
		if(l == r) return;
		int mid = (l+r)>>1;
		merge(lson(u),ls[v1],ls[v2]);
		merge(rson(u),rs[v1],rs[v2]);
	}
	int query(int u,int l,int r,int ql,int qr)
	{
		if(!u) return 0;
		if(ql<=l && r<=qr) return sum[u];
		int mid = (l+r)>>1, res = 0;
		if(ql<=mid) res += query(lson(u),ql,qr);
		if(mid<qr) res += query(rson(u),ql,qr);
		return res;
	}
	
	inline void insert(int &u,int q){ insert(u,1,n,q);}
	inline void merge(int &u,int v1,int v2){ merge(u,1,n,v1,v2);}
	inline int query(int u,int ql,int qr){ return ql<=qr? query(u,1,n,ql,qr): 0;}
}

namespace SAM
{
	int son[MAXP][26], len[MAXP], fail[MAXP], rt[MAXP], pcnt = 1;
	inline int new_Node(int _len)
	{
		len[++pcnt] = _len;
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
		if(son[p][c]) return get_nq(p, c);
		int np = new_Node(len[p] + 1);
		for(; p && !son[p][c]; p = fail[p]) son[p][c] = np;
		fail[np] = p? get_nq(p, c): 1;
		return np;
	}
	
	inline void update(int u,const vector<int> &vec)
	{
		for(int x: vec) SegT::insert(rt[u], x);
	}
	inline int query(int u,int ql,int qr)
	{
		return SegT::query(rt[u], ql, qr);
	}
	
	int seq[MAXP];
	inline void build(void)
	{
		int mx = *max_element(len+1,len+pcnt+1);
		static int bak[MAXN];
		memset(bak, 0, (mx+1)<<2);
		for(int i=1; i<=pcnt; ++i) ++bak[len[i]];
		for(int i=1; i<=mx; ++i) bak[i] += bak[i-1];
		
		for(int i=pcnt; i>=1; --i) seq[bak[len[i]]--] = i;
		for(int i=pcnt; i>1; --i)
		{
			int u = seq[i], v = fail[u];
			SegT::merge(rt[v], rt[v], rt[u]);
		}
	}
}

namespace Trie
{
	int son[MAXN][26], pcnt = 1;
	vector<int> val[MAXN];
	int insert(const char s[],int id)
	{
		int u = 1;
		val[1].push_back(id);
		for(int i=1; s[i]; ++i)
		{
			int c = s[i] - 'a';
			int &v = son[u][c];
			if(!v) v = ++pcnt;
			u = v; val[u].push_back(id);
		}
		return u;
	}
	
	int pt[MAXN];
	void dfs(int u,int p)
	{
		pt[u] = p;
		SAM::update(p, val[u]);
		for(int i=0; i<26; ++i) if(son[u][i])
			dfs(son[u][i], SAM::insert(p, i));
	}
	void build(void)
	{
		dfs(1,1);
		SAM::build();
	}
	int query(int u,int ql,int qr)
	{
		return SAM::query(pt[u], ql, qr);
	}
}

int main(void)
{
	int n,Q;
	scanf("%d%d",&n,&Q);
	SegT::n = n;
	static int pt[MAXN];
	for(int i=1; i<=n; ++i)
	{
		static char s[MAXN];
		scanf("%s",s+1);
		pt[i] = Trie::insert(s, i);
	}
	
	Trie::build();
	
	while(Q--)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",Trie::query(pt[k], l, r));
	}
	return 0;
}