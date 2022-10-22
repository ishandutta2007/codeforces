#include<iostream>
#include<string>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 101
int T,N,M,a[MAXN],b[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;int sum=0,ans=0,mx=0;For(i,1,N)cin>>a[i],sum+=a[i],mx=max(mx,sum);ans=mx;
		cin>>M,sum=mx=0;For(i,1,M)cin>>b[i],sum+=b[i],mx=max(mx,sum);cout<<ans+mx<<endl;
	}
	return 0;
}