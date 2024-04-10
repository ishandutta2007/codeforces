#include<bits/stdc++.h>
using namespace std;
#define N 500050
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
int T,n,m,d[N],vis[N],t[N],a[N],b[N],to[N];
vector<int> G[N],H[N],c[N];
void Trans(int l,int r){
	int tmp=t[l];
	for(int i=l;i<r;++i)t[i]=t[i+1];
	t[r]=tmp;
}
void Solve(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		d[i]=vis[i]=to[i]=0;
		G[i].clear(),H[i].clear();
		c[i].clear();
	}
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int u=1;u<=n;++u){
		for(auto v:G[u])vis[v]=1;
		int p=-1;
		for(int j=1;j<=n;++j){
			if(!vis[j]&&u^j){p=j;break;}
		}
		for(auto v:G[u])vis[v]=0;
		if(~p&&to[p]^u){
			H[u].push_back(p);
			H[p].push_back(u);
			++d[u],++d[p];
			to[u]=p;
		}
	}
	queue<int> q1,q2;
	int now=0;
	for(int i=1;i<=n;++i){
		if(!d[i])a[i]=++now,t[now]=i;
		if(d[i]==1){
			q1.push(i);
		}
	}
	while(!q1.empty()||!q2.empty()){
		int u;
		if(!q1.empty()){
			u=q1.front();
			q1.pop();
			vis[u]=1;
			if(!c[u].empty()){
				q2.push(u);continue;
			}
			for(auto v:H[u]){
				c[v].push_back(u);
			}
		}
		else{
			u=q2.front();
			q2.pop();
			a[u]=++now,t[now]=u;
			int las=now;
			for(auto x:c[u]){
				a[x]=++now,t[now]=x;
			}
			Trans(las,now);
		}
		for(auto v:H[u]){
			if(!vis[v]){
				if((--d[v])==1)q1.push(v);
			}
		}
	}
	for(int i=1;i<=n;++i){
		b[t[i]]=i;
	}
	for(int i=1;i<=n;++i){
		printf("%d ",a[i]);
	}
	printf("\n");
	for(int i=1;i<=n;++i){
		printf("%d ",b[i]);
	}
	printf("\n");
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}