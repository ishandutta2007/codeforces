#include<bits/stdc++.h>
#define F fflush(stdout)
using namespace std;
int T,a[10005];
int main(){
	cin>>T;
	while(T-->0)
	{
		int n;
		cin>>n;
		int dk=0;
		for(int i=1;i<=n;i+=2)
		{
			if(i==n)	break;
			putchar('?');
			printf(" 2 %d %d 1",i,i+1);
			F;
			puts("");
			F;
			int x;
			scanf("%d",&x);
			if(x==1)
			{
				dk=i;
				break;
			}
			else if(x==2)
			{
				printf("? 2 %d %d 1\n",i+1,1);
				F;
				scanf("%d",&x);
				if(x==1)
				{
					dk=i+1;
					break;
				}
			}
		}
		if(!dk)	dk=n;
		a[dk]=1;
		for(int i=1;i<=n;++i)
		{
			if(i==dk)	continue;
			putchar('?');
			printf(" 1 %d %d %d",dk,i,n-1);
			F;
			puts("");
			F;
			scanf("%d",&a[i]);
		}
		putchar('!');
		for(int i=1;i<=n;++i)	printf(" %d",a[i]);
		F;
		puts("");
		F;
	}
	return 0;
}