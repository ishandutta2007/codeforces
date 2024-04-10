#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define abs(x) ((x)>0?(x):-(x))
#define MAXN 200001
int T,N;ll a[MAXN],sum,ans;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;sum=0;For(i,1,N)cin>>a[i];For(i,2,N)sum+=abs(a[i]-a[i-1]);ans=min(sum-abs(a[2]-a[1]),sum-abs(a[N]-a[N-1]));
		For(i,2,N-1)ans=min(ans,sum-abs(a[i]-a[i-1])-abs(a[i+1]-a[i])+abs(a[i+1]-a[i-1]));cout<<ans<<endl;
	}
	return 0;
}