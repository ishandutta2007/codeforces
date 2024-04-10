#include<algorithm>
#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int T,N,K,a[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>K;For(i,1,N)cin>>a[i];sort(a+1,a+N+1);if(a[N]==N-1){cout<<N+K<<endl;continue;}
		int x=0;For(i,1,N)if(a[i]==x)x++;else break;int tmp=(x+a[N]+1)/2;if(K&&(*lower_bound(a+1,a+N+1,tmp))!=tmp)N++;cout<<N<<endl;
	}
	return 0;
}