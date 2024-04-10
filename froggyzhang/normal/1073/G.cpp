//qwqwq
#include<bits/stdc++.h>
using namespace std;
#define N 400010
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
int n,Q,pos[N];
char s[N];
struct SAM{
	int las,tot;
	struct node{
		int ch[26],fa,len;
	}t[N];
	SAM(){las=tot=1;}
	void Insert(int c){
		int u=++tot,p=las;
		t[u].len=t[p].len+1;
		while(p&&!t[p].ch[c]){
			t[p].ch[c]=u;
			p=t[p].fa;
		}
		if(!p)t[u].fa=1;
		else{
			int q=t[p].ch[c];
			if(t[q].len==t[p].len+1)t[u].fa=q;
			else{
				int v=++tot;
				t[v]=t[q],t[v].len=t[p].len+1;
				while(p&&t[p].ch[c]==q){
					t[p].ch[c]=v;
					p=t[p].fa;
				}
				t[q].fa=t[u].fa=v;
			}
		}
		las=u;
	}
}T;
int dfn[N],num;
int top[N],son[N],dep[N],f[N],siz[N];
vector<int> G[N],H[N];
pair<int,int> a[N];
int ca[N],cb[N];
void dfs1(int u){
	siz[u]=1;
	for(auto v:G[u]){
		f[v]=u;
		dep[v]=dep[u]+1;
		dfs1(v);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]){
			son[u]=v;
		}
	}
}
void dfs2(int u,int topf){
	top[u]=topf;
	dfn[u]=++num;
	if(!son[u])return;
	dfs2(son[u],topf);
	for(auto v:G[u]){
		if(v==son[u])continue;
		dfs2(v,v);
	}
}
inline int LCA(int x,int y){
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=f[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	return x;
}
ll ans;
void dfs3(int u){
	ans+=1LL*T.t[u].len*ca[u]*cb[u];
	for(auto v:H[u]){
		dfs3(v);
		ans+=T.t[u].len*(1LL*ca[u]*cb[v]+1LL*ca[v]*cb[u]);
		ca[u]+=ca[v];
		cb[u]+=cb[v];
	}	
}
inline void adde(int u,int v){
	H[u].push_back(v);
}
ll Solve(int tot){
	static int st[N],top;
	static vector<int> bin;
	bin.clear();
	bin.push_back(1);
	st[top=1]=1;
	for(int i=1;i<=tot;++i){
		int u=a[i].first,tp=a[i].second;
		tp?++cb[u]:++ca[u];
		if(st[top]==u)continue;
		bin.push_back(u);
		int lca=LCA(u,st[top]);
		while(top>1&&dfn[st[top-1]]>=dfn[lca])adde(st[top-1],st[top]),--top;
		if(lca^st[top]){
			bin.push_back(lca);
			adde(lca,st[top]);
			st[top]=lca;
		}
		st[++top]=u;
	}
	while(top>1)adde(st[top-1],st[top]),--top;
	ans=0;
	dfs3(1);
	for(auto u:bin){
		H[u].clear();
		ca[u]=cb[u]=0;	
	}
	return ans;
}
int main(){
	n=read(),Q=read();
	scanf("%s",s+1);
	for(int i=n;i>=1;--i){
		T.Insert(s[i]-'a');
		pos[i]=T.las;
	}
	for(int i=2;i<=T.tot;++i){
		G[T.t[i].fa].push_back(i);
	}
	dfs1(1);
	dfs2(1,1);
	while(Q--){
		int ka=read(),kb=read();
		for(int i=1;i<=ka;++i)a[i]=make_pair(pos[read()],0);
		for(int i=1;i<=kb;++i)a[i+ka]=make_pair(pos[read()],1);
		sort(a+1,a+ka+kb+1,[&](pair<int,int> i,pair<int,int> j){return dfn[i.first]<dfn[j.first];});
		printf("%lld\n",Solve(ka+kb));
	}
	return 0;
}