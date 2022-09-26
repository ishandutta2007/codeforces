#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
using namespace std;
#define N 1000010
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
int n,Q,t[N];
bool c[N][2],a[N];
vector<int> G[N];
void dfs1(int u){
	if(t[u]==-1)return;
	for(auto v:G[u]){
		dfs1(v);
	}
	if(t[u]==1){
		a[u]=a[G[u][0]]^1;
	}
	else if(t[u]==2){
		a[u]=a[G[u][0]]&a[G[u][1]];
	}
	else if(t[u]==3){
		a[u]=a[G[u][0]]|a[G[u][1]];
	}
	else{
		a[u]=a[G[u][0]]^a[G[u][1]];
	}
}
void dfs2(int u){
	if(t[u]==-1)return;
	if(t[u]==1){
		int v=G[u][0];
		c[v][0]=c[u][1];
		c[v][1]=c[u][0];
	}
	else if(t[u]==2){
		for(int i=0;i<2;++i){
			int v=G[u][i];
			for(int x=0;x<2;++x){
				c[v][x]=c[u][a[G[u][i^1]]&x];
			}
		}
	}
	else if(t[u]==3){
		for(int i=0;i<2;++i){
			int v=G[u][i];
			for(int x=0;x<2;++x){
				c[v][x]=c[u][a[G[u][i^1]]|x];
			}
		}
	}
	else{
		for(int i=0;i<2;++i){
			int v=G[u][i];
			for(int x=0;x<2;++x){
				c[v][x]=c[u][a[G[u][i^1]]^x];
			}
		}
	}
	for(auto v:G[u]){
		dfs2(v);
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		static char s[23];
		scanf("%s",s+1);
		if(s[1]=='I'){
			a[i]=read();
			t[i]=-1;
		}
		else{
			if(s[1]=='A'){
				t[i]=2;
			}
			else if(s[1]=='O'){
				t[i]=3;
			}
			else if(s[1]=='X'){
				t[i]=4;
			}
			else{
				t[i]=1;
			}
			G[i].push_back(read());
			if(t[i]!=1)G[i].push_back(read());
		}
	}
	dfs1(1);
	c[1][0]=false,c[1][1]=true;
	dfs2(1);
	for(int i=1;i<=n;++i){
		if(!~t[i])printf("%d",c[i][a[i]^1]);
	}
	return 0;
}