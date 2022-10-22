#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define ls(x) x<<1
#define rs(x) x<<1|1
#define R (l+r>>1)
#define L (l+r>>1)+1
#define MAXN 200001
int N,a[MAXN],pre[MAXN],mn[MAXN*4];bool vis[MAXN];
void upd(int k,int l,int r,int x,int v){l!=r?x<=R?upd(ls(k),l,R,x,v):upd(rs(k),L,r,x,v),mn[k]=min(mn[ls(k)],mn[rs(k)]):mn[k]=v;}
int ask(int k,int l,int r,int x,int y){return l<=y&&r>=x?l<x||r>y?min(ask(ls(k),l,R,x,y),ask(rs(k),L,r,x,y)):mn[k]:N+1;}
int main()
{
	cin>>N;For(i,1,N)cin>>a[i],vis[1]|=a[i]>1,vis[a[i]]|=a[i]>1&&ask(1,1,N,1,a[i]-1)>pre[a[i]],upd(1,1,N,a[i],pre[a[i]]=i);
	For(i,2,N+1)vis[i]|=ask(1,1,N,1,i-1)>pre[i];int ans=1;while(ans<=N+1&&vis[ans])ans++;cout<<ans<<endl;return 0;
}