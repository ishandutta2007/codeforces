#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,ch[500005][26],tot,fail[500005],dfn[500005],sign,size[500005],c[500005];
ll ans[500005];
char str[500005];
struct P{
	int id,k,dlt;
};
vector<int> g[200005],p[200005];
vector<P> q[200005];
void dfs(int x,int fa){
	dfn[x]=++sign,size[x]=1;
	for(int y:g[x])if(y^fa)dfs(y,x),size[x]+=size[y];
}
void U(int x,int k){
	while(x<=tot+1)c[x]+=k,x+=x&-x;
}
int Query(int x){
	int r=0;
	while(x)r+=c[x],x-=x&-x;
	return r;
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1,len,x; i<=n; i++) {
		scanf("%s",str),len=strlen(str),x=0;
		for(int j=0; j<len; j++) {
			int w=str[j]-'a';
			if(!ch[x][w])ch[x][w]=++tot;
			x=ch[x][w],p[i].push_back(x);
		}
	}
	queue<int> Q;
	for(int i=0; i<26; i++)if(ch[0][i])Q.push(ch[0][i]);
	while(!Q.empty()) {
		int x=Q.front();
		Q.pop(),g[fail[x]].push_back(x);
		for(int i=0; i<26; i++) {
			int y=ch[x][i];
			if(y)fail[y]=ch[fail[x]][i],Q.push(y);
			else ch[x][i]=ch[fail[x]][i];
		}
	}
	dfs(0,0);
	for(int i=1,l,r,k;i<=m;i++)scanf("%d%d%d",&l,&r,&k),
							   q[l-1].push_back({i,p[k].back(),-1}),q[r].push_back({i,p[k].back(),1});
	for(int i=1;i<=n;i++){
		for(int j:p[i])U(dfn[j],1);
		for(auto j:q[i])ans[j.id]+=j.dlt*(Query(dfn[j.k]+size[j.k]-1)-Query(dfn[j.k]-1));
	}
	for(int i=1;i<=m;i++)printf("%lld\n",ans[i]);
}