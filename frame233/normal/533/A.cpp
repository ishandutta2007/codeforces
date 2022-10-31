#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=500005,NC=(1<<20)+5,inf=0x3f3f3f3f;
int a[N],h[N],s[N],n,k,mn1[N],mn2[N];std::vector<int> e[N],vec[N];
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
int mn[NC],tag[NC];
void build(int l,int r,int u){
	if(l==r)return mn[u]=-(k-l+1),void();
	int mid=(l+r)>>1;build(l,mid,ls(u)),build(mid+1,r,rs(u));
	mn[u]=std::min(mn[ls(u)],mn[rs(u)]);
}
inline void upd(int u,int C){mn[u]+=C,tag[u]+=C;}
inline void pushdown(int u){if(tag[u])upd(ls(u),tag[u]),upd(rs(u),tag[u]),tag[u]=0;}
void Update(int L,int R,int C,int l,int r,int u){
	if(L>R)return;
	if(L<=l&&r<=R)return upd(u,C);
	int mid=(l+r)>>1;pushdown(u);
	if(L<=mid)Update(L,R,C,l,mid,ls(u));
	if(R>mid)Update(L,R,C,mid+1,r,rs(u));
	mn[u]=std::min(mn[ls(u)],mn[rs(u)]);
}
inline int get(int x){return std::upper_bound(s+1,s+k+1,x)-s-1;}
void dfs1(int x,int fa){
	mn1[x]=mn1[fa],mn2[x]=mn2[fa];
	if(h[x]<h[mn1[x]])mn2[x]=mn1[x],mn1[x]=x;
	else if(h[x]<h[mn2[x]])mn2[x]=x;
	vec[mn1[x]].pb(get(h[mn2[x]]));
	for(auto v:e[x])if(v!=fa)dfs1(v,x);
}
int main(){
	read(n);for(int i=1;i<=n;++i)read(h[i]);
	for(int i=1,x,y;i<n;++i)read(x,y),e[x].pb(y),e[y].pb(x);
	read(k);for(int i=1;i<=k;++i)read(s[i]);
	h[0]=inf,std::sort(s+1,s+k+1),dfs1(1,0),build(1,k,1);
	for(int i=1;i<=n;++i)Update(1,get(h[mn1[i]]),1,1,k,1),a[i]=h[mn1[i]];
	std::sort(a+1,a+n+1);int v=-1;
	for(int i=k,j=n;i>=1;--i,--j)if(a[j]<s[i]){v=i;break;}
	if(v==-1)return puts("0"),0;
	int ans=2e9;
	for(int i=1;i<=n;++i)if(!vec[i].empty()){
		int r=get(h[i]);Update(1,r,-SZ(vec[i]),1,k,1);
		for(auto it:vec[i])Update(1,std::min(it,v),1,1,k,1);
		if(mn[1]>=0)ans=std::min(ans,s[v]-h[i]);
		for(auto it:vec[i])Update(1,std::min(it,v),-1,1,k,1);
		Update(1,r,SZ(vec[i]),1,k,1);
	}
	printf("%d\n",ans>=2e9?-1:ans);
	return 0;
}