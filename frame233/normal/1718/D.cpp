#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=300005,NC=(1<<20)+5;typedef std::pair<int,int> pi;
int a[N],b[N],c[N],f[N][20],Log2[N],t[N],pos,cnt[N];std::vector<pi> all;std::vector<int> Q[N];bool flag;
inline int _max(int x,int y){return a[x]>a[y]?x:y;}
inline int ask(int l,int r){int k=Log2[r-l+1];return _max(f[l][k],f[r-(1<<k)+1][k]);}
int solve(int l,int r,int val){
	if(l>r)return 0;
	int mid=ask(l,r);
	if(b[mid]){
		int tmp=std::min(val,b[mid]),x=solve(l,mid-1,tmp),y=solve(mid+1,r,tmp);
		if(b[mid]<std::max(x,y)||b[mid]>val)flag=1;
		return std::max({x,y,b[mid]});
	}
	else{
		int x=solve(l,mid-1,val),y=solve(mid+1,r,val);
		all.pb({std::max(x,y),val});return std::max(x,y);
	}
}
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
struct node{int val,pos;inline bool operator < (const node &o)const{return val==o.val?pos>o.pos:val<o.val;}};
node mn[NC];int tag[NC];
void build(int l,int r,int u){
	mn[u]={0,r},tag[u]=0;if(l==r)return;
	int mid=(l+r)>>1;build(l,mid,ls(u)),build(mid+1,r,rs(u));
}
inline void pushup(int u){mn[u]=std::min(mn[ls(u)],mn[rs(u)]);}
inline void upd(int u,int C){mn[u].val+=C,tag[u]+=C;}
inline void pushdown(int u){if(tag[u])upd(ls(u),tag[u]),upd(rs(u),tag[u]),tag[u]=0;}
void Update(int L,int R,int C,int l,int r,int u){
	if(L<=l&&r<=R)return upd(u,C);
	int mid=(l+r)>>1;pushdown(u);
	if(L<=mid)Update(L,R,C,l,mid,ls(u));
	if(R>mid)Update(L,R,C,mid+1,r,rs(u));
	pushup(u);
}
void MAIN(){
	int n,q;read(n,q),pos=0;
	for(int i=1;i<=n;++i)read(a[i]);
	int k=0;for(int i=1;i<=n;++i){read(b[i]);if(b[i])t[++pos]=b[i];else ++k;}
	for(int i=1;i<k;++i)read(c[i]),t[++pos]=c[i];
	t[++pos]=1e6,std::sort(t,t+pos+1),pos=std::unique(t,t+pos+1)-t-1;memset(cnt,0,(pos+3)<<2);
	for(int i=0;i<=pos+1;++i)Q[i].clear();
	for(int i=1;i<=n;++i)b[i]=std::lower_bound(t,t+pos+1,b[i])-t;
	for(int i=1;i<k;++i)++cnt[c[i]=std::lower_bound(t,t+pos+1,c[i])-t];
	for(int i=n;i>=1;--i){f[i][0]=i;for(int j=1;j<20&&i+(1<<j)-1<=n;++j)f[i][j]=_max(f[i][j-1],f[i+(1<<(j-1))][j-1]);}
	flag=0,all.clear(),solve(1,n,pos);
	for(const auto &it:all)Q[it.second].pb(it.first);
	build(0,pos,1);int l=0,r=pos;
	for(int i=0;i<=pos;++i){
		Update(0,i,cnt[i],0,pos,1);
		for(auto it:Q[i])Update(0,it,-1,0,pos,1);
		if(mn[1].val<-1)l=pos+1,r=0;
		else if(mn[1].val==-1)r=std::min(r,i),l=std::max(l,mn[1].pos);
	}
	if(flag)l=pos+1,r=0;
	int x;while(q--)read(x),puts(t[l]<=x&&x<=t[r]?"YES":"NO");
}
int main(){
	for(int i=2;i<N;++i)Log2[i]=Log2[i>>1]+1;
	int _;read(_);
	while(_--)MAIN();
	return 0;
}