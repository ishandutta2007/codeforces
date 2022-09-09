#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e6 + 5;
const int inf = 0x3f3f3f3f;

namespace SA
{
	int rnk1[MAXN], rnk2[MAXN];
	int sa[MAXN], *rnk = rnk1, *lst_rnk = rnk2, lcp[MAXN], sa_k;
	inline bool sa_same(int x,int y){ return lst_rnk[x] == lst_rnk[y] && lst_rnk[x+sa_k] == lst_rnk[y+sa_k];}
	void build(char s[],int n)
	{
		static int t[MAXN];
		int m = 3e2; rnk1[0] = rnk2[0] = rnk1[n+1] = rnk2[n+1] = -1;
		memset(t,0,(m+1)<<2);
		for(int i=1; i<=n; ++i) ++t[rnk[i] = s[i]];
		for(int i=1; i<=m; ++i) t[i] += t[i-1];
		for(int i=n; i>=1; --i) sa[t[rnk[i]]--] = i;
		if(n == 1) rnk[1] = 1;
		if(n == m) ++m;
		for(int &k=sa_k=1; m!=n; k<<=1)
		{
			static int id[MAXN];
			int *w = lst_rnk, cur = 0;
			for(int i=n-k+1; i<=n; ++i) id[++cur] = i;
			for(int i=1; i<=n; ++i) if(sa[i] > k) id[++cur] = sa[i] - k;
			
			memset(t,0,(m+1)<<2);
			for(int i=1; i<=n; ++i) ++t[w[i] = rnk[id[i]]];
			for(int i=1; i<=m; ++i) t[i] += t[i-1];
			for(int i=n; i>=1; --i) sa[t[w[i]]--] = id[i];
			
			m = 0; swap(rnk, lst_rnk);
			for(int i=1; i<=n; ++i)
				rnk[sa[i]] = sa_same(sa[i], sa[i-1])? m: ++m;
		}
		
		for(int i=1,k=0; i<=n; ++i)
		{
			if(rnk[i] == n){ lcp[n] = k = 0; continue;}
			if(k) --k;
			int j = sa[rnk[i]+1];
			while(s[i+k] == s[j+k]) ++k;
			lcp[rnk[i]] = k;
		}
	}
} using SA::sa; using SA::rnk; using SA::lcp;

char s[MAXN];
int f[MAXN], g[MAXN];

bool chk(int l,int r,char c)
{
	for(int i=l; i<=r; ++i)
		if(s[i] != c) return 0;
	return 1;
}

void solve(void)
{
	int n,d;
	scanf("%d%d%s",&n,&d,s+1);
	
	SA::build(s,n);
	
//	for(int i=1; i<=n; ++i)
//	{
//		printf("%2d: %2d %2d  ",i,sa[i],lcp[i]);
//		for(int j=sa[i]; j<=n; ++j) putchar('1' + '0' - s[j]); printf("\n");
//	}
	
	for(int i=1; i<=n; ++i) s[i] = '1' + '0' - s[i];
	for(int i=1; i<=n; ++i)
		f[i] = s[i] == '1'? f[i-1] + 1: 0,
		g[i] = s[i] == '0'? g[i-1] + 1: 0;
	
	int cur = inf, j = n+1;
	for(int i=n; i>=1; --i)
	{
		cur = min(cur, lcp[i]);
		if(sa[i] + d - 1 > n) continue;
		if(j > n)
		{
			if(!chk(sa[i], sa[i] + d - 1, '0')){ cout << "YES\n" << string(d,'0') << endl; return;}
			j = i; cur = inf; continue;
		}
		if(cur >= d){ cur = inf; j = i; continue;}
		
		int len = f[sa[j] + d - 1], len2 = g[sa[i] + d - 1];
		len = min(len, d); len2 = min(len2, d);
		if(len2 == len && len + cur + 1 == d){ j = i; cur = inf; continue;}
		
		int l = sa[j], r = sa[j] + d - 1;
		for(int k=0; k<len; ++k) s[r-k] = '0';
		s[r-len] = '1';
		cout << "YES\n" << string(s+l, s+r+1) << endl;
		return;
	}
	
	int l = sa[j], r = sa[j] + d - 1, len = f[r];
	len = min(len, d);
	if(len == d){ printf("NO\n"); return;}
	for(int k=0; k<len; ++k) s[r-k] = '0';
	s[r-len] = '1';
	cout << "YES\n" << string(s+l, s+r+1) << endl;
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}

/*
1
3 1
100

*/