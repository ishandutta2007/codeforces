#include<bits/stdc++.h>
using namespace std;
const int N=200005;
char s[N];
int n,a[N],m,l,t;
void sol()
{
	scanf("%d%s",&n,s+1);
	l=1,m=0;
	for(int i=2;i<=n;i++)
	{
		if(s[i]!=s[i-1])
		{
			m++;
			a[m]=i-l;
			l=i;
		}
	}
	m++;
	a[m]=n-l+1;
	t=1;
	for(int i=1;i<=m;i++)
	{
		while(t<=m&&a[t]==1)
			t++;
		a[t]--;
		if(t>m)
		{
			printf("%d\n",i+(m-i)/2);
			return;
		}
		if(t<=i)
			t=i+1;
	}
	printf("%d\n",m);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}