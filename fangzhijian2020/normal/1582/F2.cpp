#pragma GCC optimize(2)
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#pragma GCC optimize(3,"Ofast","inline")
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
//	return getchar();
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
int read(){
	int a=0;bool opt=0;char c=gc();
	while(c<'0'||c>'9')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
int n,a[1000005],pre[1000005],tp[5005],L[10005],Vis[10005],ans;
vector<int>v[10005],answer;
struct node{
	int x,y;
};vector<node>g[1000005];
int main(){
	n=read();
	for(int i=0;i<=5000;++i){
		tp[i]=0;
	}
	for(int j=0;j<=10000;++j){
		L[j]=5001;
	}
	for(int i=1;i<=n;++i){
		a[i]=read();
		if(!pre[a[i]]){
			g[i].push_back((node){a[i],a[i]});
		}
		pre[a[i]]=i;v[a[i]].push_back(i);
	}
	Vis[0]=1;++ans;answer.push_back(0);
	int cnt=0;
	for(int x=1;x<=n;++x){
		for(int j=0;j<g[x].size();++j){
			node now=g[x][j];
			if(!Vis[now.y]){
				++ans;Vis[now.y]=1;answer.push_back(now.y);
			}
			for(int i=now.x+1;i<L[now.y];++i){
				while(tp[i]<v[i].size()&&v[i][tp[i]]<x)++tp[i];
				int Next=tp[i];
				if(Next<v[i].size()){
					Next=v[i][Next];
					g[Next].push_back((node){i,i^now.y});
				}
			}
			L[now.y]=min(L[now.y],now.x+1);	
		}
	}

	cout<<ans<<"\n";sort(answer.begin(),answer.end());
	for(int i=0;i<answer.size();++i)cout<<answer[i]<<" ";
	return 0;
}