#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 201
int T,N,K,a[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>K;For(i,1,N)cin>>a[i];a[N+1]=0;
		int ans=-1;For(i,1,K){int pos=1;while(pos<=N&&a[pos]>=a[pos+1])pos++;if(pos>N)break;a[pos]++;if(i==K)ans=pos;}cout<<ans<<endl;
	}
	return 0;
}