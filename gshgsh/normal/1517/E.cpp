#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 998244353
#define MAXN 200001
int T,N,a[MAXN];ll S,sum[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int sol(int x,int y,ll now){if(now*2>=S||x>y)return 0;if(y-x&1)y--;int l=1,r=(y-x>>1)+1,ans=1;while(l<=r){int mid=l+r>>1;(now+sum[x+(mid-1<<1)]-sum[x])*2<S?ans=mid,l=mid+1:r=mid-1;}return ans;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),S=0;For(i,1,N)S+=a[i]=get(),sum[i]=a[i]+(i>1?sum[i-2]:0);ll ans=0;For(i,1,N)if((sum[i]+sum[i-1])*2>S)ans++;
		ll now=0;For(i,1,N-1){now=sum[i]+sum[i-1];ans+=sol(i,N-1,now)+sol(i,N-2,now+a[N]);if(i>1)ans+=sol(i,N-1,now-a[1])+sol(i,N-2,now+a[N]-a[1]);}cout<<ans%P<<endl;
	}
	return 0;
}