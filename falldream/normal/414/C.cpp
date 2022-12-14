#include<iostream>
#include<cstdio>
#define MN 1048576
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,stat[25],a[MN+5],q[MN+5],top=0;
long long ans[25],Ans[25],sum=0;

void Solve(int x,int l,int r)
{
	if(l==r) return;
	int mid=l+r>>1;
	Solve(x+1,l,mid);Solve(x+1,mid+1,r);
	top=0;long long res=0,res2=0;
	for(int i=l,j=mid+1,k=1;k<=r-l+1;++k)
		if((j>r)||(i<=mid&&a[i]<=a[j])) q[++top]=a[i++];	
		else q[++top]=a[j++],res+=mid-i+1;
	top=0;
	for(int i=l,j=mid+1,k=1;k<=r-l+1;++k)
		if((j>r)||(i<=mid&&a[i]<a[j])) q[++top]=a[i++],res2+=r-j+1;	
		else q[++top]=a[j++];
	for(int i=0;i<=r-l;++i) a[l+i]=q[i+1];
	sum+=res;ans[x]+=res;Ans[x]+=res2;
}

int main()
{
	n=read();
	for(int i=1;i<=1<<n;++i) a[i]=read();
	Solve(1,1,1<<n);
	m=read();
	for(int i=1;i<=m;++i)
	{
		int x=n-read()+1;
		for(;x<=n;++x)
		{
			if(stat[x]^=1) sum-=ans[x]-Ans[x];
			else sum-=Ans[x]-ans[x];
		}
		printf("%lld\n",sum);
	}
	return 0;
}