#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N],s[N];
void sol()
{
	scanf("%d",&n);
	for(int j=0;j<=30;j++)
		s[j]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		for(int j=0;j<30;j++)
			if(a[i]>>j&1)
				s[j]++;
	}
	for(int i=1;i<=n;i++)
	{
		int f=1;
		for(int j=0;j<=30;j++)
			if(s[j]%i)
				f=0;
		if(f)
			printf("%d ",i);
	}
	puts("");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}