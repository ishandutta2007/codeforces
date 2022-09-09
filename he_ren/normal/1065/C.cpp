#include<cstdio>
#include<algorithm>
typedef long long ll;
const int MAXN = 2e5 + 5;
const int MAXH = 2e5 + 5;

inline void chk_min(int &a,int b){ if(a>b) a=b;}
inline void chk_max(int &a,int b){ if(a<b) a=b;}

int h[MAXN];
ll sum[MAXH];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&h[i]);
	
	sum[1]=n;
	for(int i=1; i<=n; ++i)
		--sum[h[i]+1];
	for(int i=1; i<MAXH; ++i)
		sum[i] += sum[i-1];
	for(int i=1; i<MAXH; ++i)
		sum[i] += sum[i-1];
	
	int mn=MAXH, mx=0;
	for(int i=1; i<=n; ++i)
		chk_min(mn,h[i]),
		chk_max(mx,h[i]);
	
	int ans=0;
	for(int l=mn+1,r=mn+1; l<=mx; l=r)
	{
		while(sum[r]-sum[l-1] <= m) ++r;
		++ans;
	}
	printf("%d",ans);
	return 0;
}