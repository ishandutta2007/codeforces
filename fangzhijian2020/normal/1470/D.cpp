#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int T,n,m,x,y,h[300005],cnt,fa[300005],tp[300005],tot,ans[300005],vis[300005];
struct edge{int to,next;}e[600005];
void add(int x,int y){
	e[++cnt]=(edge){y,h[x]};h[x]=cnt;
}
int getfzj(int x){
	if(x==fa[x])return x;
	return fa[x]=getfzj(fa[x]);
}
queue<int>q;
int main(){
	T=read()+1;
	while(--T){
		n=read();m=read();cnt=0;
		for(int i=1;i<=n;++i)vis[i]=tp[i]=h[i]=0,fa[i]=i;
		for(int i=1;i<=m;++i){
			x=read();y=read();
			add(x,y);add(y,x);
			fa[getfzj(x)]=getfzj(y);
		}
		int opt=0;
		for(int i=1;i<n;++i){
			if(getfzj(i)!=getfzj(i+1)){
				opt=1;break;
			}
		}
		if(opt)puts("NO");
		else{
			puts("YES");tot=0;
			while(!q.empty())q.pop();
			q.push(1);
			while(!q.empty()){
				x=q.front();q.pop();
				int opt=1;vis[x]=2;
				for(int i=h[x];i;i=e[i].next){
					y=e[i].to;
					if(vis[y]==2&&tp[y]){
						opt=0;
					}
					if(!vis[y]){
						q.push(y);vis[y]=1;
					}
				}
				tp[x]=opt;if(opt)ans[++tot]=x;
			}
			cout<<tot<<"\n";
			for(int i=1;i<=tot;++i)cout<<ans[i]<<" ";
			puts("");
		}
		
	}
	return 0;
}