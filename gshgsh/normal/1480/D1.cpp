#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int N,M,K,a[MAXN],b[MAXN],c[MAXN],pos[MAXN],nxt[MAXN];
int main()
{
	cin>>N;For(i,1,N)cin>>a[i],pos[a[i]]=N+1;FOR(i,N,1)nxt[i]=pos[a[i]],pos[a[i]]=i;nxt[0]=N+1;
	For(i,1,N)if(a[i]==a[b[M]])c[++K]=i;else if(a[i]==a[c[K]])b[++M]=i;else if(nxt[b[M]]<nxt[c[K]])b[++M]=i;else c[++K]=i;
	int ans=0;For(i,1,M)if(a[b[i]]!=a[b[i-1]])ans++;For(i,1,K)if(a[c[i]]!=a[c[i-1]])ans++;cout<<ans<<endl;return 0;
}