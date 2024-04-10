#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define lowbit(x) x&-x
#define MAXN 200001
int T,N,M,a[MAXN],b[MAXN],c[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'?f=-1:0,c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void upd(int x){for(int i=x;i<=N;i+=lowbit(i))c[i]++;}int ask(int x){int ans=0;for(int i=x;i;i-=lowbit(i))ans+=c[i];return ans;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)a[i]=b[i]=get();sort(b+1,b+N+1);M=unique(b+1,b+N+1)-b-1;For(i,1,N)a[i]=lower_bound(b+1,b+M+1,a[i])-b;For(i,1,M)c[i]=0;
		bool flag=1;upd(a[1]);For(i,2,N){int l=min(a[i-1],a[i]),r=max(a[i-1],a[i]);if(ask(r-1)-ask(l)>0){flag=0;break;}upd(a[i]);}cout<<(flag?"YES\n":"NO\n");
	}
	return 0;
}