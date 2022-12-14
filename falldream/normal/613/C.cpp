#include<algorithm>
#include<iostream>
#include<cstdio>
#define MN 100000
#define ll long long 
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,a[MN+5],ans=-1,from=0,g,tot=0,s[MN+5];
inline int gcd(int x,int y){return y?gcd(y,x%y):x;}
void Print(int x)
{
	for(int i=1,l=1,r=tot/x;i<=n;++i)
	{
		if((a[i]/x)&1) s[l+r>>1]=i;
		for(int j=1;j<<1<=a[i]/x;++j) s[l++]=s[r--]=i;	
	}
	for(int i=1;i<=tot/x;++i) printf("%c",s[i]+'a'-1);
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i) g=gcd(g,a[i]=read()),tot+=a[i];
	for(int i=1;i<=tot;++i) if(g%i==0)
	{
		int num1=0;
		for(int j=1;j<=n;++j) num1+=(a[j]/i)&1;
		if(num1>1) continue;
		if(i*(2-num1)>ans) ans=i*(2-num1),from=i; 	
	}
	if(ans<0)
	{
		puts("0");
		for(int i=1;i<=n;++i) for(int j=1;j<=a[i];++j) printf("%c",i+'a'-1);
		return 0;	
	}
	printf("%d\n",ans);
	for(int i=1;i<=from;++i) Print(from);
	return 0;
}