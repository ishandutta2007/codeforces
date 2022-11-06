#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int Mxdt=100000,N=2000000,INF=1e9;
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
int n,m,s[505][505],t[505][505],ans;char c[505][505];
int S,T,sum,h[1005],cnt=1;struct edge{int to,next,v;}e[2000005];
void add(int x,int y,int z){
	e[++cnt]=(edge){y,h[x],z};h[x]=cnt;
	e[++cnt]=(edge){x,h[y],0};h[y]=cnt;
}
queue<int>q;int d[1005];
bool bfs(int s,int t){
	int i,y;while(!q.empty())q.pop();
	for(int i=s;i<=t;++i)d[i]=0;
	q.push(s);d[s]=1;
	while(!q.empty()){
		int x=q.front();q.pop();
		if(x==t)return 1;
		for(i=h[x];i;i=e[i].next){
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
			int del=dfs(y,min(e[i].v,maxf),t);
			if(!del)d[y]=0;
			e[i].v-=del;e[i^1].v+=del;
			maxf-=del;ret+=del;
			if(!maxf)return ret;
		}
	}
	return ret;
}
int main(){
	n=read();m=read();
	for(int i=1;i<=n;++i){
		scanf("%s",c[i]+1);
	}
	for(int i=n;i;--i){
		for(int j=m;j;--j){
			s[i][j]^=s[i][j+1]^s[i+1][j]^s[i+1][j+1];
			if(c[i][j]=='B'&&!s[i][j])t[i][j]=1;
			if(c[i][j]=='W'&&s[i][j])t[i][j]=1;
			s[i][j]^=t[i][j];ans+=t[i][j];
		}
	}
	S=0;T=n+m;
	for(int i=1;i<n;++i)add(S,i,1);
	for(int i=1;i<m;++i)add(i+n,T,1);
	for(int i=1;i<n;++i){
		for(int j=1;j<m;++j){
			if(t[i][j]&&t[n][j]&&t[i][m]){
				add(i,j+n,1);
			}
		}
	}
	while(bfs(S,T))sum+=dfs(S,INF,T);
	if(!t[n][m])t[n][m]=-1;
	if(sum&1)ans-=t[n][m];ans-=sum;
	cout<<ans<<"\n";
	return 0;
}