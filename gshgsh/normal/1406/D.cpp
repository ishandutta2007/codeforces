#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define lowbit(x) x&-x
#define MAXN 100001
int N,M,a[MAXN];ll c[MAXN],ans;int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'?f=-1:0,c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void upd(int x,int v){for(int i=x;i<=N;i+=lowbit(i))c[i]+=v;}ll ask(int x){ll ans=0;for(int i=x;i;i-=lowbit(i))ans+=c[i];return ans;}
ll solve(ll x){if(x>=0)return x+1>>1;if(-x&1)x++;return x/2;}
int main()
{
	N=get();For(i,1,N)a[i]=get(),upd(i,a[i]-a[i-1]);ans=a[1];For(i,2,N)ans+=max(a[i]-a[i-1],0);cout<<solve(ans)<<endl;M=get();
	For(i,1,M)
	{
		int l=get(),r=get(),x=get();if(l>1)ans-=max(ask(l)-ask(l-1),0ll);else ans-=ask(1);if(r<N)ans-=max(ask(r+1)-ask(r),0ll);
		upd(l,x);upd(r+1,-x);if(l>1)ans+=max(ask(l)-ask(l-1),0ll);else ans+=ask(1);if(r<N)ans+=max(ask(r+1)-ask(r),0ll);cout<<solve(ans)<<endl;
	}
	return 0;
}