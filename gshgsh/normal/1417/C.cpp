#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 300001
int T,N,a[MAXN],ans[MAXN],mx[MAXN];vector<int>pos[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)a[i]=get(),ans[i]=-1,mx[i]=0,pos[i].clear();For(i,1,N)pos[i].push_back(0);For(i,1,N)pos[a[i]].push_back(i);For(i,1,N)pos[i].push_back(N+1);
		For(i,1,N)For(j,1,pos[i].size()-1)mx[i]=max(mx[i],pos[i][j]-pos[i][j-1]);
		int now=N;For(i,1,N){while(now&&mx[i]<=now)ans[now--]=i;}For(i,1,N)cout<<ans[i]<<" \n"[i==N];
	}
	return 0;
}