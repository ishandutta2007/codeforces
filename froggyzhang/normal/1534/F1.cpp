#include<bits/stdc++.h>
using namespace std;
#define N 400040
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
int n,m;
int a[N];
vector<int> G[N];
vector<int> g[N];
int dfn[N],low[N],num,ins[N],tot,col[N],siz[N],d[N];
vector<pair<int,int> > E;
const int D[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int st[N],top;
char s[N];
inline int ID(int x,int y){
	return (x-1)*m+y;
}
void Tarjan(int u){
	dfn[u]=low[u]=++num;
	st[++top]=u;
	ins[u]=1;
	for(auto v:G[u]){
		if(!dfn[v]){
			Tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(ins[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(low[u]==dfn[u]){
		int t=0;
		++tot;
		while(t^u){
			t=st[top--];
			col[t]=tot;
			siz[tot]+=a[t];
			ins[t]=0;
		}		
	}
}
inline void adde(int u,int v){
	G[u].push_back(v);
	E.emplace_back(u,v);
}
int main(){
	n=read(),m=read();
	for(int i=n;i>=1;--i){
		scanf("%s",s+1);	
		for(int j=1;j<=m;++j){
			if(s[j]=='#')a[ID(i,j)]=true,g[j].push_back(i);
		}
	}
	for(int j=1;j<=m;++j){
		reverse(g[j].begin(),g[j].end());
	}
	for(int j=1;j<=m;++j){
		int l=0,r=0;
		for(int pi=0;pi<(int)g[j].size();++pi){
			int i=g[j][pi];
			if(pi>=1){
				adde(ID(i,j),ID(g[j][pi-1],j));
				if(i-1==g[j][pi-1])adde(ID(g[j][pi-1],j),ID(i,j));
			}
			while(l<(int)g[j-1].size()&&g[j-1][l]<=i){
				adde(ID(i,j),ID(g[j-1][l],j-1));
				++l;
			}
			while(r<(int)g[j+1].size()&&g[j+1][r]<=i){
				adde(ID(i,j),ID(g[j+1][r],j+1));
				++r;
			}
		}
	}
	for(int i=1;i<=n*m;++i){
		if(!dfn[i])Tarjan(i);
	}
	for(auto [x,y]:E){
	//	cerr<<" E: "<<x<<" "<<y<<" "<<col[x]<<" "<<col[y]<<endl;
		if(col[x]^col[y]){
			++d[col[y]];
		}
	}
	int ans=0;
	for(int i=1;i<=tot;++i){
		if(siz[i]&&!d[i])++ans;
	}
	printf("%d\n",ans);
	return 0;
}