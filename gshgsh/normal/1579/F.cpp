#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 1000001
int T,N,M,a[MAXN];bool vis[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int solve(vector<int>pos){bool flag=1;for(auto i:pos)flag&=i;if(flag)return N+1;int cnt=0,mx=0,front=0;for(auto i:pos)if(i)front++;else break;for(auto i:pos)i?mx=max(mx,++cnt):cnt=0;return max(mx,cnt+front);}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),M=get();For(i,0,N-1)a[i]=get(),vis[i]=0;
		int ans=0;For(i,0,N-1)if(!vis[i]){vector<int>pos;int x=i;do{pos.push_back(a[x]);vis[x]=1;x=(x+M)%N;}while(!vis[x]);ans=max(ans,solve(pos));}cout<<(ans==N+1?-1:ans)<<'\n';
	}
	return 0;
}