#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int T,N,a[MAXN],b[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N){char c;cin>>c;a[i]=c-'0';}For(i,1,N){char c;cin>>c;b[i]=c-'0';}
		bool is0=0,is1=0;int ans=0;
		For(i,1,N)
		if(a[i]^b[i]){if(is0)ans++;ans+=2;is0=is1=0;}
		else if(a[i]){if(is0)ans+=2,is0=0;else is1=1;}
		else if(is1)ans+=2,is1=0;else if(is0)ans++;else is0=1;
		cout<<ans+is0<<'\n';
	}
	return 0;
}