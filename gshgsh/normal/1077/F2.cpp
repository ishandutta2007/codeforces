#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define INF 0x3fffffffffffffff
#define MAXN 5001
int N,M,K,a[MAXN],h,t,q[MAXN];ll f[MAXN],g[MAXN],ans;
int main()
{
	cin>>N>>K>>M;For(i,1,N)cin>>a[i],g[i]=-INF;g[0]=0;
	For(j,1,M){q[h=t=1]=0;For(i,1,N){while(h<=t&&q[h]<i-K)h++;f[i]=g[q[h]]+a[i];while(h<=t&&g[q[t]]<g[i])t--;q[++t]=i;}For(i,1,N)g[i]=f[i];}
	For(i,N-K+1,N)ans=max(ans,f[i]);cout<<(ans?ans:-1)<<endl;return 0;
}