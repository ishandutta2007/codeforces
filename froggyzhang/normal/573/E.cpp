#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 300030
int n,a[N];
struct dc{
	ll s,k;
	dc(ll _s=0,ll _k=0):s(_s),k(_k){}
	friend dc operator + (const dc &a,const dc &b){
		return dc(a.s+b.s,a.k+b.k);
	}
};
mt19937 rnd(1145141);
struct node{
	int ch[2],siz;
	unsigned int key;
	dc add;
	ll val;
	node(){key=rnd();}
}t[N];
#define ls t[u].ch[0]
#define rs t[u].ch[1]
int cnt;
inline int NewNode(ll w){
	int u=++cnt;
	t[u].siz=1;
	t[u].val=w;
	return u;
}
int rt;
inline void Add(int u,dc d){
	t[u].val+=d.s+d.k*t[ls].siz;
	t[u].add=t[u].add+d;
}
inline void update(int u){
	t[u].siz=t[ls].siz+t[rs].siz+1;
}
inline void pushdown(int u){
	if(t[u].add.s||t[u].add.k){
		Add(ls,t[u].add);
		Add(rs,t[u].add+dc(t[u].add.k*(t[ls].siz+1),0));
		t[u].add.s=t[u].add.k=0;
	}
}
void Split(int u,int lim,int &l,int &r){
	if(!u){
		l=r=0;
		return;
	}
	pushdown(u);
	if(t[ls].siz+1<=lim){
		l=u;
		Split(rs,lim-t[ls].siz-1,rs,r);
	}
	else{
		r=u;
		Split(ls,lim,l,ls);
	}
	update(u);
}
int Merge(int l,int r){
	if(!l||!r)return l|r;
	pushdown(l),pushdown(r);
	if(t[l].key<t[r].key){
		t[l].ch[1]=Merge(t[l].ch[1],r);
		update(l);
		return l;
	}
	else{
		t[r].ch[0]=Merge(l,t[r].ch[0]);
		update(r);
		return r;
	}
}
/*ll get_val(int jb,int rk){ // TLE
	int L,R,o;
	Split(rt,rk+1,L,R);
	Split(L,rk,L,o);
	ll w=t[o].val;
	rt=Merge(L,Merge(o,R));
	return w;
}*/
ll get_val(int u,int pos){
	if(t[ls].siz==pos)return t[u].val;
	pushdown(u);
	return pos>t[ls].siz?get_val(rs,pos-t[ls].siz-1):get_val(ls,pos);
}
inline bool check(int i,int pos){
	return get_val(rt,pos+1)<get_val(rt,pos)+1LL*a[i]*(pos+1);
}
int find_pos(int tot){
	int l=0,r=tot-1,pos=tot-1;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(tot,mid))pos=mid,r=mid;
		else l=mid+1;
	}
	return pos;
}
ll ans;
void dfs(int u){
	if(!u)return;
	pushdown(u);
	dfs(ls),dfs(rs);
	ans=max(ans,t[u].val);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	rt=NewNode(0);
	for(int i=1;i<=n;++i){
		int pos=find_pos(i);
		ll tmp=get_val(rt,pos);
		int L,R;
		Split(rt,pos,L,R);
		if(R)Add(R,dc(1LL*(pos+1)*a[i],a[i]));
		rt=Merge(Merge(L,NewNode(tmp)),R);
	}
	dfs(rt);
	cout<<ans<<'\n';
	return 0;
}