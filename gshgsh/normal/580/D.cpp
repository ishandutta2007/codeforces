#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define lowbit(x) x&-x
#define MAXN 18
int N,M,K,v[MAXN],a[MAXN][MAXN];ll f[1<<MAXN][MAXN],ans;
int cnt(int x){int cnt=0;while(x)x-=lowbit(x),cnt++;return cnt;}
int main()
{
	cin>>N>>M>>K;For(i,0,N-1)cin>>v[i],f[1<<i][i]=v[i];For(i,1,K){int x,y;cin>>x>>y;cin>>a[x-1][y-1];}
	For(i,0,(1<<N)-1)if(cnt(i)>=2)For(j,0,N-1)if((i>>j)&1)For(k,0,N-1)if((i>>k)&1&&j!=k)f[i][j]=max(f[i][j],f[i-(1<<j)][k]+a[k][j]+v[j]);
	For(i,0,(1<<N)-1)if(cnt(i)==M)For(j,0,N-1)if((i>>j)&1)ans=max(ans,f[i][j]);cout<<ans<<endl;return 0;
}