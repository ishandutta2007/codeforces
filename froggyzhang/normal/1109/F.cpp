#include<bits/stdc++.h>
using namespace std;
#define M 2020
#define N 200020
typedef long long ll;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
int n,m,a[M][M];
pii p[N];
ll ans;
const int d[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
inline bool In(int x,int y){
	return x>=1&&x<=n&&y>=1&&y<=m;
} 
class Link_Cut_Tree{
	struct node{
		int ch[2],fa,rev,siz;
		inline void Rev(){swap(ch[0],ch[1]);rev^=1;}
	}t[N<<1];
	#define ls t[x].ch[0]
	#define rs t[x].ch[1]
	inline int Get(int x){return t[t[x].fa].ch[1]==x;}
	inline bool IsRoot(int x){return t[t[x].fa].ch[0]^x&&t[t[x].fa].ch[1]^x;}
	inline void Connect(int x,int fa,int p){t[x].fa=fa,t[fa].ch[p]=x;}
	inline void update(int x){t[x].siz=t[ls].siz+t[rs].siz+1;}
	inline void pushdown(int x){
		if(t[x].rev)t[ls].Rev(),t[rs].Rev(),t[x].rev=0;
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
public:
	void init(int n){
		for(int i=1;i<=n;++i){
			t[i].siz=1;
		}
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
	#undef ls
	#undef rs
}T;
struct Data{
	int mn,cnt;
	Data(){mn=inf,cnt=0;}
	friend Data operator + (const Data &a,const Data &b){
		Data c;
		c.mn=min(a.mn,b.mn);
		c.cnt=a.cnt*(a.mn==c.mn)+b.cnt*(b.mn==c.mn);
		return c;
	}	
};
class Segment_Tree{
	struct node{
		Data p;
		int add;
		inline void Add(int d){
			p.mn+=d;
			add+=d;	
		}
	}t[N<<2];
	#define ls u<<1
	#define rs u<<1|1
	inline void update(int u){
		t[u].p=t[ls].p+t[rs].p;	
	}
	inline void pushdown(int u){
		if(t[u].add){
			t[ls].Add(t[u].add);
			t[rs].Add(t[u].add);
			t[u].add=0;
		}
	}
public:
	void build(int u,int L,int R){
		if(L==R){
			t[u].p.mn=0;t[u].p.cnt=1;
			return;
		}
		int mid=(L+R)>>1;
		build(ls,L,mid);
		build(rs,mid+1,R);
		update(u);
	}
	inline void Plus(int u,int L,int R,int l,int r,int d){
		if(L>=l&&R<=r){
			t[u].Add(d);
			return;	
		}	
		pushdown(u);
		int mid=(L+R)>>1;
		if(l<=mid)Plus(ls,L,mid,l,r,d);
		if(r>mid)Plus(rs,mid+1,R,l,r,d);
		update(u);
	}
	Data Query(int u,int L,int R,int l,int r){
		if(L>=l&&R<=r)return t[u].p;
		pushdown(u);
		int mid=(L+R)>>1;
		Data ans;
		if(l<=mid)ans=ans+Query(ls,L,mid,l,r);
		if(r>mid)ans=ans+Query(rs,mid+1,R,l,r);
		return ans;
	}
}S;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin>>a[i][j];
			p[a[i][j]]=make_pair(i,j);
		}
	}
	T.init(n*m);
	S.build(1,1,n*m);
	for(int i=1,j=1;i<=n*m;++i){
		auto [x,y]=p[i];
		S.Plus(1,1,n*m,1,i,1);
		auto Del=[&](int u)->void{
			auto [x,y]=p[u];
			for(int k=0;k<4;++k){
				int nx=x+d[k][0],ny=y+d[k][1];
				if(In(nx,ny))T.Cut(u,a[nx][ny]);
			}
		};
		for(int k=0;k<4;++k){
			int nx=x+d[k][0],ny=y+d[k][1];
			if(In(nx,ny)&&a[nx][ny]<i){
				int v=a[nx][ny];
				S.Plus(1,1,n*m,1,v,-1);
				while(v>=j&&!T.check(i,v)){
					Del(j++);	
				}
				if(v>=j)T.Link(i,v);
			}
		}
		auto [mn,cnt]=S.Query(1,1,n*m,j,i);
		if(mn==1)ans+=cnt;
	}
	cout<<ans<<'\n';
	return 0;
}