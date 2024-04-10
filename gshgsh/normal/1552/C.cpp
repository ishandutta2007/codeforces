#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 101
int T,N,K,id[MAXN*2],a[MAXN],b[MAXN];bool vis[MAXN*2];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
bool cross(int a,int b,int c,int d){if(a>b)swap(a,b);if(c>a&&c<b)return d<a||d>b;if(d>a&&d<b)return c<a||c>b;return 0;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),K=get();For(i,1,N*2)vis[i]=0;For(i,1,K)a[i]=get(),b[i]=get(),vis[a[i]]=1,vis[b[i]]=1;
		int j=1;For(i,1,N-K<<1){while(vis[j])j++;id[i]=j++;}For(i,K+1,N)a[i]=id[i-K],b[i]=id[i+N-K*2];
		int ans=0;For(i,1,N)For(j,1,i-1)ans+=cross(a[i],b[i],a[j],b[j]);cout<<ans<<'\n';
	}
	return 0;
}