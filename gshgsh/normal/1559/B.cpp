#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 101
int T,N,a[MAXN],ans[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N){char c;cin>>c;if(c=='?')a[i]=-1;else ans[i]=a[i]=c=='B';}
		int x=1;while(x<=N&&a[x]==-1)x++;if(x==N+1){For(i,1,N)cout<<(i&1?'B':'R');cout<<'\n';continue;}FOR(i,x-1,1)a[i]=a[i+1]^1;
		x=N;while(x&&a[x]==-1)x--;For(i,x+1,N)a[i]=a[i-1]^1;
		FOR(i,x-1,1)if(a[i]==-1)a[i]=a[i+1]^1;
		For(i,1,N)cout<<(a[i]?'B':'R');cout<<'\n';
	}
	return 0;
}