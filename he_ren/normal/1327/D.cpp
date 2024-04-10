#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;

inline void chk_min(int &a,int b){ if(a>b) a=b;}

int p[MAXN],clr[MAXN];
int dis[MAXN],t[MAXN];
bool vis[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&p[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&clr[i]);
	
	for(int i=1; i<=n; ++i) vis[i]=0;
	
	int ans=n;
	for(int i=1; i<=n; ++i)
	{
		if(vis[i]) continue;
		
		int now=i;
		dis[now]=0;
		do vis[now]=1, dis[p[now]]=dis[now]+1, now=p[now]; while(now!=i);
		
		int len=dis[i];
		if(len==1){ ans=1; break;}
		
		
		for(int k=1; k<=len; ++k)
		{
			if(len%k) continue;
			
			for(int j=0; j<k; ++j) t[j]=-1;
			
			now=i;
			do
			{
				int j = dis[now]%k;
				if(t[j]==-1) t[j]=clr[now];
				else if(t[j]!=clr[now]) t[j]=-233;
				now=p[now]; 
			}while(now!=i);
			
			for(int j=0; j<k; ++j)
				if(t[j]>0) chk_min(ans,k);
		}
	}
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}