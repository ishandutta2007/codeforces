#include<bits/stdc++.h>
using namespace std;
#define N 500050
typedef long long ll;
const int inf=0x3f3f3f3f;
typedef pair<int,int> pii;
int n,m;
class Link_Cut_Tree{
public:
	struct node{
		int ch[2],fa,rev,siz;
		int cov,val,mx;
		inline void Rev(){swap(ch[0],ch[1]);rev^=1;}
		inline void Cover(int d){
			val=cov=mx=d;
		}
	}t[N<<1];
	#define ls t[x].ch[0]
	#define rs t[x].ch[1]
	inline int Get(int x){return t[t[x].fa].ch[1]==x;}
	inline bool IsRoot(int x){return t[t[x].fa].ch[0]^x&&t[t[x].fa].ch[1]^x;}
	inline void Connect(int x,int fa,int p){t[x].fa=fa,t[fa].ch[p]=x;}
	inline void update(int x){
		t[x].siz=t[ls].siz+t[rs].siz+1;
		t[x].mx=t[ls].mx|t[rs].mx|(x>n?t[x].val:0);
	}
	inline void pushdown(int x){
		if(t[x].rev)t[ls].Rev(),t[rs].Rev(),t[x].rev=0;
		if(~t[x].cov){
			if(ls)t[ls].Cover(t[x].cov);
			if(rs)t[rs].Cover(t[x].cov);
			t[x].cov=-1;
		}
	}
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
		while(ls)pushdown(x=ls);
		Splay(x);
		return x;
	}
	inline bool check(int x,int y){
		return findroot(x)^findroot(y);	
	}
	inline void makeroot(int x){
		Access(x),Splay(x),t[x].Rev();
	}
	void Split(int x,int y){
		makeroot(x),Access(y),Splay(y);	
	}
	void Link(int x,int y){
		makeroot(x),t[x].fa=y;	
	}
	void Cut(int x,int y){
		Split(x,y);
		if(t[y].siz==2&&t[y].ch[0]==x&&t[x].fa==y){
			t[x].fa=t[y].ch[0]=0;update(y);	
		}
	}
	void Cover(int x,int y,int w){
		Split(x,y);
		t[y].Cover(w);	
	}
	#undef ls
	#undef rs
}T;
pii E[N];
int del[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		cin>>E[i].first>>E[i].second;	
	}
	for(int i=1;i<=n+m;++i){
		T.t[i].siz=1;T.t[i].cov=-1;
	}
	ll ans=0;
	for(int i=1,j=1;i<=m;++i){
		int u=E[i].first,v=E[i].second;
		while(!T.check(u,v)){
			T.Split(u,v);
			if(!T.t[v].mx)break;
			int x=E[j].first,y=E[j].second;
			T.Splay(j+n);
			int k=T.t[j+n].val;
			if(k){
				T.Cover(E[k].first,E[k].second,0);
				T.Cut(x,j+n);
				T.Link(E[k].first,k+n);
				T.Link(E[k].second,k+n);
			}
			else{
				T.Cut(x,j+n);	
			}
			++j;
		}
		if(T.check(u,v)){
			T.Link(i+n,u);
			T.Link(i+n,v);	
		}
		else{
			T.Cover(u,v,i);
		}
		ans+=i-j+1;
	}
	cout<<ans<<'\n';
	return 0;
}