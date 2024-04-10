#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define lowbit(x) x&-x
#define MAXN 300001
#define K 600000
int N,a[MAXN],c1[K+1];ll sum[MAXN],c2[K+1],ans[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void upd1(int x,int v){for(int i=x;i<=K;i+=lowbit(i))c1[i]+=v;}int ask1(int x){int ans=0;for(int i=x;i;i-=lowbit(i))ans+=c1[i];return ans;}
void upd2(int x,int v){for(int i=x;i<=K;i+=lowbit(i))c2[i]+=v;}ll ask2(int x){ll ans=0;for(int i=x;i;i-=lowbit(i))ans+=c2[i];return ans;}
int main()
{
	N=get();For(i,1,N)a[i]=get(),sum[i]=sum[i-1]+a[i];
	For(i,1,N)
	{
		ans[i]=ans[i-1]+1ll*(i-1)*a[i]+sum[i-1]-ask2(a[i]);
		for(int j=1;(j+1)*a[i]-1<=K;j++)ans[i]-=1ll*a[i]*j*(ask1((j+1)*a[i]-1)-ask1(j*a[i]-1)),upd2(j*a[i],j*a[i]),upd2((j+1)*a[i],-j*a[i]);upd1(a[i],1);
		cout<<ans[i]<<" \n"[i==N];
	}
	return 0;
}