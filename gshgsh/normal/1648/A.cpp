#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define lowbit(x) x&-x
#define MAXN 100001
int N,M,K;ll ans;vector<int>a[MAXN];vector<ll>c[MAXN],c1[MAXN],c2[MAXN];vector<pair<int,int>>id[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void upd(int x,int y,int v,int v1,int v2){for(int i=x;i<=N;i+=lowbit(i))for(int j=y;j<=M;j+=lowbit(j))c[i][j]+=v,c1[i][j]+=v1,c2[i][j]+=v2;}
ll ask(vector<ll>*c,int x,int y){ll ans=0;for(int i=x;i;i-=lowbit(i))for(int j=y;j;j-=lowbit(j))ans+=c[i][j];return ans;}
int main()
{
	N=get(),M=get();For(i,0,N)a[i].resize(M+1),c[i].resize(M+1),c1[i].resize(M+1),c2[i].resize(M+1);
	For(i,1,N)For(j,1,M)K=max(K,a[i][j]=get()),id[a[i][j]].push_back({i,j});
	For(i,1,K)
	{
		for(auto j:id[i]){int x=j.first,y=j.second;upd(x,y,1,x,y);}
		for(auto j:id[i]){int x=j.first,y=j.second;ans+=1ll*(x+y)*ask(c,x,y)-ask(c1,x,y)-ask(c2,x,y);}
		for(auto j:id[i]){int x=j.first,y=j.second;ans+=1ll*(x-y)*(ask(c,x-1,M)-ask(c,x-1,y))-(ask(c1,x-1,M)-ask(c1,x-1,y))+(ask(c2,x-1,M)-ask(c2,x-1,y));}
		for(auto j:id[i]){int x=j.first,y=j.second;upd(x,y,-1,-x,-y);}
	}
	cout<<ans<<'\n';return 0;
}