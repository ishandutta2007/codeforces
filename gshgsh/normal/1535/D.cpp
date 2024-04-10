#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 18
int N,M,a[1<<MAXN],ans[1<<MAXN+1];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	N=get();FOR(i,(1<<N)-1,1){char c;cin>>c;a[i]=c!='?'?c-'0':2;}For(i,(1<<N),(1<<N+1)-1)ans[i]=1;
	FOR(i,(1<<N)-1,1)ans[i]=a[i]==2?ans[i<<1]+ans[i<<1|1]:ans[i<<1|(a[i]^1)];
	M=get();For(i,1,M){int x=(1<<N)-get(),y;char c;cin>>c;y=c=='?'?2:c-'0';a[x]=y;while(x)ans[x]=a[x]==2?ans[x<<1]+ans[x<<1|1]:ans[x<<1|(a[x]^1)],x>>=1;cout<<ans[1]<<endl;}return 0;
}