#include<bits/stdc++.h>
using namespace std;
int T,n,h[200005];
int main(){
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)	scanf("%d",&h[i]);
		sort(h+1,h+1+n);
		int minn=1e9+5;
		for(int i=2;i<=n;++i)	minn=min(minn,h[i]-h[i-1]);
		for(int i=2;i<=n;++i)
		{
			if(minn==h[i]-h[i-1])
			{
				printf("%d ",h[i-1]);
				for(int j=i+1;j<=n;++j)	printf("%d ",h[j]);
				for(int j=1;j<i-1;++j)	printf("%d ",h[j]);
				printf("%d",h[i]);
				puts("");
				break;
			}
		}
	}
	return 0;
}