#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 1001
int T,N,a[MAXN];string ans[MAXN],pre[MAXN];bool vis[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)a[i]=get(),vis[i]=0;
		For(i,1,N)if(a[i]==1)ans[i]=ans[i-1]+".1",pre[i]=ans[i-1];else{int j=i-1;while(j>=1){if(!vis[j])if(a[j]==a[i]-1)break;else vis[j]=1;j--;}vis[j]=1;ans[i]=pre[j]+"."+to_string(a[i]),pre[i]=pre[j];}
		For(i,1,N){For(j,1,ans[i].size()-1)cout<<ans[i][j];cout<<endl;}
	}
	return 0;
}