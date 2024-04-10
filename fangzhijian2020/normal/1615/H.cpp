#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int Mxdt=100000,INF=1e9;
char gc(){
	return getchar();static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
int read(){
	int a=0;bool opt=0;char c=gc();
	while(c<'0'||c>'9')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
int n,m,a[1005],x,y,id[1005],t[1005],c[1005];long long ans;
struct edge{int x,y;};vector<int>V;vector<edge>E;
int cal(int id,int x){return abs(a[id]-x);}
int h[1005],cnt;
struct node{int to,next,v;}e[10005];
void add(int x,int y,int z){
	e[++cnt]=(node){y,h[x],z};h[x]=cnt;
	e[++cnt]=(node){x,h[y],0};h[y]=cnt;
}
int d[1005];queue<int>q;
bool bfs(vector<int>V,int s,int t){
	while(!q.empty())q.pop();
	for(int i=0;i<V.size();++i)d[V[i]]=0;
	d[s]=1;d[t]=0;q.push(s);
	while(!q.empty()){
		int x=q.front();q.pop();
		if(x==t)return 1;
		for(int i=h[x];i;i=e[i].next){
			y=e[i].to;
			if(e[i].v&&!d[y]){
				d[y]=d[x]+1;
				q.push(y);
			}
		}
	}
	return 0;
}
int dfs(int x,int maxf,int t){
	int i,y,ret=0;if(x==t)return maxf;
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;
		if(e[i].v&&d[y]==d[x]+1){
			int del=dfs(y,min(maxf,e[i].v),t);
			if(!del)d[y]=0;
			e[i].v-=del;e[i^1].v+=del;
			ret+=del;maxf-=del;
			if(!maxf)return ret;
		}
	}
	return ret;
}
void solve(vector<int>V,vector<edge>E,int l,int r){	
	if(V.empty())return;
	if(l==r){
		for(int i=0;i<V.size();++i)c[V[i]]=t[l];return;
	}
	int mid=l+r>>1;
	for(int i=0;i<V.size();++i)h[V[i]]=0;cnt=1;
	h[0]=h[n+1]=0;int S=0,T=n+1;
	for(int i=0;i<V.size();++i){
		if(cal(V[i],t[mid])>cal(V[i],t[mid]+1)){
			add(S,V[i],1);id[V[i]]=cnt^1;
		}
		else{add(V[i],T,1);id[V[i]]=cnt^1;}
	}
	for(int i=0;i<E.size();++i)add(E[i].x,E[i].y,INF);
	while(bfs(V,S,T))ans+=dfs(S,INF,T);
	for(int i=0;i<V.size();++i){
		c[V[i]]=bool(d[V[i]]);
	}
	vector<int>v1,v2;vector<edge>e1,e2;
	for(int i=0;i<V.size();++i){
		if(c[V[i]]==0)v1.push_back(V[i]);
		else v2.push_back(V[i]);
	}
	for(int i=0;i<E.size();++i){
		if(c[E[i].x]==c[E[i].y]){
			if(c[E[i].x]==0)e1.push_back(E[i]);
			else e2.push_back(E[i]);
		}
	}
	solve(v1,e1,l,mid);solve(v2,e2,mid+1,r);
}
int main(){
	n=read();m=read();
	for(int i=1;i<=n;++i)a[i]=read(),V.push_back(i),t[i]=a[i];
	sort(t+1,t+n+1);int Max=unique(t+1,t+n+1)-t-1;
	for(int i=1;i<=m;++i){
		x=read();y=read();
		E.push_back((edge){x,y});
	}
	solve(V,E,1,Max);
	for(int i=1;i<=n;++i)cout<<c[i]<<" ";
	return 0;
}