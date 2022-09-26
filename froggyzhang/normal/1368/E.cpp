#include<iostream>
#include<cstdio>
#include<cstring>
#include<assert.h>
#include<vector>
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
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int T;
vector<int> G[N],ans;
void Solve(){
	int n=read(),m=read();
	static int d[N],del[N];
	ans.clear();
	for(int i=1;i<=n;++i){
		G[i].clear();
		d[i]=del[i]=0;
	}
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		++d[v];
	}
	for(int u=1;u<=n;++u){
		if(del[u]||!d[u])continue;
		for(auto v:G[u]){
			if(!del[v]){
				del[v]=1;
				ans.push_back(v);
				for(auto myh:G[v])--d[myh];
			}
		}
	}
	assert((int)ans.size()<=n*4/7);
	printf("%d\n",(int)ans.size());
	for(auto x:ans){
		printf("%d ",x);
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