#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
#define int long long
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 200005
#define inf 0x3f3f3f3f3f3f3f3f
#define N (maxn<<2)
int n,m,k;
int id[maxn],pid[maxn];
int v[maxn],w[maxn],a[maxn];
int val[N][19],wei[N][19],ex[N][19];//   
inline bool cmp(int x,int y){return v[x]>v[y]||(v[x]==v[y]&&w[x]<w[y]);}

inline void pushup(int p){
	int ls=p<<1,rs=p<<1|1;
	For(i,1,18){
		val[p][i]=val[ls][i]+val[rs][i]; 
		wei[p][i]=wei[ls][i]+wei[rs][i];
		ex[p][i]=min(ex[ls][i],ex[rs][i]+wei[ls][i]);
	}
}
inline void get(int p,int x){
	For(i,1,18)
	{
		val[p][i]=wei[p][i]=0;
		ex[p][i]=inf;
		if(w[x]<(1<<(i-1))) val[p][i]=a[x]*v[x],wei[p][i]=a[x]*w[x];
		else if(w[x]<(1<<i)&&a[x]) ex[p][i]=w[x];
	}
}
void build(int p,int l,int r){
	if(l==r)return get(p,id[l]),void();
	int mid=l+r>>1; build(p<<1,l,mid),build(p<<1|1,mid+1,r),pushup(p);
}
void mdf(int p,int l,int r,int x){
	if(l==r)return get(p,id[l]),void();
	int mid=l+r>>1; x<=mid?mdf(p<<1,l,mid,x):mdf(p<<1|1,mid+1,r,x); pushup(p); 
}

int up=18,c;
inline void getw(){
	while(up>1 && (1<<(up-2))-1>=c) --up;
}
int ask(int p,int l,int r)
{
	if(l==r){
		int x=id[l];
		int t=min(a[x],c/w[x]);
		c-=t*w[x]; getw(); return t*v[x];
	}
	if(wei[p][up]<=c){
		int ret=val[p][up];
		c-=wei[p][up],getw(); return ret; 
	}
	if(wei[p][up-1]<=c && ex[p][up-1]>c){
		int ret=val[p][up-1];
		c-=wei[p][up-1],getw(); return ret;
	}
	int mid=l+r>>1;
	return ask(p<<1,l,mid) + ask(p<<1|1,mid+1,r);
}

signed main()
{
	n=read(),m=read();
	For(i,1,n)id[i]=i,a[i]=read(),w[i]=read(),v[i]=read();
	sort(id+1,id+n+1,cmp);
	For(i,1,n)pid[id[i]]=i;
	build(1,1,n);
	For(i,1,m){
		int o=read(),k,d;
		if(o<=2){
			o=(o==1?1:-1);
			k=read()*o,d=read();
			a[d]+=k;
			mdf(1,1,n,pid[d]);
		}
		else{
			c=read();
			up=18,getw();
			printf("%lld\n",ask(1,1,n));
		}
	}
	return 0;
}