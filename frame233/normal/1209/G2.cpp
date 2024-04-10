#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;
int a[N],d[N],cnt[N],v[N],n,q;
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
int tag[N<<2],mn[N<<2],mx1[N<<2],mx2[N<<2],ans[N<<2],mx[N<<2];
inline void pushup(int u){
	int x=ls(u),y=rs(u);
	mn[u]=std::min(mn[x],mn[y]),mx[u]=std::max(mx[x],mx[y]);
	if(mn[x]==mn[y]){
		ans[u]=ans[x]+ans[y]+std::max(mx2[x],mx1[y]);
		mx1[u]=mx1[x],mx2[u]=mx2[y];
	}
	else if(mn[x]<mn[y]){
		ans[u]=ans[x];
		mx2[u]=std::max(mx2[x],mx[y]);
		mx1[u]=mx1[x];
	}
	else{
		ans[u]=ans[y];
		mx1[u]=std::max(mx1[y],mx[x]);
		mx2[u]=mx2[y];
	}
}
void build(int l,int r,int u){
	if(l==r){
		mn[u]=d[l],mx1[u]=v[l],mx2[u]=0,ans[u]=0,mx[u]=v[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,ls(u)),build(mid+1,r,rs(u));
	pushup(u);
}
inline void upd(int u,int C){mn[u]+=C,tag[u]+=C;}
inline void pushdown(int u){if(tag[u])upd(ls(u),tag[u]),upd(rs(u),tag[u]),tag[u]=0;}
void Update(int L,int R,int C,int l,int r,int u){
	if(L<=l&&r<=R)return upd(u,C);
	int mid=(l+r)>>1;pushdown(u);
	if(L<=mid)Update(L,R,C,l,mid,ls(u));
	if(R>mid)Update(L,R,C,mid+1,r,rs(u));
	pushup(u);
}
void Modify(int pos,int l,int r,int u){
	if(l==r){
		mx1[u]=v[l],mx2[u]=0,ans[u]=0,mx[u]=v[l];
		return;
	}
	int mid=(l+r)>>1;pushdown(u);
	pos<=mid?Modify(pos,l,mid,ls(u)):Modify(pos,mid+1,r,rs(u));
	pushup(u);
}
std::set<int> S[N];
void del(int x){
	int l=*S[a[x]].begin(),r=*S[a[x]].rbegin();
	v[r]=0,Modify(r,0,n,1);if(l<r)Update(l,r-1,-1,0,n,1);
	S[a[x]].erase(S[a[x]].find(x)),--cnt[a[x]];
	if(!S[a[x]].empty()){
		int l=*S[a[x]].begin(),r=*S[a[x]].rbegin();
		v[r]=cnt[a[x]],Modify(r,0,n,1);
		if(l<r)Update(l,r-1,1,0,n,1);
	}
}
void ins(int x){
	if(!S[a[x]].empty()){
		int l=*S[a[x]].begin(),r=*S[a[x]].rbegin();
		v[r]=0,Modify(r,0,n,1);if(l<r)Update(l,r-1,-1,0,n,1);
	}
	S[a[x]].insert(x),++cnt[a[x]];
	int l=*S[a[x]].begin(),r=*S[a[x]].rbegin();
	v[r]=cnt[a[x]],Modify(r,0,n,1);
	if(l<r)Update(l,r-1,1,0,n,1);
}
int main(){
	read(n,q);
	for(int i=1;i<=n;++i)read(a[i]),S[a[i]].insert(i),++cnt[a[i]];
	for(int i=1;i<=200000;++i)if(!S[i].empty()){
		int l=*S[i].begin(),r=*S[i].rbegin();
		++d[l],--d[r],v[r]=cnt[i];
	}
	for(int i=1;i<=n;++i)d[i]+=d[i-1];
	build(0,n,1);printf("%d\n",n-ans[1]);
	int x,y;
	while(q--){
		read(x,y);
		del(x),a[x]=y,ins(x);
		printf("%d\n",n-ans[1]);
	}
	return 0;
}