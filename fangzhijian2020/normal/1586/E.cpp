#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}

int n,m,q,x,y,fa[300005],h[300005],cnt=1,ans;
int getfzj(int x){
	if(x==fa[x])return x;
	return fa[x]=getfzj(fa[x]);
}
vector<int>v[300005];
struct edge{int to,next;}e[600005];
void add(int x,int y){
	e[++cnt]=(edge){y,h[x]};h[x]=cnt;
}
int stack[300005],top,vis[300005];
void dfs(int x,int prt,int Y,int id){
	int i,y;
	if(x==Y){
		for(i=1;i<=top;++i){
			v[id].push_back(e[stack[i]].to);
			vis[stack[i]>>1]^=1;
		}
		return;
	}
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;if(y==prt)continue;
		stack[++top]=i;
		dfs(y,x,Y,id);--top;
	}
}
int main(){
	n=read();m=read();
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=m;++i){
		x=read();y=read();
		if(getfzj(x)!=getfzj(y)){
			fa[getfzj(x)]=getfzj(y);
			add(x,y);add(y,x);
		}
	}
	q=read();
	for(int i=1;i<=q;++i){
		x=read();y=read();
		v[i].push_back(x); 
		dfs(x,0,y,i);
	}
	for(int i=1;i<n;++i)ans+=vis[i];
	if(!ans){
		puts("YES");
		for(int i=1;i<=q;++i){
			cout<<v[i].size()<<"\n";
			for(int j=0;j<v[i].size();++j){
				cout<<v[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
	else{
		for(x=1;x<=n;++x){
			int tmp=0;
			for(int i=h[x];i;i=e[i].next){
				if(vis[i>>1])++tmp;
			}
			ans-=(tmp>>1);
		}	
		puts("NO");
		cout<<ans<<"\n";
	}
	
	return 0;
}