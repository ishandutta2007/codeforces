#include<cstdio>
#include<iostream>
const int N=100010;
int n,cnt,num;
int v[N],p[N],q[N],c[N],a[N];
int main()
{
	scanf("%d",&n);
	for (int i=2;i*i<=n;i++)
	if (!v[i])
	for (int j=2;i*j<=n;j++)
		v[i*j]=1;
	for (int i=3;i*2<=n;i++)
	if (!v[i])
	{
		cnt=0;
		for (int j=1;i*j<=n;j++)
		if (!a[i*j])
		{
			c[++cnt]=i*j;
			a[i*j]=1;
		}
		int l;
		if (cnt&1) a[c[2]]=0,p[++num]=c[1],q[num]=c[3],l=4;
		else l=1;
		while (l+1<=cnt)
		{
			p[++num]=c[l];q[num]=c[l+1];
			l+=2;
		}
	}
	cnt=0;
	for (int i=1;i*2<=n;i++)
	if (!a[i*2]) c[++cnt]=i*2;
	for (int i=1;i*2<=cnt;i++)
		p[++num]=c[i*2-1],q[num]=c[i*2];
	printf("%d\n",num);
	for (int i=1;i<=num;i++) printf("%d %d\n",p[i],q[i]);
}