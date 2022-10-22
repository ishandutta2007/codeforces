#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define INF 0x3fffffff
#define MAXN 300001
int N,M,u[MAXN],v[MAXN],w[MAXN],p[MAXN],id[MAXN],f[MAXN],siz[MAXN],cnt,top,sta[MAXN*100],ans[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int getf(int x){return f[x]==x?x:getf(f[x]);}
void mrg(int x,int y){x=getf(x),y=getf(y);if(x==y)return;if(siz[x]>siz[y])swap(x,y);cnt-=siz[x]&1;cnt-=siz[y]&1;f[x]=y;f[x]=y;siz[y]+=siz[x];cnt+=siz[y]&1;sta[++top]=x;}
void back(int x){cnt-=siz[f[x]]&1;siz[f[x]]-=siz[x];cnt+=siz[x]&1;cnt+=siz[f[x]]&1;f[x]=x;}
void solve(int l,int r,int x,int y)
{
	if(l>r)return;int mid=l+r>>1;
	int lst=top;For(i,l,mid)if(id[i]<x)mrg(u[i],v[i]);For(i,x,y)if(p[i]<=mid){mrg(u[p[i]],v[p[i]]);if(!cnt){ans[mid]=i;break;}}while(top>lst)back(sta[top--]);
	if(!ans[mid]){For(i,l,mid)if(id[i]<x)mrg(u[i],v[i]);solve(mid+1,r,x,y);while(top>lst)back(sta[top--]);return;}
	For(i,l,mid)if(id[i]<x)mrg(u[i],v[i]);solve(mid+1,r,x,ans[mid]);while(top>lst)back(sta[top--]);
	For(i,x,ans[mid])if(p[i]<l)mrg(u[p[i]],v[p[i]]);solve(l,mid-1,ans[mid],y);while(top>lst)back(sta[top--]);
}
int main(){N=get(),M=get();cnt=N;For(i,1,N)f[i]=i,siz[i]=1;For(i,1,M)u[i]=get(),v[i]=get(),w[i]=get(),p[i]=i;sort(p+1,p+M+1,[&](int x,int y){return w[x]<w[y];});For(i,1,M)id[p[i]]=i;solve(1,M,1,M);For(i,1,M)cout<<(!ans[i]?-1:w[p[ans[i]]])<<'\n';return 0;}