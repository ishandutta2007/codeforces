#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 2001
int T,N,a[MAXN];ll K;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>K;if(K&1){cout<<-1<<endl;continue;}N=1;memset(a,0,sizeof(a));a[1]=1;
		while(K){int l=60;while((1ll<<l+1)-2>K)l--;a[N+=l]=1;K-=(1ll<<l+1)-2;}cout<<N-1<<endl;For(i,1,N-1)cout<<a[i]<<' ';cout<<'\n';
	}
	return 0;
}