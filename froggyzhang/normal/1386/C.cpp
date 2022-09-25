#include<bits/stdc++.h>
using namespace std;
#define N 400040
typedef long long ll;
const int inf=0x3f3f3f3f;
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
int n,m,Q;
struct Link_Cut_Tree{
	struct node{
		int ch[2],fa,dis,mn,val;
		bool rev;
		node(){rev=false;mn=val=inf;}
		inline void Rev(){
			swap(ch[0],ch[1]);
			rev^=1;
		}
	}t[N];
	#define ls t[x].ch[0]
	#define rs t[x].ch[1]
	inline void update(int x){
		t[x].dis=t[ls].dis+t[rs].dis+1;
		t[x].mn=min(min(t[ls].mn,t[rs].mn),t[x].val);
	}
	inline void pushdown(int x){
		if(t[x].rev){
			t[ls].Rev();
			t[rs].Rev();
			t[x].rev=false;
		}
	}
	inline int Get(int x){return t[t[x].fa].ch[1]==x;}
	inline bool IsRoot(int x){return t[t[x].fa].ch[0]^x&&t[t[x].fa].ch[1]^x;}
	inline void Connect(int x,int fa,int p){
		t[x].fa=fa,t[fa].ch[p]=x;
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
	void Splay(int x){
		static int st[N],top;
		int y=x;
		st[top=1]=y;
		while(!IsRoot(y))y=t[y].fa,st[++top]=y;
		while(top)pushdown(st[top--]);
		while(!IsRoot(x)){
			int y=t[x].fa;
			if(!IsRoot(y)){
				Rotate(Get(x)^Get(y)?x:y);
			}
			Rotate(x);
		}
	}
	void Access(int x){
		for(int y=0;x;y=x,x=t[x].fa){
			Splay(x),rs=y,update(x);
		}
	}
	void makeroot(int x){
		Access(x),Splay(x),t[x].Rev();
	}
	void Link(int x,int y){
		makeroot(x);
		t[x].fa=y;
	}
	void Split(int x,int y){
		makeroot(x),Access(y),Splay(y);	
	}
	int findroot(int x){
		pushdown(x);
		while(ls)pushdown(x=ls);
		Splay(x);
		return x;
	}
	void Cut(int x,int y){
		Split(x,y);
		t[x].fa=t[y].ch[0]=0;
		update(y);
	}
}T;
int ans[N],id[N],tot,ok[N];
int tim,p[N];
struct Link{
	int x,y;
}L[N];
inline bool check(int u,int opt){
	int x=L[u].x,y=L[u].y;
	T.Split(x,y);
	int len=T.t[y].dis>>1;
	int z=T.t[y].mn;
	int con=(T.findroot(y)==x);
	if(con&&!(len&1))return false;
	if(z<inf&&con&&opt){
		T.Cut(id[z],L[z].x);
		T.Cut(id[z],L[z].y);
		ok[z]=0;
		con=0;
	}
	if(!con){
		if(!id[u])id[u]=++tot;
		T.t[id[u]].mn=T.t[id[u]].val=opt?inf:u;
		T.Link(id[u],x);
		T.Link(id[u],y);	
		ok[u]=1;
	}
	return true;
}
int main(){
	n=read(),m=read(),Q=read();
	for(int i=1;i<=m;++i){
		L[i].x=read();
		L[i].y=read();
	}
	tot=n;
	int now=m+1;
	while(now>1&&check(now-1,0))--now;
	ans[0]=now;
	for(int i=1;i<=m;++i){
		while(true){
			if(now<=i)goto qwq;
			if(check(i,1))break;
			if(now>m){
				now=m+2;
				break;
			}
			qwq:
			if(ok[now]){
				ok[now]=0;
				T.Cut(id[now],L[now].x);
				T.Cut(id[now],L[now].y);
			}
			++now;
		}
		ans[i]=now;
	}
	while(Q--){
		int l=read(),r=read();
		printf(ans[l-1]<=r+1?"NO\n":"YES\n");
	}
	return 0;
}