#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
int main()
{
	int a,b;cin>>a>>b;if(a>b)swap(a,b);int x=b-a;pair<ll,int>ans={5e18,0};
	for(int i=1;i*i<=x;i++)if(x%i==0){int k=(a+i-1)/i*i-a;ans=min(ans,{1ll*(a+k)*(b+k)/__gcd(a+k,b+k),k});k=(a+x/i-1)/(x/i)*(x/i)-a;ans=min(ans,{1ll*(a+k)*(b+k)/__gcd(a+k,b+k),k});}
	cout<<ans.second<<'\n';return 0;
}