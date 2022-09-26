#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define N 500020
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
int n,m,a[N],pos,las[N];
vector<int> G[N],b[N],ans;
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		G[u].push_back(v),G[v].push_back(u);
	}
	for(int i=1;i<=n;++i){
		a[i]=read();
		b[a[i]].push_back(i);
	}
	for(int i=1;i<=n;++i){
		for(auto v:b[i]){
			++pos;
			ans.push_back(v);
			for(auto p:G[v]){
				las[a[p]]=pos;
			}
			for(auto p:G[v]){
				if(a[p]==a[v]){
					printf("-1\n");
					return 0;
				}
			}
			for(int j=1;j<a[v];++j){
				if(las[j]^pos){
					printf("-1\n");
					return 0;
				}
			}
		}
	}
	for(auto x:ans){
		printf("%d ",x);
	}
	return 0;
}