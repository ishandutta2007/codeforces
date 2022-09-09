#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e3 + 5;
const int MAXM = 1e3 + 5;
const int MAXL = MAXN * MAXM;
const int inf = 0x3f3f3f3f;

namespace SA
{
	int _rnk1[MAXL], _rnk2[MAXL];
	int sa[MAXL], *rnk = _rnk1, *lst_rnk = _rnk2, sa_k;
	inline bool sa_same(int x,int y){ return lst_rnk[x] == lst_rnk[y] && lst_rnk[x + sa_k] == lst_rnk[y + sa_k];}
	inline void build(char s[],int n)
	{
		static int t[MAXL];
		int m = 300; rnk[0] = lst_rnk[0] = rnk[n+1] = lst_rnk[n+1] = -1;
		memset(t,0,(m+1)<<2);
		for(int i=1; i<=n; ++i) ++t[rnk[i] = s[i]];
		for(int i=1; i<=m; ++i) t[i] += t[i-1];
		for(int i=n; i>=1; --i) sa[t[rnk[i]]--] = i;
		if(n == 1){ sa[1] = rnk[1] = 1; return;}
		if(m == n) ++m;
		for(int &k=sa_k=1; m!=n; k<<=1)
		{
			static int id[MAXL];
			int cur = 0, *w = lst_rnk;
			for(int i=n-k+1; i<=n; ++i) id[++cur] = i;
			for(int i=1; i<=n; ++i) if(sa[i] > k) id[++cur] = sa[i] - k;
			
			memset(t,0,(m+1)<<2);
			for(int i=1; i<=n; ++i) ++t[w[i] = rnk[id[i]]];
			for(int i=1; i<=m; ++i) t[i] += t[i-1];
			for(int i=n; i>=1; --i) sa[t[w[i]]--] = id[i];
			
			m = 0;
			swap(rnk, lst_rnk);
			for(int i=1; i<=n; ++i)
				rnk[sa[i]] = sa_same(sa[i], sa[i-1])? m: ++m;
		}
	}
} using SA::sa; using SA::rnk;

inline int read_s(int a[])
{
	static char s[MAXN];
	scanf("%s",s+1);
	int len = strlen(s+1);
	reverse(s+1,s+len+1);
	for(int i=1; i<=len; ++i) a[i] = s[i] == '?'? -1: s[i] - '0';
	return len;
}

int n,m;
int a[MAXM], b[MAXN][MAXM], bl[MAXN];
int c[15];

namespace Subtask1
{
	int brnk[MAXN][MAXM], whb[MAXN][MAXM];
	int dp[MAXM][MAXN];
	
	int f[MAXN][2];
	
	void solve(void)
	{
		static char t[MAXL];
		int tot = 0;
		for(int i=1; i<=n; ++i)
		{
			for(int j=m; j>=1; --j)
				t[++tot] = b[i][j] + '0';
			t[++tot] = '$';
		}
		
		SA::build(t, tot);
		
//		printf("t = %s\n",t+1);
//		for(int i=1; i<=tot; ++i)
//		{
//			printf("%2d: %2d %2d  ",i,sa[i],rnk[i]);
//			for(int j=sa[i]; j<=tot; ++j) putchar(t[j]);
//			printf("\n");
//		}
		
		for(int i=1; i<=n; ++i)
			brnk[i][0] = i, whb[0][i] = i;
		
		static int cur_rnk[MAXM];
		for(int i=1; i<=tot; ++i)
		{
			int bid = (sa[i]-1) / (m+1) + 1;
			int bpos = m + 1 - sa[i] % (m+1);
			if(bpos == m+1) continue;
			brnk[bid][bpos] = ++cur_rnk[bpos];
			whb[bpos][cur_rnk[bpos]] = bid;
		}
		
//		printf("\nrnk:\n");
//		for(int i=1; i<=n; ++i, printf("\n"))
//			for(int j=1; j<=m; ++j)
//			{
//				printf("%2d ",brnk[i][j]);
//			}
		
		memset(dp,0xc0,sizeof(dp));
		dp[0][n+1] = 0;
		
		for(int i=1; i<=m; ++i)
		{
			static int cnt[15];
			memset(cnt, 0, 11<<2);
			for(int j=1; j<=n; ++j) ++cnt[(b[j][i] + 1) % 10];
			
			for(int j=1; j<=n+1; ++j)
			{
				if(dp[i-1][j] >= 0)
				{
					int kl, kr;
					if(~a[i]) kl = kr = a[i];
					else kl = i == m? 1: 0, kr = 9;
					for(int k=kl; k<=kr; ++k)
					{
						int cost = 0;
						for(int x=0; x<=9; ++x)
							cost += cnt[x] * c[(x + k) % 10];
						
						int l = 1, r = n+1;
						while(l < r)
						{
							int mid = (l+r)>>1;
							if(mid > n){ r = mid; continue;}
							int bid = whb[i][mid];
							if(b[bid][i] + k + (brnk[bid][i-1] >= j) >= 10) r = mid;
							else l = mid+1;
						}
						
//						printf("i = %d, j = %d, k = %d, nxt = %d\n",i,j,k,l);
						
						dp[i][l] = max(dp[i][l], dp[i-1][j] + cost);
					}
				}
				
				if(j <= n)
				{
					--cnt[(b[ whb[i-1][j] ][i] + 1) % 10];
					++cnt[b[ whb[i-1][j] ][i]];
				}
			}
		}
		
		for(int i=1; i<=n; ++i)
		{
			for(int j=m+1; j<=bl[i]; ++j)
				f[i][0] += c[b[i][j]];
			
			int lst = 1;
			for(int j=m+1; j<=bl[i]; ++j)
			{
				int cur = b[i][j] + lst;
				f[i][1] += c[cur % 10];
				lst = (cur >= 10);
			}
			if(lst) f[i][1] += c[1];
		}
		
		int ans = 0;
		
		int sum = 0;
		for(int i=1; i<=n; ++i) sum += f[i][1];
		for(int i=1; i<=n+1; ++i)
		{
			if(dp[m][i] >= 0)
				ans = max(ans, dp[m][i] + sum);
			if(i <= n)
				sum = sum - f[whb[m][i]][1] + f[whb[m][i]][0];
		}
		
		printf("%d",ans);
		exit(0);
	}
}

int main(void)
{
	m = read_s(a);
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) bl[i] = read_s(b[i]);
	for(int i=0; i<=9; ++i) scanf("%d",&c[i]);
	
	Subtask1::solve();
	return 0;
}