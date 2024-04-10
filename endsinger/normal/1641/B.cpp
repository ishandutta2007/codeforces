#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,m,a[N],b[N],s[N*N],t,ax[N*N],ay[N*N],c,z;
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
	n=rd();
	t=c=z=0,m=n;
	for(int i=1;i<=n;i++)
		a[i]=rd(),b[i]=a[i];
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i+=2)
	{
		if(b[i]!=b[i+1])
		{
			puts("-1");
			return;
		}
	}
	for(int i=1;i<=m/2;i++)
	{
		int p=0;
		for(int j=i+1;j<=n&&!p;j++)
			if(a[i]==a[j])
				p=j;
		for(int j=i+1,d=0;j<p;j++,d++)
			c++,ax[c]=z+d+p,ay[c]=a[j];
		z+=(p-i-1)*2+1;
		s[++t]=(p-i)<<1;
		reverse(a+i+1,a+p);
		for(int j=p;j<n;j++)
			a[j]=a[j+1];
		n=n-1;
	}
	printf("%d\n",c);
	for(int i=1;i<=c;i++)
		printf("%d %d\n",ax[i],ay[i]);
	printf("%d\n",t);
	for(int i=1;i<=t;i++)
		printf("%d ",s[i]);
	puts("");
}
int main()
{
	int t=rd();
	while(t--)
		sol();
	return 0;
}