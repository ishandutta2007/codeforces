#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200010
using namespace std;
int v[N];
int ans[N];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&v[i]);
	for(int i=2;i<=n;i++)
	{
		int l=1,r=0;
		const int m=i-2;
		for(;l<=m;l=r+1)
		{
			r=m/(m/l);
			if(v[m/l+1]>v[i]) ans[l]++,ans[r+1]--;
		}
		if(v[1]>v[i]) ans[l]++;
	}
	for(int i=1;i<n;i++) ans[i]+=ans[i-1],printf("%d ",ans[i]);
	return 0;
}