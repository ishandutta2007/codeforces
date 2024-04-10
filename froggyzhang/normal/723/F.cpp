#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define N 200020
#define myhmd return !printf("No\n")
inline int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,A,B,dA,dB,bel[N],tot,a[N],vis[N],tA[N],tB[N];
vector<int> G[N];
vector<pair<int,int> > ans;
void dfs(int u){
	for(auto v:G[u]){
		if(bel[v]||v==A||v==B)continue;
		bel[v]=bel[u];
		ans.emplace_back(u,v);
		dfs(v);
	}
}
int main(){
	n=read(),m=read();
	for(int i=1; i<=m; ++i) {
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	A=read(),B=read(),dA=read(),dB=read();
	for(int i=1; i<=n; ++i){
		if(i==A||i==B||bel[i])continue;
		bel[i]=i;
		dfs(i);
		a[++tot]=i;
	}
	if(tot>=dA+dB)myhmd;
	for(auto v:G[A])vis[bel[v]]|=1;
	for(auto v:G[B])vis[bel[v]]|=2;
	for(int i=1;i<=tot;++i){
		if(!vis[a[i]])myhmd;
	}
	for(auto v:G[A]){
		if(v==B)continue;
		if(vis[bel[v]]==1){
			ans.emplace_back(A,v);
			vis[bel[v]]=0;
			if(!--dA)myhmd;
		}
		else if(vis[bel[v]]==3)tA[bel[v]]=v;
	}
	for(auto v:G[B]){
		if(v==A)continue;
		if(vis[bel[v]]==2){
			ans.emplace_back(B,v);
			vis[bel[v]]=0;
			if(!--dB)myhmd;
		}
		else if(vis[bel[v]]==3)tB[bel[v]]=v;
	}
	bool ok=false;
	for(int i=1;i<=tot;++i){
		if(vis[a[i]]==3){
			if(!ok){
				ans.emplace_back(A,tA[a[i]]);
				ans.emplace_back(B,tB[a[i]]);
				--dA,--dB;
				ok=true;
				continue;
			}
			if(dA){
				ans.emplace_back(A,tA[a[i]]);
				--dA;
			}
			else if(dB){
				ans.emplace_back(B,tB[a[i]]);
				--dB;
			}
			else myhmd;
		}
	}
	if(!ok){
		if(dA&&dB){
			ans.emplace_back(A,B);
		}
		else myhmd;
	}
	printf("Yes\n");
	for(auto x:ans){
		printf("%d %d\n",x.first,x.second);
	}
	return 0;
}