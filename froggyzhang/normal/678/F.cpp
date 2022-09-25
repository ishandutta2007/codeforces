#include<bits/stdc++.h>
using namespace std;
#define N 300030
typedef long long ll;
const int inf=0x3f3f3f3f;
const int B=1e9;
const ll infll=0x3f3f3f3f3f3f3f3fll;
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
int m;
struct Line{
	int k,b;
	Line(int _k=-inf,int _b=-inf){k=_k,b=_b;}
	inline ll Val(int x){
		return 1LL*k*x+b;
	}
};
class LiChao_Tree{
public:
	int cnt,rt;
	struct node{
		Line p;
		int ch[2];
	}tree[N<<1];
	#define ls tree[u].ch[0]
	#define rs tree[u].ch[1]
	vector<pair<int,Line> > st;
	void Insert(int &u,int L,int R,Line t){
		if(!u||tree[u].p.k==-inf){
			if(!u)u=++cnt;
			st.emplace_back(u,tree[u].p);
			tree[u].p=t;
			return;
		}
		if(L==R){
			if(tree[u].p.Val(L)>t.Val(L)){
				st.emplace_back(u,tree[u].p);
				tree[u].p=t;
			}
			return;
		}
		int mid=(L+R)>>1;
		if(t.k>tree[u].p.k){
			if(t.Val(mid)>tree[u].p.Val(mid)){
				Insert(ls,L,mid,tree[u].p);
				st.emplace_back(u,tree[u].p);
				tree[u].p=t;
			}
			else{
				Insert(rs,mid+1,R,t);	
			}
		}
		else{
			if(t.Val(mid)>tree[u].p.Val(mid)){
				Insert(rs,mid+1,R,tree[u].p);
				st.emplace_back(u,tree[u].p);
				tree[u].p=t;
			}
			else{
				Insert(ls,L,mid,t);	
			}	
		}
	}
	ll Query(int u,int L,int R,int x){
		if(!u||tree[u].p.k==-inf)return -infll;
		int mid=(L+R)>>1;
		ll mx=tree[u].p.Val(x);
		mx=max(mx,x<=mid?Query(ls,L,mid,x):Query(rs,mid+1,R,x));
		return mx;
	}
	#undef ls
	#undef rs
}T;
class Seg_FZ{
public:
	vector<Line> OP[N<<2];
	vector<int> q[N];
	Line S[N];
	#define ls u<<1
	#define rs u<<1|1
	void Add(int u,int L,int R,int l,int r,Line &t){
		if(L>=l&&R<=r){
			OP[u].push_back(t);
			return;
		}
		int mid=(L+R)>>1;
		if(l<=mid)Add(ls,L,mid,l,r,t);
		if(r>mid)Add(rs,mid+1,R,l,r,t);
	}
	void Solve(int u,int L,int R){
		int SZ=T.st.size();
		for(auto t:OP[u]){
			T.Insert(T.rt,-B,B,t);	
		}
		if(L==R){
			for(auto x:q[L]){
				ll ans=T.Query(T.rt,-B,B,x);
				if(ans==-infll){
					printf("EMPTY SET\n");	
				}
				else{
					printf("%lld\n",ans);
				}
			}
			return;
		}
		int mid=(L+R)>>1;
		Solve(ls,L,mid),Solve(rs,mid+1,R);
		while((int)T.st.size()>SZ){
			int u=T.st.back().first;
			T.tree[u].p=T.st.back().second;
			T.st.pop_back();
		}
	}
	void init(){
		m=read();
		for(int i=1;i<=m;++i){
			int opt=read();
			if(opt==1){
				int x=read(),y=read();
				S[i]=Line(x,y);
			}
			else if(opt==2){
				int id=read();
				Add(1,1,m,id,i-1,S[id]);
				S[id]=Line(-inf,-inf);
			}
			else{
				int x=read();
				q[i].push_back(x);
			}
		}
		for(int i=1;i<=m;++i){
			if(S[i].k^(-inf))Add(1,1,m,i,m,S[i]);
		}	
	}
	#undef ls 
	#undef rs
}Q;
int main(){
	Q.init();
	Q.Solve(1,1,m);
	return 0;
}