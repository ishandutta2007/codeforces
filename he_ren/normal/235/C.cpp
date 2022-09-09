#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e6 + 5;
const int MAXM = 2e6 + 5;
const int MAXP = MAXN * 2;

struct SAM
{
	int len[MAXP], son[MAXP][26], fail[MAXP], pcnt;
	SAM(void){ clear();}
	inline void clear(void){ pcnt = 0; new_Node(0);}
	inline int new_Node(int _len)
	{
		len[++pcnt] = _len; fail[pcnt] = 0;
		memset(son[pcnt],0,sizeof(son[pcnt]));
		t[pcnt] = 0;
		return pcnt;
	}
	inline int get_nq(int p,int c)
	{
		int q = son[p][c];
		if(len[q] == len[p] + 1) return q;
		int nq = new_Node(len[p] + 1);
		memcpy(son[nq], son[q], sizeof(son[nq]));
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
	
	int t[MAXP];
	inline void build(char s[],int n)
	{
		clear();
		int lst = 1;
		for(int i=1; i<=n; ++i)
			lst = insert(lst, s[i] - 'a'), ++t[lst];
		
		static pii ps[MAXP];
		for(int i=1; i<=pcnt; ++i) ps[i] = make_pair(-len[i], i);
		sort(ps+1,ps+pcnt+1);
		for(int i=1; i<pcnt; ++i)
		{
			int u = ps[i].second;
			t[fail[u]] += t[u];
		}
	}
	inline pii trans(pii u,char c) const
	{
		int p = u.first, cid = c - 'a';
		while(p && !son[p][cid]) p = fail[p];
		return p? make_pair(son[p][cid], min(u.second, len[p]) + 1): make_pair(1, 0);
	}
	inline pii to_len(pii u,int k) const
	{
		int p = u.first;
		while(p != 1 && len[fail[p]] >= k) p = fail[p];
		return make_pair(p, min(u.second, len[p]));
	}
}sam;

char s[MAXN];

int main(void)
{
	int Q;
	scanf("%s%d",s+1,&Q);
	int n = strlen(s+1);
	
	sam.build(s, n);
	
	while(Q--)
	{
		static char t[MAXM];
		scanf("%s",t+1);
		int m = strlen(t+1);
		for(int i=1; i<=m; ++i) t[i+m] = t[i];
		
		pii lst = make_pair(1,0);
		for(int i=1; i<m; ++i) lst = sam.trans(lst, t[i]);
		
		int ans = 0;
		vector<int> vec;
		static bool vis[MAXP];
		for(int i=1; i<=m; ++i)
		{
			lst = sam.trans(lst, t[i + m - 1]);
			lst = sam.to_len(lst, m);
			if(lst.second >= m && !vis[lst.first])
			{
				vis[lst.first] = 1;
				vec.push_back(lst.first);
				ans += sam.t[lst.first];
			}
		}
		
		printf("%d\n",ans);
		while(vec.size()) vis[vec.back()] = 0, vec.pop_back();
	}
	return 0;
}

/*
baabaabaaa
1
aabaa
*/