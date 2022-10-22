#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 200001
int T,N,a[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N)cin>>a[i];sort(a+1,a+N+1);ll ans=0;
		int l=1;For(r,3,N){while(a[r]-a[l]>2)l++;if(r-l+1<3)continue;ans+=1ll*(r-l)*(r-l-1)/2;}cout<<ans<<endl;
	}
	return 0;
}