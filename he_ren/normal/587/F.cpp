#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int MAXQ = 1e5 + 5;
const int MAXP = MAXN * 2;

namespace Block
{
	const int B = 300;
	int small[MAXN], big[MAXN / B + 5], n, mxb;
	void build(int _n){ n = _n; mxb = n/B;}
	inline void update(int i,int k)
	{
		int b = i / B, bR = b * B + B - 1;
		while(i<=bR) small[i] += k, ++i;
		++b;
		while(b<=mxb) big[b] += k, ++b;
	}
	inline int query(int x){ return small[x] + big[x/B];}
	inline int query(int l,int r){ return query(r) - query(l-1);}
};

namespace SAM
{
	int len[MAXP], son[MAXP][26], fail[MAXP], id[MAXP], cnt[MAXP], pcnt;
	inline int new_Node(int _len)
	{
		int u = ++pcnt; len[u] = _len;
		memset(son[u], 0, sizeof(son[u]));
		fail[u] = 0; id[u] = 0; cnt[u] = 0;
		return u;
	}
	inline void clear(void)
	{
		pcnt = 0; new_Node(0);
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
		if(son[p][c]) return get_nq(p,c);
		int np = new_Node(len[p] + 1);
		for(; p && !son[p][c]; p = fail[p]) son[p][c] = np;
		fail[np] = p? get_nq(p,c): 1;
		return np;
	}
	
	int seq[MAXP];
	void build(const string &s)
	{
		clear();
		int n = (int)s.size(), lst = 1;
		for(char c: s) ++cnt[lst = insert(lst, c - 'a')];
		
		static int bak[MAXN];
		memset(bak, 0, (n+1)<<2);
		for(int i=1; i<=pcnt; ++i) ++bak[len[i]];
		for(int i=1; i<=n; ++i) bak[i] += bak[i-1];
		for(int i=pcnt; i>=1; --i) seq[bak[len[i]]--] = i;
		
		for(int i=pcnt; i>1; --i)
		{
			int u = seq[i];
			cnt[fail[u]] += cnt[u];
		}
	}
}

namespace Trie
{
	int tr[MAXN][26], pcnt = 1;
	int insert(const string &s)
	{
		int u = 1;
		for(char c: s)
		{
			int &v = tr[u][c - 'a'];
			if(!v) v = ++pcnt;
			u = v;
		}
		return u;
	}
	int sam_pos[MAXN];
	void build_SAM(void)
	{
		SAM::clear();
		function<void(int,int)> dfs = [&] (int u,int lst)
		{
			SAM::id[lst] = u;
			sam_pos[u] = lst;
			for(int i=0; i<26; ++i) if(tr[u][i])
				dfs(tr[u][i], SAM::insert(lst, i));
		};
		dfs(1,1);
	}
}

string s[MAXN];
array<int,3> qs[MAXQ];
ll res[MAXQ];
vector<int> qid[MAXN];

int main(void)
{
	int n,Q;
	scanf("%d%d",&n,&Q);
	for(int i=1; i<=n; ++i)
	{
		static char tmp[MAXN];
		scanf("%s",tmp);
		s[i] = tmp;
	}
	for(int i=1; i<=Q; ++i)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		qs[i] = {l,r,k};
		qid[k].emplace_back(i);
	}
	
	const int B = 300;
	
	static vector<int> tr_pid[MAXN], tr_qid[MAXN];
	for(int i=1; i<=n; ++i)
	{
		if((int)s[i].size() <= B)
		{
			int u = Trie::insert(s[i]);
			tr_pid[u].emplace_back(i);
			tr_qid[u].insert(tr_qid[u].end(), qid[i].begin(), qid[i].end());
			continue;
		}
		
		if(!qid[i].size()) continue;
		
		SAM::build(s[i]);
		
		static ll sum[MAXN];
		for(int j=1; j<=n; ++j)
		{
			int u = 1;
			for(char c: s[j])
			{
				u = SAM::son[u][c - 'a'];
				if(!u) break;
			}
			sum[j] = sum[j-1] + SAM::cnt[u];
		}
		
		for(auto j: qid[i])
		{
			res[j] += sum[qs[j][1]] - sum[qs[j][0]-1];
		}
	}
	
	Trie::build_SAM();
	
	static vector<int> sam_pid[MAXP];
	for(int u=1; u<=Trie::pcnt; ++u)
		sam_pid[Trie::sam_pos[u]].swap(tr_pid[u]);
	
	static vector<int> g[MAXP];
	for(int u=2; u<=SAM::pcnt; ++u)
		g[SAM::fail[u]].emplace_back(u);
	
	Block::build(n);
	function<void(int)> dfs_trie = [&] (int u)
	{
		for(auto i: tr_qid[u])
			res[i] += Block::query(qs[i][0], qs[i][1]);
		for(int i=0; i<26; ++i) if(Trie::tr[u][i])
			dfs_trie(Trie::tr[u][i]);
	};
	function<void(int)> dfs_sam = [&] (int u)
	{
		for(int t: sam_pid[u]) Block::update(t, 1);
		if(SAM::id[u]) dfs_trie(SAM::id[u]);
		for(int v: g[u]) dfs_sam(v);
		for(int t: sam_pid[u]) Block::update(t, -1);
	};
	dfs_sam(1);
	
	for(int i=1; i<=Q; ++i)
		printf("%lld\n",res[i]);
	return 0;
}