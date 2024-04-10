#include<bits/stdc++.h>
using namespace std;
#define N 200020
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
int n,Q,pos[N<<1];
struct BIT{
	int b[N<<1];
	inline int lowbit(int x){return x&(-x);}
	inline void Add(int x,int d){
		while(x<=n+200000)b[x]+=d,x+=lowbit(x);
	}
	inline int Ask(int x){
		int ans=0;while(x)ans+=b[x],x-=lowbit(x);return ans;
	}		
}B;
vector<int> G[N];
struct LCT{
	struct node{
		int fa,siz,ch[2],id;
		bool rev;
		node(){siz=fa=ch[0]=ch[1]=rev=0;}
		inline void Rev(){
			rev^=1;
			swap(ch[0],ch[1]);
		}
	}t[N];
	#define ls t[x].ch[0]
	#define rs t[x].ch[1]
	inline int Get(int x){return t[t[x].fa].ch[1]==x;}
	inline bool IsRoot(int x){return t[t[x].fa].ch[0]^x&&t[t[x].fa].ch[1]^x;}
	inline void Connect(int x,int fa,int p){t[x].fa=fa,t[fa].ch[p]=x;}
	inline void update(int x){
		t[x].siz=t[ls].siz+t[rs].siz+1;
	}
	inline void pushdown(int x){
		if(t[x].rev){
			t[ls].Rev();
			t[rs].Rev();
			t[x].rev=0;
		}
	}
	inline void Rotate(int x){
		int fa=t[x].fa,gfa=t[fa].fa;
		int d1=Get(x),d2=Get(fa);
		if(!IsRoot(fa))Connect(x,gfa,d2);
		else t[x].fa=gfa;
		Connect(t[x].ch[d1^1],fa,d1);
		Connect(fa,x,d1^1);
		update(fa);
		update(x);
	}
	inline void Splay(int x){
		static int st[N],top;
		int y=x;
		st[top=1]=x;
		while(!IsRoot(y))y=t[y].fa,st[++top]=y;
		while(top)pushdown(st[top--]);
		while(!IsRoot(x)){
			y=t[x].fa;
			if(!IsRoot(y)){
				Rotate(Get(x)^Get(y)?x:y);
			}
			Rotate(x);
		}
	}
	int Find(int x){
		pushdown(x);
		while(rs)pushdown(x=rs);
		return x;	
	}
	void Access(int x){
		for(int y=0;x;y=x,x=t[x].fa){
			Splay(x);
			B.Add(t[Find(x)].id,t[rs].siz-t[x].siz);
			rs=y;
			update(x);
		}
	}
	int Query(int x){
		Splay(x);
		return B.Ask(t[Find(x)].id-1)+t[rs].siz+1;	
	}
	void makeroot(int x){
		if(pos[n]==x){
			t[x].id=++n;pos[n]=x;return;	
		}
		Access(x),Splay(x);
		B.Add(n,t[x].siz);
		pos[++n]=x;
		t[x].id=n;
		t[x].Rev();
	}
}T;
void dfs(int u,int fa){
	T.t[u].fa=fa;
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u);
	}
}
int main(){
	n=read(),Q=read();
	for(int i=1;i<=n;++i){
		B.Add(i,1);
		T.t[i].siz=1;
		T.t[i].id=pos[i]=i;
	}
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(n,0);
	for(int i=1;i<n;++i){
		T.Access(i);
		T.Splay(i);
		B.Add(i,T.t[i].siz);
	}
	while(Q--){	
		static char opt[10];
		scanf("%s",opt);
		if(opt[0]=='u'){
			int u=read();
			T.makeroot(u);
		}
		else if(opt[0]=='w'){
			int u=read();
			printf("%d\n",T.Query(u));
		}
		else{
			int u=read(),v=read();
			printf("%d\n",T.Query(u)<T.Query(v)?u:v);
		}
	}
	return 0;
}