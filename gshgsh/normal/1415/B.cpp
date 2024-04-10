#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define INF 0x3fffffff
#define MAXN 100001
int T,N,K,a[MAXN],ans[101],res;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>K;For(i,1,N)cin>>a[i];For(i,1,100)ans[i]=0;res=INF;
		For(i,1,100){For(j,1,N)if(a[j]!=i){ans[i]++;j+=K-1;}res=min(res,ans[i]);}cout<<res<<endl;
	}
	return 0;
}