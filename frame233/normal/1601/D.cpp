#include<bits/stdc++.h>
#define pb emplace_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=500005;
struct node{int s,a;inline bool operator < (const node &o)const{return a==o.a?s<o.s:a<o.a;}}a[N];
int dp[N],n,d;
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
int v[N<<2],tag[N<<2];
inline void upd(int u,int C){v[u]+=C,tag[u]+=C;}
inline void pushdown(int u){if(tag[u])upd(ls(u),tag[u]),upd(rs(u),tag[u]),tag[u]=0;}
void Update(int L,int R,int C,int l,int r,int u){
	if(L<=l&&r<=R)return upd(u,C);
	int mid=(l+r)>>1;pushdown(u);
	if(L<=mid)Update(L,R,C,l,mid,ls(u));
	if(R>mid)Update(L,R,C,mid+1,r,rs(u));
	v[u]=std::max(v[ls(u)],v[rs(u)]);
}
void Modify(int pos,int C,int l,int r,int u){
	if(l==r)return v[u]=C,void();
	int mid=(l+r)>>1;pushdown(u);
	pos<=mid?Modify(pos,C,l,mid,ls(u)):Modify(pos,C,mid+1,r,rs(u));
	v[u]=std::max(v[ls(u)],v[rs(u)]);
}
int ask(int L,int R,int l,int r,int u){
	if(L<=l&&r<=R)return v[u];
	int mid=(l+r)>>1;pushdown(u);
	if(L<=mid&&R>mid)return std::max(ask(L,R,l,mid,ls(u)),ask(L,R,mid+1,r,rs(u)));
	return L<=mid?ask(L,R,l,mid,ls(u)):ask(L,R,mid+1,r,rs(u));
}
struct comp{inline bool operator () (int x,int y)const{return a[x].s==a[y].s?x<y:a[x].s<a[y].s;}};
std::set<int,comp> S;
int main(){
	read(n,d);
	for(int i=1;i<=n;++i){
		read(a[i].s,a[i].a);
		if(a[i].s<d)--i,--n;
		if(a[i].a<d)a[i].a=d;
	}
	std::sort(a+1,a+n+1);a[0].a=d;
	for(int i=1;i<=n;++i){
		while(!S.empty()){
			int x=*S.begin();
			if(a[x].s<a[i].a)Update(0,x-1,-1,0,n,1),S.erase(S.begin());
			else break;
		}
		int l=0,r=i-1,mid;while(l<r)mid=(l+r+1)>>1,a[mid].a<=a[i].s?l=mid:r=mid-1;
		dp[i]=ask(0,l,0,n,1)+1,Modify(i,dp[i],0,n,1);
		if(a[i].s>=a[i].a)S.insert(i),Update(0,i-1,1,0,n,1);
	}
	int ans=0;for(int i=0;i<=n;++i)ans=std::max(ans,dp[i]);
	printf("%d\n",ans);
	return 0;
}