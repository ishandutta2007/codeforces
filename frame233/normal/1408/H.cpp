#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=500005;
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
int mn[N<<2],tag[N<<2],m;
inline void upd(int u,int C){mn[u]+=C,tag[u]+=C;}
inline void pushdown(int u){if(tag[u])upd(ls(u),tag[u]),upd(rs(u),tag[u]),tag[u]=0;}
void build(int l,int r,int u){
	tag[u]=0;if(l==r)return mn[u]=l+m-1,void();
	int mid=(l+r)>>1;
	build(l,mid,ls(u)),build(mid+1,r,rs(u));
	mn[u]=std::min(mn[ls(u)],mn[rs(u)]);
}
void Update(int L,int R,int C,int l,int r,int u){
	if(L<=l&&r<=R)return upd(u,C);
	int mid=(l+r)>>1;pushdown(u);
	if(L<=mid)Update(L,R,C,l,mid,ls(u));
	if(R>mid)Update(L,R,C,mid+1,r,rs(u));
	mn[u]=std::min(mn[ls(u)],mn[rs(u)]);
}
int a[N],n,id[N],last[N],tmp[N];
bool check(int mid){
	m=mid,build(1,m,1);
	memset(id,0,(n+3)<<2);
	for(int i=1,c=0;i<=n;++i){
		if(c<m&&!a[i])id[i]=++c;
		last[i]=c;
	}
	for(int i=n,c=m*2;i>=1&&c>m;--i)if(!a[i])id[i]=c--;
	memset(tmp,0,(n+3)<<2);
	for(int i=1;i<=n;++i){
		if(a[i]){
			if(tmp[a[i]])Update(1,tmp[a[i]],-1,1,m,1);
			if(last[i])Update(1,last[i],1,1,m,1),tmp[a[i]]=last[i];
		}
		if(id[i]>m&&mn[1]<id[i])return false;
	}
	return true;
}
void MAIN(){
	read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	int cnt=std::count(a+1,a+n+1,0);
	int l=0,r=cnt/2,mid;
	while(l<r)mid=(l+r+1)>>1,check(mid)?l=mid:r=mid-1;
	printf("%d\n",l);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}