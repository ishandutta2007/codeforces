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
struct LCT{
	struct node{
		int ch[2],fa,sum,val;
		bool rev;
		inline void Rev(){
			rev^=1;swap(ch[0],ch[1]);
		}
	}t[N<<2];
	#define ls t[x].ch[0]
	#define rs t[x].ch[1]
	inline void update(int x){
		t[x].sum=t[ls].sum^t[rs].sum^t[x].val;
	}
	inline void pushdown(int x){
		if(t[x].rev){
			t[ls].Rev();
			t[rs].Rev();
			t[x].rev=0;
		}
	}
	inline int  Get(int x){return t[t[x].fa].ch[1]==x;}
	inline bool IsRoot(int x){return t[t[x].fa].ch[0]^x&&t[t[x].fa].ch[1]^x;}
	inline void Connect(int x,int fa,int p){t[x].fa=fa,t[fa].ch[p]=x;}
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
		st[top=1]=y;
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
	inline void Access(int x){
		for(int y=0;x;y=x,x=t[x].fa){
			Splay(x),rs=y,update(x);
		}
	}
	inline int findroot(int x){
		Access(x),Splay(x);
		pushdown(x);
		while(ls)pushdown(x=ls);
		Splay(x);
		return x;
	}
	bool check(int x,int y){
		return findroot(x)==findroot(y);
	}
	void makeroot(int x){
		Access(x),Splay(x),t[x].Rev();
	}
	void Link(int x,int y){
		makeroot(x),t[x].fa=y;
	}
	void Split(int x,int y){
		makeroot(x),Access(y),Splay(y);
	}
}T;
int Q,lastans,tot;
map<int,int> mp;
int main(){
	Q=read();
	while(Q--){
		int opt=read(),l=read()^lastans,r=read()^lastans;
		if(l>r)swap(l,r);
		--l;
		if(!mp.count(l))mp[l]=++tot;
		if(!mp.count(r))mp[r]=++tot;
		int x=mp[l],y=mp[r];
		if(opt==1){
			int w=read()^lastans;
			if(T.check(x,y))continue;
			++tot;
			T.t[tot].val=T.t[tot].sum=w;
			T.Link(tot,x);
			T.Link(tot,y);
		}
		else{
			if(T.check(x,y)){
				T.Split(x,y);
				printf("%d\n",lastans=T.t[y].sum);		
			}
			else{
				printf("-1\n");
				lastans=1;
			}
		}
	}
	return 0;
}