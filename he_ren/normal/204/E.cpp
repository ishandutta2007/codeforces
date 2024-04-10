#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int MAXL = 2e5 + 5;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

int sa[MAXL], rnk[MAXL], sa_k, sa_w[MAXL];
inline bool cmp(const int x,const int y){ return sa_w[x] < sa_w[y];}
void get_sa(int s[],int n,int m)
{
	static int t[MAXL]; rnk[n+1] = -1;
	memset(t,0,(m+1)<<2);
	for(int i=1; i<=n; ++i) ++t[rnk[i] = s[i]];
	for(int i=1; i<=m; ++i) t[i] += t[i-1];
	for(int i=n; i>=1; --i) sa[t[rnk[i]]--] = i;
	for(int i=1,j=1; i<=n;)
	{
		while(j<=n && s[sa[i]] == s[sa[j]]) ++j;
		if(j==i+1) rnk[sa[i]] = i, sa[i++] = -1;
		while(i<j) rnk[sa[i++]] = j-1;
	}
	
	for(int &k=sa_k=1; sa[1] > -n; k<<=1)
	{
		int len = 0;
		for(int i=1; i<=n;)
		{
			if(sa[i] < 0){ len += sa[i]; i -= sa[i]; continue;}
			if(len) sa[i+len] = len, len = 0;
			int l = i, r = rnk[sa[i]];
			
			for(int j=l; j<=r; ++j) sa_w[sa[j]] = rnk[sa[j]+k];
			sort(sa+l,sa+r+1,cmp);
			
			for(int j=i; i<=r;)
			{
				while(j<=r && sa_w[sa[j]] == sa_w[sa[i]]) ++j;
				if(j == i+1) rnk[sa[i]] = i, sa[i++] = -1;
				while(i<j) rnk[sa[i++]] = j-1;
			}
		}
		if(len) sa[n+1+len] = len;
	}
	for(int i=1; i<=n; ++i) sa[rnk[i]] = i;
}

int lcp[MAXL];
void get_lcp(int s[],int n)
{
	for(int i=1; i<=n; ++i) lcp[i] = 0;
	for(int i=1; i<=n; ++i) if(rnk[i] < n)
	{	
		int j = sa[rnk[i]+1], &res = lcp[rnk[i]];
		while(s[i+res] == s[j+res]) ++res;
		if(i<n) chk_max(lcp[rnk[i+1]], res-1);
	}
	lcp[n] = 0;
}

int s[MAXL], m = 0;
int beg[MAXN], ata[MAXL];

int main(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	int alpha = 'z';
	for(int i=1; i<=n; ++i)
	{
		static char t[MAXN];
		scanf("%s",t+1);
		beg[i] = m+1;
		for(int j=1; t[j]; ++j) s[++m] = t[j];
		s[++m] = ++alpha;
	}
	beg[n+1] = m+1;
	
	if(d == 1)
	{
		for(int i=1; i<=n; ++i)
		{
			ll len = beg[i+1] - beg[i] - 1;
			printf("%lld ",len * (len-1) / 2 + len);
		}
		return 0;
	}
	
	get_sa(s, m, alpha); get_lcp(s, m);
	for(int i=1; i<=n; ++i)
		for(int j=beg[i]; j<beg[i+1]; ++j)
			ata[rnk[j]] = i;
	
	static int rb[MAXL], val[MAXL];
	
	static int freq[MAXN], cnt = 0;
	deque<pii> q;
	for(int i=m,j=m; i>=1; --i)
	{
		while(q.size() && q.back().second >= lcp[i]) q.pop_back();
		q.push_back(make_pair(i, lcp[i]));
		
		if(++freq[ata[i]] == 1) ++cnt;
		while(cnt > d || freq[ata[j]] > 1)
			if(--freq[ata[j--]] == 0) --cnt;
		while(q.size() && q.front().first >= j) q.pop_front();
		
		if(cnt == d) rb[i] = j, val[i] = q.front().second;
	}
	q.clear();
	
	static int res[MAXL];
	for(int i=1; i<=m; ++i)
	{
		while(q.size() && q.front().first < i) q.pop_front();
		if(rb[i])
		{
			while(q.size() && q.back().second <= val[i]) q.pop_back();
			q.push_back(make_pair(rb[i], val[i]));
		}
		res[i] = q.size()? q.front().second: 0;
		chk_max(res[i], min(res[i-1], lcp[i-1]));
	}
	
	for(int i=1; i<=n; ++i)
	{
		ll ans = 0;
		for(int j=beg[i]; j<beg[i+1]; ++j)
			ans += res[rnk[j]];
		printf("%lld ",ans);
	}
	return 0;
}