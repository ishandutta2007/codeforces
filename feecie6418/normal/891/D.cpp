#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Thing{int f0,f1,g,h,sz;}f[500005],h[500005],pre[500005];
Thing operator +(Thing x,Thing y){//yx
	Thing ret;
	ret.f0=x.f0+max(y.f0,y.f1);
	ret.f1=max(x.f1+max(y.f0,y.f1),x.f0+y.f0+1);
	ret.sz=x.sz+y.sz;
	ret.g=(ret.sz%2?(ret.f0*2+1==ret.sz):(ret.f1*2==ret.sz));
	if(x.sz%2!=y.sz%2)ret.h=x.h*y.g+y.h*x.g;
	else if(x.sz%2==1)ret.h=y.h*x.g;
	else ret.h=x.h*y.g;
	return ret;
}
int n,lst[500005];
ll ans=0;
vector<int> g[500005];
void dfs1(int x,int fa){
	f[x]={0,-(1<<30),1,0,1};
	bool flag=1;
	for(int y:g[x]){
		if(y==fa)continue;
		dfs1(y,x),f[x]=f[x]+f[y],flag&=(f[y].f1*2==f[y].sz);
	}
	f[x].h+=flag;
}
void dfs2(int x,int fa){
	int cnt=(h[x].f1*2==h[x].sz)-(x==1),ls=0;
	for(int y:g[x])if(y^fa)cnt+=(f[y].f1*2==f[y].sz);
	pre[0]=(Thing){0,-(1<<29),1,0,1}+h[x];
	for(int y:g[x]){
		if(y==fa)continue;
		pre[y]=pre[ls]+f[y],lst[y]=ls,ls=y;
	}
	reverse(g[x].begin(),g[x].end());
	Thing cur=(Thing){0,-(1<<29),1,0,1};
	for(int y:g[x]){
		if(y==fa)continue;
		h[y]=pre[lst[y]]+((Thing){0,-(1<<29),1,0,1}+cur),cur=cur+f[y];
		if(cnt-(f[y].f1*2==f[y].sz)+1==g[x].size())h[y].h++;
	}
	for(int y:g[x])if(y^fa)dfs2(y,x);
}
void dfs3(int x,int fa){
	for(int y:g[x])if(y^fa)dfs3(y,x);
	if(!fa)return ;
	if(f[x].sz&1){
		ans+=1ll*f[x].h*h[x].h;
	}
	else {
		if(f[x].g&&h[x].g)ans+=1ll*f[x].sz*(n-f[x].sz);
	}
}
int main(){
	scanf("%d",&n);
	if(n%2==1)puts("0"),exit(0);
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),g[x].push_back(y),g[y].push_back(x);
	dfs1(1,0),h[1]={-(1<<29),0,0,0,0},dfs2(1,0),dfs3(1,0),cout<<ans;
}