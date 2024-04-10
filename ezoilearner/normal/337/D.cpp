#include<iostream>
#include<cstring>
#include<cstdio>
#include<stack>
#include<algorithm>
using namespace std;
int n,m,d;
#define maxn 100010
int head[maxn],v[maxn*2],nxt[maxn*2],tot=0;
bool ap[maxn];
int ans1[maxn],ans2[maxn];
stack<int> st;
void add_edge(int s,int e){
	tot++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;
	tot++;v[tot]=s;nxt[tot]=head[e];head[e]=tot;
}
void dfs1(int u,int f){
	if(ap[u])ans1[u]=0;
	for(int i=head[u];i;i=nxt[i])
	if(v[i]!=f){
	dfs1(v[i],u);
	if(ans1[v[i]]!=-1)ans1[u]=max(ans1[u],ans1[v[i]]+1);
}
}
void dfs2(int u,int f){
	if(ans2[u]!=-1)
		for(int i=head[u];i;i=nxt[i])
		if(v[i]!=f)ans2[v[i]]=max(ans2[v[i]],ans2[u]+1);
	if(ap[u])
	    for(int i=head[u];i;i=nxt[i])
	    if(v[i]!=f)ans2[v[i]]=max(ans2[v[i]],1);
	int ans=-1;
	for(int i=head[u];i;i=nxt[i])
	if(v[i]!=f){
		if(ans!=-1)ans2[v[i]]=max(ans2[v[i]],ans+1);
		if(ans1[v[i]]!=-1)ans=max(ans,ans1[v[i]]+1);
		st.push(v[i]);
	}
	ans=-1;
	while(!st.empty()){
		int now=st.top();
		st.pop();
		if(ans!=-1)ans2[now]=max(ans2[now],ans+1);
		if(ans1[now]!=-1)ans=max(ans,ans1[now]+1); 
	}
	for(int i=head[u];i;i=nxt[i])
	if(v[i]!=f)dfs2(v[i],u);
}
int main(){
	memset(ans1,-1,sizeof(ans1));
	memset(ans2,-1,sizeof(ans2));
	scanf("%d%d%d",&n,&m,&d);
	int x;
	for(int i=1;i<=m;++i){
		scanf("%d",&x);
		ap[x]=true;
	}
	int s,e;
	for(int i=1;i<n;++i){
		scanf("%d%d",&s,&e);
		add_edge(s,e);
	}
	dfs1(1,0);
	dfs2(1,0);
	int ans=0;
	for(int i=1;i<=n;++i)
	if(max(ans1[i],ans2[i])<=d)ans++;
	printf("%d\n",ans);
	return 0;
}