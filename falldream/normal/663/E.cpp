#include<iostream>
#include<cstring>
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
char st[MN+5];long long a[MN+5],b[MN+5],c[MN+5];
int n,m,s[MN+5],num[MN+5],f[21][MN+5],res[MN+5],ans=1e9;
void FWT(long long*a,int l,int r,int v)
{
	if(l==r) return;
	int mid=l+r>>1;FWT(a,l,mid,v);FWT(a,mid+1,r,v);
	for(int i=0;i<=mid-l;++i)
	{
		long long x=a[l+i],y=a[mid+1+i];
		a[l+i]=(x+y)>>v;
		a[mid+1+i]=(x-y)>>v;
	}
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i) 
	{
		scanf("%s",st+1);
		for(int j=1;j<=m;++j) if(st[j]=='1') s[j]|=1<<i-1;
	}
	for(int i=1;i<=m;++i) ++a[s[i]];
	for(int i=1;i<1<<n;++i) num[i]=num[i>>1]+(i&1);
	FWT(a,0,(1<<n)-1,0);
	for(int j=0;j<1<<n;++j) b[j]=min(num[j],n-num[j]);
	FWT(b,0,(1<<n)-1,0);
	for(int j=0;j<1<<n;++j) c[j]=b[j]*a[j];
	FWT(c,0,(1<<n)-1,1);
	for(int j=0;j<1<<n;++j) res[j]+=c[j];
	for(int j=0;j<1<<n;++j) ans=min(ans,res[j]);
	printf("%d\n",ans);
	return 0;
}