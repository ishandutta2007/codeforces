#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define INF 0x3fffffff
#define MAXN 300001
int T,N,M,a[MAXN],sum[MAXN],mx1[MAXN],mn1[MAXN],mx2[MAXN],mn2[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>M;For(i,1,N){char c;cin>>c;a[i]=c=='+'?1:-1;sum[i]=sum[i-1]+a[i];mx1[i]=max(mx1[i-1],sum[i]);mn1[i]=min(mn1[i-1],sum[i]);}
		mx2[N+1]=-INF;mn2[N+1]=INF;FOR(i,N,1)mx2[i]=max(mx2[i+1],sum[i]),mn2[i]=min(mn2[i+1],sum[i]);For(i,1,N)mx2[i]-=sum[i-1],mn2[i]-=sum[i-1];
		For(i,1,M){int l,r;cin>>l>>r;int mx=mx1[l-1],mn=mn1[l-1],tmp=sum[l-1];mx=max(mx,tmp+mx2[r+1]),mn=min(mn,tmp+mn2[r+1]);cout<<mx-mn+1<<endl;}
	}
	return 0;
}