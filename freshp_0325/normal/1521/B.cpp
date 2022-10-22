#include<bits/stdc++.h>
using namespace std;
int n,a[100005];
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)	scanf("%d",&a[i]);
		int minn=2105781207,pos=0;
		for(int i=1;i<=n;++i)	if(a[i]<minn)	minn=a[i],pos=i;
		printf("%d\n",n-1);
		for(int i=1;i<=n;++i)
		{
			if(i==pos)	continue;
			printf("%d %d %d %d\n",i,pos,1000000007+(i&1)*2,minn);
		}
	}
	return 0;
}