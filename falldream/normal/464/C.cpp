#include<iostream>
#include<cstdio>
#define MN 100000
#define mod 1000000007
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
char s[MN+5],t[MN+5],st[MN+5];
int n,len[20],c[20],from[MN+5],lt[MN+5],rt[MN+5];
inline int pow(int k)
{
	int sum=1;
	for(int x=10;k;k>>=1,x=1LL*x*x%mod)
		if(k&1) sum=1LL*sum*x%mod;
	return sum;
}
int main()
{
	scanf("%s",s+1);n=read();
	for(int i=1,j=1;i<=n;++i)
	{
		scanf("%s",st+1);from[i]=st[1]-'0';
		lt[i]=j;rt[i]=j-1;
		for(int k=4;st[k];++k) t[++rt[i]]=st[k];
		j=rt[i]+1;
	}
	for(int i=0;i<=9;++i) len[i]=1,c[i]=i;
	for(int i=n;i;--i)
	{
		int x=0,l=0;
		for(int j=lt[i];j<=rt[i];++j)
			(l+=len[t[j]-'0'])%=(mod-1),x=(1LL*x*pow(len[t[j]-'0'])+c[t[j]-'0'])%mod;
		len[from[i]]=l;c[from[i]]=x;
	}
	int res=0;
	for(int i=1;s[i];++i) res=(1LL*res*pow(len[s[i]-'0'])+c[s[i]-'0'])%mod;
	cout<<res;
	return 0;
}