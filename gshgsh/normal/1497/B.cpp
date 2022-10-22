#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define abs(x) ((x)>0?(x):-(x))
#define MAXN 100001
int T,N,M,a[MAXN],cnt[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>M;For(i,0,M-1)cnt[i]=0;For(i,1,N)cin>>a[i],cnt[a[i]%M]++;
		int ans=cnt[0]>0;For(i,1,M/2)if(cnt[i]||cnt[M-i])ans+=abs(cnt[i]-cnt[M-i])<=1?1:abs(cnt[i]-cnt[M-i]);cout<<ans<<endl;
	}
	return 0;
}