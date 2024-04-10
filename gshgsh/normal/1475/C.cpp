#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 200001
int T,N,M,K,a[MAXN],b[MAXN],cnt1[MAXN],cnt2[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>M>>K;For(i,1,N)cnt1[i]=0;For(i,1,M)cnt2[i]=0;For(i,1,K)cin>>a[i];For(i,1,K)cin>>b[i];
		ll ans=0;For(i,1,K)ans+=i-1-cnt1[a[i]]-cnt2[b[i]],cnt1[a[i]]++,cnt2[b[i]]++;cout<<ans<<endl;
	}
	return 0;
}