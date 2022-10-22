#include<iostream>
#include<map>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define P 1000000007
#define MAXN 200001
int T,N,a[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N)cin>>a[i];map<ll,int>f;f[0]=1;ll now=0;int ans=1;
		For(i,1,N){int x=f[now];f[now]=ans,now-=a[i];ans=(ans*2ll-x+P)%P;}cout<<ans<<endl;
	}
	return 0;
}