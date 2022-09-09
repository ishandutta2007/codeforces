#include<cstdio>
#include<algorithm>
const int MAXN = 1e6 + 5;
const int MAXM = 1e6 + 5;
using namespace std;

int a[MAXN],b[MAXN],cnt[MAXM],t[MAXM];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i]), b[i]=a[i];
	
	for(int i=1; i<=n; ++i)
		if(a[i]<=m) ++cnt[a[i]];
	
	sort(b+1,b+n+1);
	int p = unique(b+1,b+n+1)-b-1;
	
	for(int i=1; i<=p && b[i]<=m; ++i)
		for(int j=b[i]; j<=m; j+=b[i])
			t[j]+=cnt[b[i]];
	
	int ans=t[1], maxt=1;
	for(int i=2; i<=m; ++i)
		if(t[i]>ans)
			ans=t[i],
			maxt=i;
	
	printf("%d %d\n",maxt,ans);
	for(int i=1; i<=n; ++i)
		if(maxt%a[i]==0) printf("%d ",i);
	return 0;
}