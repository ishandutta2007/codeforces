#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
#define N 100010
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
vector<pair<int,int> > G[N];
vector<int> ans;
queue<int> q;
int n,m,a[N],b[N],vis[N<<1];
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		G[u].emplace_back(v,i);
		G[v].emplace_back(u,i);
		++b[u],++b[v];
	}
	for(int i=1;i<=n;++i){
		if(a[i]>=b[i])q.push(i);
	}
	for(int i=1;i<=n;++i){
		if(q.empty()){
			printf("DEAD\n");
			return 0;
		}
		int u=q.front();
		q.pop();
		for(auto qwq:G[u]){
			int v=qwq.first,id=qwq.second;
			if(vis[id])continue;
			--b[v];
			vis[id]=1;
			ans.push_back(id);
			if(a[v]==b[v])q.push(v);
		}
	}
	printf("ALIVE\n");
	for(int i=(int)ans.size()-1;i>=0;--i){
		printf("%d ",ans[i]);
	}
	return 0;
}