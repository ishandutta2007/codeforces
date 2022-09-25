#include<bits/stdc++.h>
using namespace std;
#define N 800010
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
int n,m,Q;
class LCT{
public:
	struct node{
		int ch[2],fa,sxor,val;
		bool rev,e,ban,c,cov;
		void Cover(int x){
			c=(x>n);
			cov=true;
			ban=e;
		}
		inline void Rev(){
			rev^=1;
			swap(ch[0],ch[1]);
		} 
	}t[N];
	#define ls t[x].ch[0]
	#define rs t[x].ch[1]
	inline void pushdown(int x){
		if(t[x].rev){
			t[ls].Rev();
			t[rs].Rev();
			t[x].rev=0;
		}
		if(t[x].cov){
			t[ls].Cover(ls);
			t[rs].Cover(rs);
			t[x].cov=false;
		}
	}
	inline void update(int x){
		t[x].sxor=t[ls].sxor^t[rs].sxor^t[x].val;
		t[x].e=t[ls].e|t[rs].e|(x>n);
		t[x].ban=t[ls].ban|t[rs].ban|t[x].c;
	}
	inline void Connect(int x,int fa,int p){t[x].fa=fa,t[fa].ch[p]=x;}
	inline int Get(int x){return t[t[x].fa].ch[1]==x;}
	inline bool IsRoot(int x){return t[t[x].fa].ch[0]^x&&t[t[x].fa].ch[1]^x;}
	inline void Rotate(int x){
		int fa=t[x].fa,gfa=t[fa].fa;
		int d1=Get(x),d2=Get(fa);
		if(!IsRoot(fa))Connect(x,gfa,d2);
		else t[x].fa=gfa;
		Connect(t[x].ch[d1^1],fa,d1);
		Connect(fa,x,d1^1);
		update(fa),update(x);
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
	void Access(int x){
		for(int y=0;x;y=x,x=t[x].fa){
			Splay(x),rs=y,update(x);
		}	
	}
	int findroot(int x){
		Access(x),Splay(x);
		while(ls)pushdown(x=ls);
		Splay(x);
		return x;	
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
	bool check(int x,int y){
		makeroot(x);
		return findroot(y)==x;
	}
}T;
int main(){
	n=read(),Q=read();
	int m=n;
	while(Q--){
		int u=read(),v=read(),x=read();
		if(!T.check(u,v)){
			++m;
			T.t[m].val=T.t[m].sxor=x;
			T.t[m].e=1;
			T.Link(u,m),T.Link(v,m);
			printf("YES\n");
		}
		else{
			T.Split(v,u);
			if(T.t[u].ban||T.t[u].sxor==x){
				printf("NO\n");
			}
			else{
				printf("YES\n");
				T.t[u].Cover(u);
			}
		}
	}
	return 0;
}