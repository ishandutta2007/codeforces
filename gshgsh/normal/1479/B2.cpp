#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int N,a[MAXN],pos[MAXN],nxt[MAXN];
int main()
{
	cin>>N;For(i,1,N)cin>>a[i],pos[a[i]]=N+1;FOR(i,N,1)nxt[i]=pos[a[i]],pos[a[i]]=i;nxt[0]=N+1;
	int x=0,y=0,ans=0;For(i,1,N)if(a[i]==a[x])x=i;else if(a[i]==a[y])y=i;else if(nxt[x]>nxt[y])x=i,ans++;else y=i,ans++;cout<<ans<<endl;return 0;
}