#include<cstdio>
#include<algorithm>
#include<queue>
#include<climits>
#include<iostream>
using namespace std;
long long a[300005],b[300005];
int n;
int main(){
	int T;
	scanf("%d",&T); 
	while(T-->0)
	{
		long long ans=__LONG_LONG_MAX__;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)	scanf("%I64d %I64d",&a[i],&b[i]);
		b[n]=min(a[1],b[n]);
		for(int i=1;i<n;++i)	b[i]=min(b[i],a[i+1]);
		long long std=a[1]-b[n];
		for(int i=1;i<n;++i)	std+=a[i+1]-b[i];
		for(int i=1;i<=n;++i)
		{
			int p=i-1;
			if(!p)	p=n;
			ans=min(ans,std+a[i]-a[i]+b[p]);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}