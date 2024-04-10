#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define P 1000000007
#define MAXN 200001
int T,N,K,ans[MAXN];
int pow(int a,int b){int ans=1;while(b>0)(b&1)&&(ans=1ll*ans*a%P),a=1ll*a*a%P,b>>=1;return ans;}
int solve(int x)
{
	if(ans[x])return ans[x];if(!x)return 1;
	int ans1=N+1&1?pow(pow(2,x-1),N):solve(x-1);
	int ans2=1ll*(N&1?pow(2,N-1):pow(2,N-1)-1)*solve(x-1)%P;return ans[x]=(ans1+ans2)%P;
}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>K;For(i,1,K)ans[i]=0;cout<<solve(K)<<'\n';
	}
	return 0;
}