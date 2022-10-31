#include<cstdio>
#include<iostream>
using namespace std;
const int N=300010;
int n,m;
int a[N],b[N],bit[N];
void C(int i,int x) { for (;i<=n;i+=i&-i) bit[i]+=x;}
int  Q(int i) { int res=0;for (;i;i-=i&-i) res+=bit[i];return res;}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) b[a[i]]=i;
	for (int i=1;i<=n;i++) 
	if (b[i]>b[i+1]) C(i,1);
	scanf("%d",&m);
	while (m--)
	{
		int kd,x,y;
		scanf("%d%d%d",&kd,&x,&y);
		if (kd==1) printf("%d\n",Q(y-1)-Q(x-1)+1);
		if (kd==2) 
		{
			if (b[a[x]]>b[a[x]+1]) C(a[x],-1);
			if (b[a[x]-1]>b[a[x]]&&a[x]>1) C(a[x]-1,-1);
			if (b[a[y]]>b[a[y]+1]&&a[x]-1!=a[y]) C(a[y],-1);
			if (b[a[y]-1]>b[a[y]]&&a[y]>1&&a[y]-1!=a[x]) C(a[y]-1,-1);
			b[a[x]]=y;
			b[a[y]]=x;
			if (b[a[x]]>b[a[x]+1]) C(a[x],1);
			if (b[a[x]-1]>b[a[x]]&&a[x]>1) C(a[x]-1,1);
			if (b[a[y]]>b[a[y]+1]&&a[y]!=a[x]-1) C(a[y],1);
			if (b[a[y]-1]>b[a[y]]&&a[y]>1&&a[y]-1!=a[x]) C(a[y]-1,1);
			swap(a[x],a[y]);
		}
	}
	return 0;
}