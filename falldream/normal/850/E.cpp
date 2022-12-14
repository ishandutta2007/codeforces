#include<iostream>
#define MN 1048576
#include<cstdio>
#define mod 1000000007
const int Inv2=(mod+1)>>1;
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,num[1<<20],s[1<<20],ans;

void FWT(int*a,int l,int r,int v)
{	
	if(l==r) return;
	int mid=l+r>>1;FWT(a,l,mid,v);FWT(a,mid+1,r,v);
	for(int i=0;i<=mid-l;++i)
	{
		int x=a[l+i],y=a[mid+1+i];
		a[l+i]=1LL*(x+y)*v%mod;
		a[mid+1+i]=1LL*(x-y+mod)*v%mod;	
	}
}

int main()
{
	n=read();
	for(int i=0;i<1<<n;++i) s[i]=getchar()-'0';
	FWT(s,0,(1<<n)-1,1);
	for(int i=0;i<1<<n;++i) s[i]=1LL*s[i]*s[i]%mod;
	FWT(s,0,(1<<n)-1,Inv2); 
	for(int i=0;i<1<<n;++i) 
	{
		num[i]=1;
		for(int j=0;j<n;++j) if(!(i&(1<<j))) num[i]=2*num[i]%mod;
		ans=(ans+1LL*num[i]*s[i])%mod;	
	}
	printf("%d\n",3LL*ans%mod);
	return 0;
}