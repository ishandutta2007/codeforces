#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int MAXP = MAXN * 2;

struct SAM
{
	int len[MAXP], son[MAXP][26], fail[MAXP], pcnt;
	SAM(void){ clear();}
	inline void clear(void){ pcnt = 0; new_Node(0);}
	inline int new_Node(int _len)
	{
		len[++pcnt] = _len; fail[pcnt] = 0;
		memset(son[pcnt], 0, sizeof(son[pcnt]));
		t[pcnt] = 0;
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
	
	int t[MAXP];
	inline ll build(char s[],int n)
	{
		clear();
		int lst = 1;
		for(int i=1; i<=n; ++i)
			lst = insert(lst, s[i] - 'a'), ++t[lst];
		
		static pii ps[MAXP];
		for(int i=1; i<=pcnt; ++i) ps[i] = make_pair(-len[i], i);
		sort(ps+1, ps+pcnt+1);
		ll res = 0;
		for(int i=1; i<pcnt; ++i)
		{
			int u = ps[i].second;
			t[fail[u]] += t[u];
			res += (ll)(len[u] - len[fail[u]]) * t[u] * (t[u] + 1) / 2;
		}
		return res;
	}
}sam;

char s[MAXN];

int main(void)
{
	scanf("%s",s+1);
	int n = strlen(s+1);
	
	printf("%lld",sam.build(s, n));	
	return 0;
}