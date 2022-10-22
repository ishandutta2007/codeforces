#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,c,a[N];
int rd()
{
	char c=getchar();int x=0;
	while(!(c>='0'&&c<='9'))
		c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+(c-'0');
		c=getchar();
	}
	return x;
}
void sol()
{
	n=rd(),c=rd();
	for(int i=1;i<=c;i++)
		a[i]=0;
	for(int i=1;i<=n;i++)
	{
		int x=rd();
		a[x]=1;
	}
	for(int i=1;i<=c;i++)
		a[i]+=a[i-1];
	for(int i=1;i<=c;i++)
	{
		if(!(a[i]-a[i-1]))
			continue;
		for(int j=1;i*j<=c;j++)
		{
			if(a[j]==a[j-1]&&a[min(c,i*j+i-1)]-a[i*j-1])
			{
				puts("No");
				return;
			}
		}
	}
	puts("Yes");
}
int main()
{
	int t=rd();
	while(t--)
		sol();	
	return 0;
}