#include<iostream>
#include<cstdio>
#include<cstring>
#include<assert.h>
#include<vector>
using namespace std;
#define N 1010
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
int n,L,root,dep[N],b[N],siz[N],maxdep,l,r,ans,T,ans2;
vector<int> G[N],t[N],tmp;
char END[23];
void dfs(int u,int fa,int from){
	b[u]=from;
	dep[u]=dep[fa]+1;
	maxdep=max(maxdep,dep[u]);
	siz[u]=1;
	t[dep[u]].push_back(u);
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u,from);
		siz[u]+=siz[v];
	}
}
void dfs2(int u,int fa,int dep){
	if(dep==L){
		tmp.push_back(u);
		return ;
	}
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs2(v,u,dep+1);
	}
} 
void Solve(){
	n=read();
	t[0].clear();
	for(int i=1;i<=n;++i){
		G[i].clear();
		t[i].clear();
	} 
	tmp.clear();
	maxdep=root=L=ans=ans2=l=r=0;
	memset(siz,0,sizeof(siz));
	memset(b,0,sizeof(b));
	memset(dep,0,sizeof(dep));
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	printf("? %d ",n);
	for(int i=1;i<=n;++i){
		printf("%d ",i);
	}
	printf("\n");
	fflush(stdout);
	root=read(),L=read();
	t[0].push_back(root);
	for(auto v:G[root]){
		dfs(v,root,v);
		siz[root]+=siz[v];
	}
	if(!maxdep){
		ans=root;
	}
	else{
		l=max(0,L/2-1),r=min(L,maxdep)+1;
		while(l<r){
			int mid=(l+r)>>1;
			assert(t[mid].size());
			printf("? %d ",(int)t[mid].size());
			for(auto x:t[mid]){
				printf("%d ",x);
			}
			printf("\n");
			fflush(stdout);
			int s=read(),d=read();
			if(d==L){
				l=mid+1,ans=s;
			}
			else{
				r=mid;
			}
		}
	}
	dfs2(ans,0,0);
	assert(tmp.size());
	printf("? %d ",(int)tmp.size());
	for(auto x:tmp){
		printf("%d ",x);
	}
	printf("\n");
	fflush(stdout);
	ans2=read(),L=read();
	printf("! %d %d\n",ans,ans2);
	fflush(stdout);
	scanf("%s",END+1);
	assert(END[1]=='C');
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}