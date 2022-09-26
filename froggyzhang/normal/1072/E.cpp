#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstdlib>
#include<tuple>
#include<cassert>
using namespace std;
#define N 200000
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,a[N],pre[N],S,vis[N];
queue<int> q;
pair<int,int> g[N];
vector<tuple<int,int,int> > ans;
void dfs(int u,int d,pair<int,int> *g){
	if(u==S)return;
	auto [i,j]=g[u];
	dfs(u^(1<<i-j)^(1<<i)^(1<<i+j),d,g);
	ans.emplace_back(i-j+d,i+d,i+j+d);
}
void bfs(int d,int n,int flag){
	S=0;
	for(int i=0;i<n;++i){
		if(a[i+d])S|=1<<i;
	}
	while(!q.empty())q.pop();
	q.push(S);
	vis[S]=d;
	int T=-1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(!(u&((1<<flag)-1))){
			T=u;break;
		}
		for(int i=1;i<n-1;++i){
			for(int j=1;;++j){
				if(i-j<0||i+j>=n)break;
				int v=u^(1<<i)^(1<<i-j)^(1<<i+j);
				if(vis[v]==d)continue;
				vis[v]=d;
				g[v]=make_pair(i,j);
				q.push(v);
			}
		}
	}
	if(~T){
		dfs(T,d,g);
		for(int i=0;i<n;++i){
			a[d+i]=(T>>i&1);
		}
	}
	else{
		printf("NO\n");
		exit(0);
	}
}
void Output(){
	printf("YES\n");
	printf("%d\n",(int)ans.size());
	for(auto [x,y,z]:ans){
		printf("%d %d %d\n",x,y,z);
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=1;i<=n;i+=6){
		if(n-i+1<=14){
			bfs(i,n-i+1,n-i+1);
			break;
		}
		else{
			bfs(i,12,6);
		}
	}
	Output();
	return 0;
}