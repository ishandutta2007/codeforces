#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
typedef long long ll;
#define N 100010
const ll mod=1e9+7;
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
int n,p[N],m;
int cnt=0;
int head[N];
int low[N],num=0,dfn[N],tot=0,col[N];
ll ans=0,plan=0;
int vis[N];
stack<int> st;
struct Edge{
	int to,nxt;
}edge[N<<2];
void add(int a,int b){
	cnt++;
	edge[cnt].to=b;
	edge[cnt].nxt=head[a];
	head[a]=cnt;
} 
void Tarjan(int u){
	low[u]=dfn[u]=++num;
	st.push(u);
	vis[u]=1;
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
	if(dfn[u]==low[u]){
		int t=0;
		tot++;
		ll w=mod;
		ll ak=0;
		while(t!=u){
			t=st.top();
			st.pop();
			vis[t]=0;
			col[t]=tot;
			if(p[t]<w){
				w=p[t];
				ak=1;
			}
			else if(p[t]==w){
				ak++;
			}
		}
		ans+=w;
		plan=plan*ak%mod;
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		p[i]=read();
	}
	m=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		add(u,v);
	}
	plan=1;
	for(int i=1;i<=n;i++){
		if(!dfn[i]){
			Tarjan(i);
		}
	}
	printf("%lld %lld\n",ans,plan);
	return 0;
}