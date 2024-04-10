#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;

inline bool same(int a,int b){ return (a>=0 && b>=0) || (a<=0 && b<=0);}

char s[MAXN];
int a[MAXN],sum[MAXN];

void solve(void)
{
	int n,x;
	scanf("%d%d%s",&n,&x,s+1);
	for(int i=1; i<=n; ++i) a[i]=s[i]-'0';
	
	for(int i=1; i<=n; ++i)
	{
		sum[i]=sum[i-1];
		if(a[i]) --sum[i];
		else ++sum[i];
	}
	
	int ans=0;
	for(int i=1; i<=n; ++i)
	{
		if(!sum[n])
		{
			if(sum[i]==x){ printf("-1\n"); return;}
			continue;
		}
		if(!same(x-sum[i], sum[n])) continue;
		
		int a=abs(x-sum[i]), b=abs(sum[n]);
		if(a%b) continue;
		++ans;
	}
	if(!x) ++ans;
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}