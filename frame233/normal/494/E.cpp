#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005,NC=(1<<18)+5;typedef long long ll;
struct rect{int x1,x2,y1,y2;}a[N];
int ty[N],py;ll f[35];
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
int tag[NC],cnt[NC];bool leaf[NC];
inline void pushup(int u,int l,int r){
	if(tag[u])cnt[u]=ty[r]-ty[l-1];
	else if(!leaf[u])cnt[u]=cnt[ls(u)]+cnt[rs(u)];
	else cnt[u]=0;
}
void build(int l,int r,int u){
	tag[u]=cnt[u]=0;if(l==r)return leaf[u]=1,void();
	int mid=(l+r)>>1;build(l,mid,ls(u)),build(mid+1,r,rs(u));
}
void Update(int L,int R,int C,int l,int r,int u){
	if(L<=l&&r<=R)return tag[u]+=C,pushup(u,l,r);
	int mid=(l+r)>>1;
	if(L<=mid)Update(L,R,C,l,mid,ls(u));
	if(R>mid)Update(L,R,C,mid+1,r,rs(u));
	pushup(u,l,r);
}
struct qry{int x,y1,y2,c;inline bool operator < (const qry &o)const{return x<o.x;}}q[N];
ll solve(const std::vector<rect> &v){
	if(v.empty())return 0;
	int pos=0;py=0;for(const auto &it:v)ty[++py]=it.y1-1,ty[++py]=it.y2;
	std::sort(ty+1,ty+py+1),py=std::unique(ty+1,ty+py+1)-ty-1;
	for(const auto &it:v){
		int l=std::lower_bound(ty+1,ty+py+1,it.y1-1)-ty+1,r=std::lower_bound(ty+1,ty+py+1,it.y2)-ty;
		q[++pos]={it.x1,l,r,1},q[++pos]={it.x2+1,l,r,-1};
	}
	std::sort(q+1,q+pos+1),build(1,py,1);ll ans=0;
	for(int i=1;i<=pos;++i){
		Update(q[i].y1,q[i].y2,q[i].c,1,py,1);
		ans+=1LL*cnt[1]*(q[i+1].x-q[i].x);
	}
	return ans;
}
int main(){
	int n,m,k;read(n,m,k);for(int i=0;i<30;++i)if((k>>i&1)&&k!=(1<<i))k^=1<<i;
	for(int i=1;i<=m;++i)read(a[i].x1,a[i].y1,a[i].x2,a[i].y2);
	for(int c=0;(1<<c)<=k;++c){
		std::vector<rect> vec;
		for(int i=1;i<=m;++i){
			rect o;o.x1=((a[i].x1-1)>>c)+1,o.x2=a[i].x2>>c,o.y1=((a[i].y1-1)>>c)+1,o.y2=a[i].y2>>c;
			if(o.x1<=o.x2&&o.y1<=o.y2)vec.pb(o);
		}
		f[c]=solve(vec);
	}
	for(int c=0;(1<<c)<=k;++c)if((f[c]-f[c+1])%2)return puts("Hamed"),0;
	puts("Malek");
	return 0;
}