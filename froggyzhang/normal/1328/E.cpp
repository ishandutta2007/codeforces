#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 200200
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
int n,dfn[N],m,f[N],cnt,head[N],num,a[N],siz[N];
struct Edge{
	int to,nxt;
}edge[N<<1];
void add(int a,int b){
	++cnt;
	edge[cnt].to=b;
	edge[cnt].nxt=head[a];
	head[a]=cnt;
}
void dfs(int u,int fa){
	f[u]=fa;
	siz[u]=1;
	dfn[u]=++num;
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==fa)continue;
		dfs(v,u);
		siz[u]+=siz[v];
	}
}
bool cmp(int i,int j){
	return dfn[i]<dfn[j];
}
int main(){
	n=read(),m=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		add(u,v),add(v,u);
	}
	dfs(1,0);
	for(int i=1;i<=m;++i){
		int k=read();
		for(int j=1;j<=k;++j){
			a[j]=read();
			if(a[j]^1)a[j]=f[a[j]];
		}
		sort(a+1,a+k+1,cmp);
		bool ok=true;
		for(int i=2;i<=k;++i){
			if(dfn[a[i]]>dfn[a[i-1]]+siz[a[i-1]]-1){
				ok=false;
				break;
			} 
		}
		printf(ok?"YES\n":"NO\n");
	}
	return 0;
}