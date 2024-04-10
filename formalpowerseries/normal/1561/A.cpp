#include<bits/stdc++.h>
using namespace std;
int n,a[1005];
void Solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)	scanf("%d",&a[i]);
	for(int i=1;;++i)
	{
		for(int j=2;j<=n;++j)
		{
			if(a[j]<a[j-1])	goto fail;
		}
		printf("%d\n",i-1);
		break;
		fail:;
		if(i&1)
		{
			for(int j=1;j<=n;j+=2)
			{
				if(j+1>n)	continue;
				if(a[j]>a[j+1])	swap(a[j],a[j+1]);
			}
		}
		else
		{
			for(int j=2;j<=n;j+=2)
			{
				if(j+1>n)	continue;
				if(a[j]>a[j+1])	swap(a[j],a[j+1]);
			}
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)	Solve();
	return 0;
}