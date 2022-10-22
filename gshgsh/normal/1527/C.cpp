#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#define ll long long
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int T,N,a[MAXN],b[MAXN],K;vector<int>pos[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N)cin>>a[i],b[i]=a[i],pos[i].clear();sort(b+1,b+N+1);K=unique(b+1,b+N+1)-b-1;
		For(i,1,N)pos[lower_bound(b+1,b+K+1,a[i])-b].push_back(i);
		ll ans=0;For(i,1,K){ll tmp=0;for(auto j:pos[i])ans+=(N-j+1)*tmp,tmp+=j;}cout<<ans<<endl; 
	}
	return 0;
}