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
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int n,a[1000005],pre[5005],d[5005][5005],L[5005],vis[5005][5005],Vis[5005],ans;
vector<int>v[5005],answer;
struct node{
	int x,y,v;
	bool operator<(const node&a)const{
		return v>a.v;
	}
};
priority_queue<node>q;
int main(){
	n=read();
	for(int i=1;i<=5000;++i){
		L[i]=5000;
		for(int j=1;j<=5000;++j){
			d[i][j]=n+1;
		}
	}
	for(int i=1;i<=n;++i){
		a[i]=read();
		if(!pre[a[i]]){
			d[a[i]][a[i]]=i;
			q.push((node){a[i],a[i],i});
		}
		pre[a[i]]=i;v[a[i]].push_back(i);
	}
	Vis[0]=1;++ans;answer.push_back(0);
	while(!q.empty()){
		node now=q.top();q.pop();
		if(vis[now.x][now.y])continue;
		vis[now.x][now.y]=1;
		if(!Vis[now.y]){
			++ans;Vis[now.y]=1;answer.push_back(now.y);
		}
		for(int i=now.x+1;i<L[now.y];++i){
			int Next=lower_bound(v[i].begin(),v[i].end(),d[now.x][now.y])-v[i].begin();
			if(Next<v[i].size()){
				Next=v[i][Next];
				if(d[i][i^now.y]>Next){
					d[i][i^now.y]=Next;
					q.push((node){i,i^now.y,d[i][i^now.y]});
				}	
			}
			
		}
		L[now.y]=min(L[now.y],now.x+1);
	}
	cout<<ans<<"\n";sort(answer.begin(),answer.end());
	for(int i=0;i<answer.size();++i)cout<<answer[i]<<" ";
	return 0;
}