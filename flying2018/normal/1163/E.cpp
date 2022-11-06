#include<cstdio>
#include<iostream>
#include<cstring>
#define N 200010
#define M 31
using namespace std;
int num[M+2],p[M+2];
void insert(int x)
{
	int u=x;
	for(int i=M;i>=0;i--)
	if((x>>i)&1)
	{
		if(!num[i]){num[i]=x,p[i]=u;return;}
		if(p[i]>u) swap(num[i],x),swap(u,p[i]);
		x^=num[i];
	}
}
int a[N];
void get_d(int x,int &d)
{
	if(x==-1)return;
	get_d(x-1,d);
	printf("%d ",d^=p[x]);
	get_d(x-1,d);
}
int main()
{
	memset(p,64,sizeof(p));
	int n,res=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),insert(a[i]);
	while(num[res]) res++;
	--res;
	while(res>=0 && p[res]>=1<<(res+1)) res--;
	printf("%d\n",res+1);
	int swp=0;
	printf("%d ",0);
	get_d(res,swp);
	return 0;
}