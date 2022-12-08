#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
const int K=9;
int a[K], v;
int main()
{
	scanf("%d",&v);
	rep(i,0,K)
		scanf("%d",&a[i]);
	int least=a[0], dig=0;
	rep(i,1,K)
		if(a[i]<least)
		{
			least=a[i];
			dig=i;
		}
	int n=0;
	while(v>=least)
	{
		v-=least;
		++n;
	}
	if(n==0)
		printf("-1\n");
	else
	{
		rep(i,0,K)
			a[i]-=least;
		int j=K-1;
		rep(i,0,n)
		{
			while(v<a[j])
				--j;
			v-=a[j];
			printf("%d",j+1);
		}
		printf("\n");
	}
}