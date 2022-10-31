#include<cstdio>
#include<iostream>
using namespace std;
int p,q,ans;
int v[1200000];
void getp()
{
	v[1]=1;
	for (int i=2;i<=1200000;i++)
	if (!v[i])
	for (int j=2;i*j<=1200000;j++)
		v[i*j]=1;
}
int palin(int i)
{
	int j=0,tmp=i;
	while (i)
	{
		j=j*10+i%10;
		i/=10;
	}
	return tmp==j;
}
int main()
{
	scanf("%d%d",&p,&q);
	int c1=0,c2=0;
	getp();
	for (int i=1;i<=1200000;i++)
	{
		c1+=1-v[i],c2+=palin(i);
		if (1LL*c1*q<=1LL*c2*p) ans=i;
	}
	printf("%d\n",ans);
	return 0;
}