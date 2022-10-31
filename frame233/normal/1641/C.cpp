#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-(x)))
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
const int N=200005,inf=0x3f3f3f3f;
struct BIT{
	int c[N];void add(int x,int C){for(;x<N;x+=lowbit(x))c[x]+=C;}
	int ask(int x){int ans=0;for(;x;x-=lowbit(x))ans+=c[x];return ans;}
}TR;int n,a[N];
struct seg{int l,r;inline bool operator < (const seg &o)const{return l<o.l;}};
struct node{int v,l,r;inline bool operator < (const node &o)const{return v<o.v;}}f[N<<2];
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
int tag[N<<2];
void build(int l,int r,int u){
	f[u]={inf,0,0};if(l==r)return;
	int mid=(l+r)>>1;build(l,mid,ls(u)),build(mid+1,r,rs(u));
}
inline void upd(int u,int C){f[u].v+=C,tag[u]+=C;}
inline void pushdown(int u){if(tag[u])upd(ls(u),tag[u]),upd(rs(u),tag[u]),tag[u]=0;}
void Modify(int pos,const node &o,int l,int r,int u){
	if(l==r){f[u]=o;return;}
	int mid=(l+r)>>1;pushdown(u);
	pos<=mid?Modify(pos,o,l,mid,ls(u)):Modify(pos,o,mid+1,r,rs(u));
	f[u]=std::min(f[ls(u)],f[rs(u)]);
}
void Update(int L,int R,int C,int l,int r,int u){
	if(L<=l&&r<=R)return upd(u,C);
	int mid=(l+r)>>1;pushdown(u);
	if(L<=mid)Update(L,R,C,l,mid,ls(u));
	if(R>mid)Update(L,R,C,mid+1,r,rs(u));
	f[u]=std::min(f[ls(u)],f[rs(u)]);
}
std::set<int> rest,ALL;std::set<seg> S;
void mark(int x){
	a[x]=1,rest.erase(x),ALL.insert(x);
	auto it=S.upper_bound({x,x});
	if(it==S.begin())return;
	--it;
	while(true){
		if(it->r>=x)Modify(it->r,{inf,0,0},1,n,1);
		else break;
		if(it==S.begin()){S.erase(it);return;}
		S.erase(it--);
	}
}
void fix(){
	while(f[1].v<=1){
		if(f[1].v==1)mark(*rest.lower_bound(f[1].l));
		else S.erase({f[1].l,f[1].r}),Modify(f[1].r,{inf,0,0},1,n,1);
	}
}
void del(int x){
	TR.add(x,-1),a[x]=2,rest.erase(x);
	auto it=S.upper_bound({x,x});int lim=n;
	if(it!=S.begin())lim=(--it)->r;else return;
	if(x<=lim)Update(x,lim,-1,1,n,1);
	fix();
}
int main(){
	int q;read(n,q);
	for(int i=1;i<=n;++i)rest.insert(i),TR.add(i,1);
	int opt,l,r,x;build(1,n,1);
	while(q--){
		read(opt);
		if(opt==0){
			read(l,r,x);
			if(x==1){
				if(l==r){
					if(a[l]==0)mark(l);
				}
				else{
					auto IT=ALL.lower_bound(l);
					if(IT!=ALL.end()&&*IT<=r)continue;
					auto it=S.lower_bound({l,0});
					if(it!=S.end()&&it->r<=r)continue;
					while(true){
						it=S.upper_bound({l,0});
						if(it!=S.begin()&&(--it)->r>=r)Modify(it->r,{inf,0,0},1,n,1),S.erase(it);
						else break;
					}
					S.insert({l,r}),Modify(r,{TR.ask(r)-TR.ask(l-1),l,r},1,n,1),fix();
				}
			}
			else{
				while(true){
					auto it=rest.lower_bound(l);
					if(it!=rest.end()&&*it<=r)del(*it);
					else break;
				}
			}
		}
		else{
			read(x);
			if(a[x]==2)puts("NO");
			else if(a[x]==1)puts("YES");
			else puts("N/A");
		}
	}
	return 0;
}