#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
#define N 200020
inline int read(){
	int x=0,f=1;
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
int T,n,m,d[N],t[N];
vector<int> G1[N],G2[N];
queue<int> q;
void Solve(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		G1[i].clear(),G2[i].clear();
		d[i]=t[i]=0;
	}
	for(int i=1;i<=m;++i){
		int t=read(),u=read(),v=read();
		if(t){
			G1[v].push_back(u);
			++d[u];
		}
		else{
			G2[u].push_back(v);
		}
	}
	for(int i=1;i<=n;++i){
		if(!d[i])q.push(i);
	}
	int num=0;
	while(!q.empty()){
		int u=q.front();
		t[u]=++num;
		q.pop();
		for(auto v:G1[u]){
			if(!--d[v]){
				q.push(v);
			}
		}
	}
	for(int i=1;i<=n;++i){
		if(d[i]){
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
	for(int u=1;u<=n;++u){
		for(auto v:G1[u]){
			printf("%d %d\n",v,u);
		}
	}
	for(int u=1;u<=n;++u){
		for(auto v:G2[u]){
			if(t[u]>t[v]){
				printf("%d %d\n",u,v);
			}
			else{
				printf("%d %d\n",v,u);
			}
		}
	}
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}