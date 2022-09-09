#include<cstdio>
#include<algorithm>
#include<vector>
const int MAXN = 2e3 + 5;
const int inf = 2e9 + 5;
using namespace std;

int rnk[MAXN<<1],cnt=0;

struct Seg
{
	int id,l,r;
}a[MAXN];
inline bool cmp(const Seg &x,const Seg &y){ return x.r==y.r? x.l>y.l: x.r<y.r;}

vector<int> c[MAXN<<1],ans[MAXN];
int id[MAXN<<1][MAXN<<1];
int f[MAXN<<1],g[MAXN<<1],last[MAXN<<1];

inline void gao(int p)
{
	int l=a[p].l, r=a[p].r;
	
	f[l]=0;
	for(int i=l+1; i<=r; ++i)
	{
		f[i]=f[i-1];
		last[i]=0;
		for(int j=0; j<(int)c[i].size(); ++j)
		{
			int q=c[i][j], ql=a[q].l;
			if(ql < l || q == p) continue;
			
			if(f[i] < f[ql] + g[q])
				f[i] = f[ql] + g[q],
				last[i] = ql;
		}
	}
	
	ans[p].push_back(p);
	for(int i=r; i>l; i=last[i])
	{
		while(!last[i] && i>l) --i; 
		if(i<=l) break;
		
		int q=id[last[i]][i];
		for(int j=0; j<(int)ans[q].size(); ++j) ans[p].push_back(ans[q][j]);
	}
	
	g[p] = f[r] + 1;
} 

int main(void)
{
	int n;
	scanf("%d",&n);
	a[0] = (Seg){0, -inf, inf};
	rnk[++cnt]=-inf; rnk[++cnt]=inf;
	for(int i=1; i<=n; ++i)
	{
		int c,rd;
		scanf("%d%d",&c,&rd);
		a[i] = (Seg){i, c-rd, c+rd};
		rnk[++cnt]=c-rd; rnk[++cnt]=c+rd;
	}
	
	sort(a,a+n+1,cmp);
	sort(rnk+1,rnk+cnt+1);
	cnt = unique(rnk+1,rnk+cnt+1) - rnk - 1;
	for(int i=0; i<=n; ++i)
	{
		a[i].l = lower_bound(rnk+1,rnk+cnt+1, a[i].l) - rnk;
		a[i].r = lower_bound(rnk+1,rnk+cnt+1, a[i].r) - rnk;
		
		id[a[i].l][a[i].r] = i;
		gao(i);
		c[a[i].r].push_back(i);
	}
	
	printf("%d\n",(int)ans[n].size()-1);
	for(int i=1; i<(int)ans[n].size(); ++i)
		printf("%d ",a[ans[n][i]].id);
	return 0;
}