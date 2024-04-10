#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
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
	inline ll build(char s[],char fob[],int n)
	{
		clear();
		int lst = 1;
		for(int i=1; i<=n; ++i)
		{
			lst = insert(lst, s[i] - 'a');
			if(fob[i] != '1') ++t[lst];
		}
		
		static int bac[MAXN], seq[MAXP];
		memset(bac,0,(n+1)<<2);
		for(int i=1; i<=pcnt; ++i) ++bac[len[i]];
		for(int i=1; i<=n; ++i) bac[i] += bac[i-1];
		for(int i=pcnt; i>=1; --i) seq[bac[len[i]]--] = i;
		
		ll res = 0;
		for(int i=pcnt; i>1; --i) t[fail[seq[i]]] += t[seq[i]];
		for(int i=1; i<=pcnt; ++i)
			res = max(res, (ll)t[i] * len[i]);
		return res;
	}
}sam;

char s[MAXN], fob[MAXN];

int main(void)
{
	int n;
	scanf("%d%s%s",&n,s+1,fob+1);
	
	printf("%lld",sam.build(s,fob,n));
	return 0;
}