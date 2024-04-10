#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int LB = 17 + 2;
const int inf = 0x3f3f3f3f;

int lb[MAXN];

const int MAXSZ = 2.7e5;
struct Segment_Tree
{
	int mn[MAXSZ<<1], N;
	void build(int n,int a[])
	{
		N = 1;
		while(N < n+2) N<<=1;
		for(int i=1; i<=n; ++i) mn[N+i] = a[i];
		for(int i=N-1; i>=1; --i) mn[i] = min(mn[i<<1], mn[i<<1|1]);
	}
	void update(int x,int k)
	{
		mn[x += N] = k;
		for(x>>=1; x; x>>=1) mn[x] = min(mn[x<<1], mn[x<<1|1]);
	}
	int query(int l,int r) const
	{
		int res = inf;
		for(l+=N-1, r+=N+1; l^r^1; l>>=1, r>>=1)
		{
			if(~l&1) res = min(res, mn[l^1]);
			if( r&1) res = min(res, mn[r^1]);
		}
		return res;
	}
};

namespace SA
{
	int sa[MAXN], rnk[MAXN], sa_k;
	void sa_sort(int a[],int n)
	{
		if(n == 1){ rnk[a[1]] = a+1-sa; a[1] = -1; return;}
		int p = rnk[a[rand() % n + 1] + sa_k];
		
		int i = 1, j = 1, k = n, x;
		while(i <= k)
		{
			if((x = rnk[a[i] + sa_k]) < p) swap(a[i++], a[j++]);
			else if(x > p) swap(a[i], a[k--]);
			else ++i;
		}
		
		if(j>1) sa_sort(a, j-1);
		rnk[a[j]] = x = a+k-sa;
		if(j == k) a[j] = -1;
		else while(j<k) rnk[a[++j]] = x;
		if(k<n) sa_sort(a+k, n-k);
	}
	void get_sa(char s[],int n = -1)
	{
		if(n == -1) n = strlen(s+1);
		for(int i=1; i<=n; ++i) sa[i] = i, rnk[i] = s[i];
		rnk[n+1] = 0;
		sa_k = 0; sa_sort(sa,n);
		for(int &k=sa_k=1; sa[1] > -n; k<<=1)
		{
			int len = 0;
			for(int i=1; i<=n;)
			{
				if(sa[i] < 0){ len += sa[i]; i -= sa[i]; continue;}
				if(len) sa[i+len] = len, len = 0;
				int j = rnk[sa[i]]+1;
				sa_sort(sa+i-1, j-i);
				i = j;
			}
			if(len) sa[n+1+len] = len;
		}
		for(int i=1; i<=n; ++i) sa[rnk[i]] = i;
	}
	
	int lcp[MAXN];
	void get_lcp(char s[],int n = -1)
	{
		if(n == -1) n = strlen(s+1);
		for(int i=1, k=0; i<=n; ++i)
		{
			if(rnk[i] == n){ lcp[rnk[i]] = k = 0; continue;}
			if(k) --k;
			int j = sa[rnk[i]+1];
			while(s[i+k] == s[j+k]) ++k;
			lcp[rnk[i]] = k;
		}
	}
}using namespace SA;

int n;
char s[MAXN];

int st[MAXN][LB];
inline int get_min(int l,int r)
{
	int k = lb[r-l+1];
	return min(st[l][k], st[r-(1<<k)+1][k]);
}
inline int get_lcp(int x,int y)
{
	if(x == y) return n - x + 1;
	x = rnk[x]; y = rnk[y];
	return x<y? get_min(x,y-1): get_min(y,x-1);
}

pii get_range(int x,int len)
{
	int l = x, r = x;
	for(int i=lb[l-1]; i>=0; --i)
		if(i<=lb[l-1] && st[l-(1<<i)][i] >= len)
			l -= 1<<i;
	for(int i=lb[n-r]; i>=0; --i)
		if(i<=lb[n-r] && st[r][i] >= len)
			r += 1<<i;
	return make_pair(l,r);
}

Segment_Tree tree;
int get_res(int x)
{
	int res = 1, len = 1;
	while(1)
	{
		pii rng = get_range(rnk[x], len);
		int y = tree.query(rng.first, rng.second);
		if(y > n) return res;
		int nlen = get_lcp(x,y);
		
		int tmp = (nlen - len) / (y - x) + 1;
		res += tmp;
		len += tmp * (y - x);
	}
}

int main(void)
{
	lb[0] = -1;
	for(int i=2; i<MAXN; ++i) lb[i] = lb[i>>1] + 1;
	
	scanf("%d%s",&n,s+1);
	
	get_sa(s,n); get_lcp(s,n);
	
	for(int i=n; i>=1; --i)
	{
		st[i][0] = lcp[i];
		for(int j=1; i+(1<<j)-1 <= n; ++j)
			st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
	}
	
	tree.build(n, sa);
	
	int ans = 0;
	for(int i=1; i<=n; ++i)
	{
		tree.update(rnk[i], inf);
		ans = max(ans, get_res(i));
	}
	printf("%d",ans);
	return 0;
}