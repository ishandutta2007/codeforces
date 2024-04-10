#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int T,N,a[MAXN],b[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)a[i]=get();int cnt=0;For(i,1,N)cnt+=a[i]&1;if(cnt!=(N>>1)&&cnt!=(N+1>>1)){cout<<-1<<'\n';continue;}
		if(N+1&1){int M=0;For(i,1,N)if(a[i]&1)b[++M]=i;ll sum1=0,sum2=0;For(i,1,M)sum1+=abs(b[i]-i*2),sum2+=abs(b[i]-i*2+1);cout<<min(sum1,sum2)<<'\n';}
		else{int M=0;For(i,1,N)if(a[i]&1)b[++M]=i;ll ans=0;if(M==(N>>1))For(i,1,M)ans+=abs(b[i]-i*2);else For(i,1,M)ans+=abs(b[i]-i*2+1);cout<<ans<<'\n';}
	}
	return 0;
}