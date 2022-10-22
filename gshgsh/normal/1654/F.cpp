#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 1<<20
int N,k,a[MAXN],rk[MAXN],sa[MAXN],tmp[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int getc(){char c=getchar();while(c<'a'||c>'z')c=getchar();return c;}
int main()
{
	N=get();For(i,0,(1<<N)-1)rk[i]=a[i]=getc(),sa[i]=i;
	for(k=1;k<1<<N;k<<=1)
	{
		sort(sa,sa+(1<<N),[&](const int&x,const int&y){return rk[x]<rk[y]||rk[x]==rk[y]&&rk[x^k]<rk[y^k];});
		tmp[sa[0]]=1;For(i,1,(1<<N)-1)tmp[sa[i]]=tmp[sa[i-1]]+(rk[sa[i]]!=rk[sa[i-1]]||rk[sa[i]^k]!=rk[sa[i-1]^k]);For(i,0,(1<<N)-1)rk[i]=tmp[i];
	}
	For(i,0,(1<<N)-1)cout<<char(a[i^sa[0]]);cout<<'\n';
}