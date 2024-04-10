#include<cstdio>
#include<iostream>
using namespace std;
const int N=100010;
const long long mo=1000000007;
struct Edge{int y,ne;};
int n,num;
int c[N];
Edge e[N];int last[N];
int f[N][3];
void add(int x,int y)
{
	e[++num].y=y;e[num].ne=last[x];last[x]=num;
}
int pow(int a,int b,int c)
{
	int d=1;
	while (b)
	{
		if (b&1) d=1LL*d*a%c;
		a=1LL*a*a%mo;
		b>>=1;
	}
	return d;
}
int main()
{
	scanf("%d",&n);int fa;
	for (int i=1;i<n;i++) scanf("%d",&fa),add(fa,i);
	for (int i=0;i<n;i++) scanf("%d",&c[i]);
	for (int i=n-1;i>=0;i--)
	{
		f[i][c[i]]=1;
		for (int j=last[i];j;j=e[j].ne)
			f[i][c[i]]=1LL*f[i][c[i]]*f[e[j].y][2]%mo;
		if (c[i]==1) f[i][0]=0;
		else
		{
			for (int j=last[i];j;j=e[j].ne)
				f[i][1]=(f[i][1]+1LL*f[i][0]*pow(f[e[j].y][2],mo-2,mo)%mo*f[e[j].y][1]%mo)%mo;
		}
		f[i][2]=f[i][0]+f[i][1];
		if (f[i][2]>=mo) f[i][2]-=mo;
	}
	if (f[0][1]<0) f[0][1]+=mo;
	printf("%d\n",f[0][1]);
	return 0;
}