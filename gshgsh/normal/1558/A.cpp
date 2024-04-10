#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int T,N,M,vis[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>M;For(i,0,N+M)vis[i]=0;
		if(N+M&1)
		{
			For(i,0,N+M>>1)if(i<=N&&N-i<=(N+M+1>>1))vis[(N+M>>1)-i+N-i]=1;
			For(i,0,N+M+1>>1)if(i<=N&&N-i<=(N+M>>1))vis[(N+M+1>>1)-i+N-i]=1;
		}
		else For(i,0,N+M>>1)if(i<=N&&N-i<=(N+M>>1))vis[(N+M>>1)-i+N-i]=1;
		int cnt=0;For(i,0,N+M)cnt+=vis[i];cout<<cnt<<'\n';For(i,0,N+M)if(vis[i])cout<<i<<' ';cout<<'\n';
	}
	return 0;
}