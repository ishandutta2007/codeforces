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
int T,n,m,x,y,rd[300005],h[300005],cnt,fa[300005],tp[300005],tot,ans[300005],vis[300005];
struct edge{int to,next,v;}e[600005];
void add(int x,int y,int z){
	e[++cnt]=(edge){y,h[x],z};h[x]=cnt;
}
int getfzj(int x){
	if(x==fa[x])return x;
	return fa[x]=getfzj(fa[x]);
}
queue<int>q;long long X,a[300005],sum;
int main(){
	n=read();m=read();X=read();cnt=0;
	for(int i=1;i<=n;++i)a[i]=read(),fa[i]=i,sum+=a[i];
	for(int i=1;i<=m;++i){
		x=read();y=read();
		if(getfzj(x)!=getfzj(y)){
			add(x,y,i);add(y,x,i);++rd[x];++rd[y];
			fa[getfzj(x)]=getfzj(y);	
		}
	}
	int opt=0;
	for(int i=1;i<n;++i){
		if(getfzj(i)!=getfzj(i+1)){
			opt=1;break;
		}
	}
	if(opt||sum<X*(n-1))puts("NO");
	else{
		puts("YES");
		while(!q.empty())q.pop();
		for(int i=1;i<=n;++i){
			if(rd[i]==1&&i!=1)q.push(i),vis[i]=1;
		}
		int L=0,R=n;
		while(!q.empty()){
			x=q.front();q.pop();vis[x]=1;
			for(int i=h[x];i;i=e[i].next){
				y=e[i].to;
				if(!vis[y]){
					--rd[y];
					if(rd[y]<=1&&y!=1){
						q.push(y);vis[y]=1;
					}
					if(a[x]+a[y]>=X){
						a[y]=a[x]+a[y]-X;
						ans[++L]=e[i].v;
					}
					else{
						ans[--R]=e[i].v;
					}
				}
			}
		}
		for(int i=1;i<n;++i)cout<<ans[i]<<"\n";
		puts("");
	}	
	return 0;
}