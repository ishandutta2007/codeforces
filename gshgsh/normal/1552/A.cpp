#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 41
int T,N,a[MAXN],b[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N){char c;cin>>c;a[i]=b[i]=c-'0';}
		sort(a+1,a+N+1);int ans=0;For(i,1,N)ans+=a[i]!=b[i];cout<<ans<<endl;
	}
	return 0;
}