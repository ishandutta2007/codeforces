#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 300001
int N,M;pair<int,int>a[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	N=get(),M=get();For(i,1,N)a[i].second=get(),a[i].first=get();sort(a+1,a+N+1,greater<pair<int,int>>());
	priority_queue<int,vector<int>,greater<int>>q;ll sum=0,ans=0;
	For(i,1,N){q.push(a[i].second),sum+=a[i].second;if(q.size()>M)sum-=q.top(),q.pop();ans=max(ans,sum*a[i].first);}cout<<ans<<'\n';return 0;
}