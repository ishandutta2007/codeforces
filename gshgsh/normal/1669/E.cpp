#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int T,N,a[MAXN],K,x[MAXN],y[MAXN],c[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int getc(){char c=getchar();while(c<'a'||c>'z')c=getchar();return c-'a';}
bool check(int a,int b)
{
	int x1=x[a],y1=y[a],x2=x[b],y2=y[b];
	return (x1==x2)+(y1==y2)==1;
}
int main()
{
	T=get();For(i,0,25)For(j,0,25)x[++K]=i,y[K]=j;
	while(T--)
	{
		N=get();For(i,1,K)c[i]=0;For(i,1,N){int a=getc(),b=getc();c[a*26+b+1]++;}
		ll ans=0;For(i,1,K)For(j,i+1,K)if(check(i,j))ans+=1ll*c[i]*c[j];cout<<ans<<'\n';
	}
}