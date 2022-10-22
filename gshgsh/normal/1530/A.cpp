#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int main()
{
	int T;cin>>T;
	while(T--)
	{
		int N;cin>>N;int ans=0;while(N)ans=max(ans,N%10),N/=10;
		cout<<ans<<endl;
	}
	return 0;
}