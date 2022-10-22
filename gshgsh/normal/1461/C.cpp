#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int T,N,M,a[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>M;For(i,1,N)cin>>a[i];int id=N+1;FOR(i,N,1)if(a[i]==i)id=i;else break;double ans=0,tmp=1;
		For(i,1,M){int x;double p;cin>>x>>p;if(x>=id-1)ans+=tmp*p,tmp*=1-p;}cout<<(id!=1?ans:1)<<endl;
	}
	return 0;
}