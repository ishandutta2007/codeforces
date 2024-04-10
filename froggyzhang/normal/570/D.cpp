#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define N 500050
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
vector<pair<int,int> > q[N];
int n,m,f[N],cnt[N][26],siz[N],dep[N],son[N],vis[N];
char s[N];
bool ok[N];
vector<int> G[N];
void dfs1(int u){
	siz[u]=1;
	for(auto v:G[u]){
		dep[v]=dep[u]+1;
		dfs1(v);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]){
			son[u]=v;
		}
	}
}
void calc(int u,int val){
	cnt[dep[u]][s[u]-'a']+=val;
	for(auto v:G[u]){
		if(vis[v])continue;
		calc(v,val);
	}
}
void dfs2(int u,bool keep){
	for(auto v:G[u]){
		if(v==son[u])continue;
		dfs2(v,false);
	}
	if(son[u])dfs2(son[u],true),vis[son[u]]=1;
	calc(u,1);vis[son[u]]=0;
	for(auto qwq:q[u]){
		int id=qwq.second,k=qwq.first;
		ok[id]=true;
		int odd=0;
		for(int i=0;i<26;++i){
			if(cnt[k][i]&1)++odd;
			if(odd>1){
				ok[id]=false;break;
			}
		}
	}
	if(!keep)calc(u,-1);
}
int main(){
	n=read(),m=read();
	for(int i=2;i<=n;++i){
		f[i]=read();
		G[f[i]].push_back(i);
	}
	scanf("%s",s+1);
	for(int i=1;i<=m;++i){
		int x=read(),dep=read();
		q[x].push_back(make_pair(dep,i));
	}
	dep[1]=1;
	dfs1(1);
	dfs2(1,0);
	for(int i=1;i<=m;++i){
		printf(ok[i]?"Yes\n":"No\n");
	}
	return 0;
}