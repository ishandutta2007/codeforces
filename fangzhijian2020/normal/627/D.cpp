#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
const int Mxdt=100000,INF=1e9;
char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
int read(){
	int a=0;bool opt=0;char c=gc();
	while(c<'0'||c>'9')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
int n,k,s[200005],x,y,h[200005],cnt;
struct edge{int to,next;}e[400005];
void add(int x,int y){
	e[++cnt]=(edge){y,h[x]};h[x]=cnt;
}
int sz[200005],opt[200005],Max[200005],se[200005];
void dfs(int x,int prt,int lim){
	int i,y,tp;Max[x]=se[x]=0;
	tp=sz[x]=opt[x]=(s[x]>=lim);
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;if(y==prt)continue;
		dfs(y,x,lim);sz[y]+=Max[y];
		if(opt[y]==1){if(tp)sz[x]+=sz[y];}
		else{
			if(tp){
				if(sz[y]>Max[x]){
					se[x]=Max[x];Max[x]=sz[y];
				}
				else if(sz[y]>se[x])se[x]=sz[y];
				--opt[x];		
			}
		}
		sz[y]-=Max[y];
	}
}
int upsz,upopt,ans;
void DFS(int x,int prt){
	int i,y,tp;tp=(sz[x]>0);
	if(upopt==1){if(tp)sz[x]+=upsz;}
	else{
		if(tp){
			if(upsz>Max[x]){
				se[x]=Max[x];Max[x]=upsz;
			}
			else if(upsz>se[x])se[x]=upsz;
			--opt[x];		
		}
	}
	if(tp)ans=max(ans,sz[x]+Max[x]);
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;if(y==prt)continue;
		upsz=tp*(sz[x]-(opt[y]==1?sz[y]+Max[y]:0)+((Max[x]==sz[y]+Max[y]&&opt[y]!=1)?se[x]:Max[x]));
		upopt=tp&((opt[x]+(opt[y]!=1))>0);DFS(y,x);
	}
}
bool check(int x){
	ans=upsz=0;upopt=1;
	dfs(1,0,x);DFS(1,0);
	return ans>=k;
}
int main(){
//	freopen("arrange6.in","r",stdin);
//	freopen("arrange.out","w",stdout);
	n=read();k=read();int Min=INF,Max=0;
	for(int i=1;i<=n;++i){
		s[i]=read();Min=min(Min,s[i]);Max=max(Max,s[i]);
	}
	for(int i=1;i<n;++i){
		x=read();y=read();add(x,y);add(y,x);
	}
	int l=Min,r=Max;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	cout<<l-1<<"\n";
	return 0;
}