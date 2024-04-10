#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 1001
int N,a[MAXN],ans[MAXN];bool vis[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	N=get();For(i,1,N-1){int x=get(),y=get();if(x>y)swap(x,y);if(y!=N){cout<<"NO\n";return 0;}a[i]=x;}
	sort(a+1,a+N);For(i,1,N-1)if(!vis[a[i]]){vis[a[i]]=1;ans[i]=a[i];}else{int x=a[i];while(x&&vis[x])x--;if(!x){cout<<"NO\n";return 0;}ans[i]=x;vis[x]=1;}
	cout<<"YES\n";ans[N]=N;For(i,2,N)cout<<ans[i-1]<<' '<<ans[i]<<'\n';return 0;
}