#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int T,N,M,a[MAXN],cnt[20];int getcnt(int x){int i=0;while((1<<i)<x)i++;return i;}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>M;For(i,0,19)cnt[i]=0;For(i,1,N)cin>>a[i],cnt[getcnt(a[i])]++;
		int ans=0;while(N){ans++;int x=M;FOR(i,19,0)if(x>=(1<<i)){int y=min(x/(1<<i),cnt[i]);cnt[i]-=y,N-=y,x-=y<<i;}}cout<<ans<<endl;
	}
	return 0;
}