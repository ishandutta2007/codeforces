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
map<pair<int,int>,int> mp;
int n,m;
struct Op{
	int opt,x,y;
}q[N];
struct Union_Set{
	int f[N],dep[N],top;
	Op st[N];
	inline int getf(int x){
		return f[x]==x?x:getf(f[x]);
	}
	void init(int n){
		for(int i=1;i<=n;++i)f[i]=i;
	}
	void Merge(int x,int y){
		int fx=getf(x),fy=getf(y);
		if(fx==fy)return;
		if(dep[fx]<dep[fy])swap(fx,fy);
		f[fy]=fx;
		st[++top]={dep[fx]==dep[fy],fx,fy};
		dep[fx]+=dep[fx]==dep[fy];
	}
	void undo(int k){
		while(top>k){
			int t=st[top].opt,x=st[top].x,y=st[top].y;
			--top;
			dep[x]-=t,f[y]=y;
		}
	}
	inline bool Query(int x,int y){ 
		return getf(x)==getf(y);
	}
}S;
vector<Op> vec[N<<2];
#define ls u<<1
#define rs u<<1|1
void Change(int u,int L,int R,int l,int r,Op t){
	if(L>=l&&R<=r){
		vec[u].push_back(t);
		return;
	}
	int mid=(L+R)>>1;
	if(l<=mid)Change(ls,L,mid,l,r,t);
	if(r>mid)Change(rs,mid+1,R,l,r,t);
}
int lastans;
void Solve(int u,int L,int R){
	int las=S.top;
	for(auto t:vec[u]){
		if(mp[make_pair(t.x,t.y)]){
			S.Merge(t.x,t.y);
		}
	}
	if(L==R){
		if(q[L].opt==2){
			putchar('0'+(lastans=S.Query(q[L].x,q[L].y)));
		}
		if(lastans){
			++(q[L+1].x%=n),++(q[L+1].y%=n);
			if(q[L+1].x>q[L+1].y)swap(q[L+1].x,q[L+1].y);
		}
		if(q[L+1].opt==1)mp[make_pair(q[L+1].x,q[L+1].y)]^=1;
	}
	else{
		int mid=(L+R)>>1;
		Solve(ls,L,mid);
		Solve(rs,mid+1,R);
	} 
	S.undo(las);
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		q[i].opt=read(),q[i].x=read(),q[i].y=read();
			if(q[i].opt==1){
			if(q[i].x>q[i].y)swap(q[i].x,q[i].y);
			auto pr=make_pair(q[i].x,q[i].y);
			if(mp.count(pr))Change(1,1,m,mp[pr],i,q[i]);
			mp[pr]=i;
			
			pr=make_pair(q[i].x%n+1,q[i].y%n+1);
			if(pr.first>pr.second)swap(pr.first,pr.second);
			if(mp.count(pr))Change(1,1,m,mp[pr],i,(Op){1,pr.first,pr.second});
			mp[pr]=i;
		}
	}
	for(auto [t,ed]:mp){
		Change(1,1,m,ed,m,(Op){1,t.first,t.second});
	}
	mp.clear();
	S.init(n);
	if(q[1].opt==1){
		mp[make_pair(q[1].x,q[1].y)]=1;
	}
	Solve(1,1,m);
	return 0;
}