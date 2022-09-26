#include<bits/stdc++.h>
using namespace std;
#define N 5000010
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
int n,m,d;
int cnt,head[N],x[N],y[N],all;
struct Edge{
	int to,nxt;
}edge[N];
inline void adde(int u,int v){
	++cnt;
	edge[cnt].to=v;
	edge[cnt].nxt=head[u];
	head[u]=cnt;
}
char s[100010][52];
int col[N],dfn[N],tot,low[N],num,vis[N],val[N];
void Tarjan(int u){
	static int st[N],top;
	low[u]=dfn[u]=++num;
	vis[u]=1;
	st[++top]=u;
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(!dfn[v]){
			Tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(vis[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(low[u]==dfn[u]){
		++tot;
		int t=0;
		while(t^u){
			t=st[top--];
			vis[t]=0;
			col[t]=tot;
		}
	}
}
int dp[N];
int dfs(int u){
	if(vis[u])return dp[u];
	vis[u]=1;
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		dp[u]=max(dp[u],dfs(v));
	}
	dp[u]+=val[u];
	return dp[u];
}
int main(){
	n=read(),m=read(),d=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		for(int j=0;j<d;++j){
			adde(j*n+u,(j+1)%d*n+v);
			++all;
			x[all]=j*n+u;
			y[all]=(j+1)%d*n+v;
		}
	}
	for(int i=1;i<=n;++i){
		scanf("%s",s[i]);
	}
	for(int i=1;i<=d*n;++i){
		if(!dfn[i])Tarjan(i);
	}
	cnt=0;
	memset(head,0,sizeof(head));
	for(int i=1;i<=n;++i){
		static int v[N];
		for(int j=0;j<d;++j){
			if(s[i][j]=='0')continue;
			int u=j*n+i;
			if(!v[col[u]]){
				++val[col[u]];
				v[col[u]]=1;
			}	
		}
		for(int j=0;j<d;++j){
			v[col[j*n+i]]=0;
		}
	}
	for(int i=1;i<=all;++i){
		int u=x[i],v=y[i];
		if(col[u]^col[v]){
			adde(col[u],col[v]);
		}	
	}
	printf("%d\n",dfs(col[1]));
	return 0;
}