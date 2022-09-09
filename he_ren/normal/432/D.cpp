#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int LB = 17 + 2;

int lb[MAXN];

int sa[MAXN], rnk[MAXN], lst_rk[MAXN];
inline bool sa_same(int x,int y,int k){ return lst_rk[x] == lst_rk[y] && lst_rk[x+k] == lst_rk[y+k];}
void get_sa(char s[],int n = -1)
{
	if(n == -1) n = strlen(s+1);
	int m = 125;
	static int t[MAXN];
	for(int i=1; i<=n; ++i) ++t[rnk[i] = s[i]];
	for(int i=1; i<=m; ++i) t[i] += t[i-1];
	for(int i=n; i>=1; --i) sa[t[rnk[i]]--] = i;
	
	if(n == 1){ rnk[1] = sa[1] = 1; return;}
	for(int k=1; k<n; k<<=1)
	{
		static int id[MAXN], w[MAXN];
		int cur = 0;
		for(int i=n-k+1; i<=n; ++i) id[++cur] = i;
		for(int i=1; i<=n; ++i)
			if(sa[i] > k) id[++cur] = sa[i] - k;
		
		for(int i=0; i<=m; ++i) t[i] = 0;
		for(int i=1; i<=n; ++i) ++t[w[i] = rnk[id[i]]];
		for(int i=1; i<=m; ++i) t[i] += t[i-1];
		for(int i=n; i>=1; --i) sa[t[w[i]]--] = id[i];
		
		m = 0;
		for(int i=1; i<=n; ++i) lst_rk[i] = rnk[i];
		for(int i=1; i<=n; ++i)
			rnk[sa[i]] = sa_same(sa[i], sa[i-1], k)? m: ++m;
	}
}

int lcp[MAXN];
void get_lcp(char s[],int n = -1)
{
	if(n == -1) n = strlen(s+1);
	for(int i=1; i<=n; ++i) if(rnk[i] < n)
	{
		int j = sa[rnk[i]+1], &res = lcp[rnk[i]];
		while(s[i+res] == s[j+res]) ++res;
		if(i<n && res) lcp[rnk[i+1]] = res - 1;
	}
	lcp[n] = 0;
}

char s[MAXN];

int st[MAXN][LB];
inline int get_mn(int l,int r)
{
	int t = lb[r-l+1];
	return min(st[l][t], st[r-(1<<t)+1][t]);
}

int main(void)
{
	for(int i=2; i<MAXN; ++i) lb[i] = lb[i>>1] + 1;
	
	scanf("%s",s+1);
	int n = strlen(s+1);
	
	get_sa(s,n);
	get_lcp(s,n);
	
	for(int i=n-1; i>=0; --i)
	{
		st[i][0] = lcp[i];
		for(int j=1; i+(1<<j)-1 < n; ++j)
			st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
	}
	
	vector<pii> ans;
	for(int i=1; i<n; ++i)
	{
		int l = rnk[n-i+1], r = rnk[1];
		if(l>r) continue;
		if(get_mn(l, r-1) < i) continue;
		
		int cur = l;
		for(int j=lb[n-l+1]; j>=0; --j)
			if(j <= lb[n-cur+1] && st[cur][j] >= i)
				cur += 1<<j;
		ans.push_back(make_pair(i, cur-l+1));
	}
	ans.push_back(make_pair(n,1));
	
	printf("%d\n",(int)ans.size());
	for(int i=0; i<(int)ans.size(); ++i)
		printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}