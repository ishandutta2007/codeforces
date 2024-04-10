#include<iostream>
#include<vector>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int T,N,a[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;vector<int>cnt(N*2+5);For(i,1,N)cin>>a[i],cnt[a[i]]++;
		For(i,1,N*2)if(cnt[i]>1)cnt[i]--,cnt[i+1]++;int ans=0;For(i,1,N*2+1)if(cnt[i])ans++;cout<<ans<<endl;
	}
	return 0;
}