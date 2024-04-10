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

#define maxn 1000005
#define N 4000005
int n,m,a[maxn];

int mn[N],cnt[N],tag[N];
inline void up(int p){
	int ls=p<<1,rs=ls|1;
	mn[p]=min(mn[ls],mn[rs]),cnt[p]=0;
	if(mn[p]==mn[ls])cnt[p]+=cnt[ls];
	if(mn[p]==mn[rs])cnt[p]+=cnt[rs];
}
inline void pt(int p,int v){tag[p]+=v,mn[p]+=v;}
inline void pd(int p){if(tag[p])pt(p<<1,tag[p]),pt(p<<1|1,tag[p]),tag[p]=0;}
void mdf(int p,int l,int r,int nl,int nr,int v){
	if(nl>nr)return;
	if(l>=nl&&r<=nr)return pt(p,v);
	int mid=l+r>>1; pd(p); if(nl<=mid)mdf(p<<1,l,mid,nl,nr,v); if(nr>mid)mdf(p<<1|1,mid+1,r,nl,nr,v); up(p);
}
void mdfcnt(int p,int l,int r,int x,int y){
	if(l==r)return cnt[p]+=y,void();
	int mid=l+r>>1; pd(p); x<=mid?mdfcnt(p<<1,l,mid,x,y):mdfcnt(p<<1|1,mid+1,r,x,y); up(p); 
}
inline void ask(int p,int l,int r,int x){
	if(l==r)return cout<<cnt[p]<<' '<<mn[p]<<endl,void();
	int mid=l+r>>1; pd(p); x<=mid?ask(p<<1,l,mid,x):ask(p<<1|1,mid+1,r,x);
}
int lim = 1000000;
inline void upd(int x,int v){
//	cout<<"upd "<<min(a[x],a[x+1])<<' '<<max(a[x],a[x+1])-1<<endl;
	mdf(1,0,lim,min(a[x],a[x+1]),max(a[x],a[x+1])-1,v); 
}

multiset<int>S;
signed main()
{
	n=read(),m=read();
	a[0]=lim+1,a[n+1]=0;
	For(i,1,n)a[i]=read(),S.insert(a[i]);
	For(i,1,n) mdfcnt(1,0,lim,a[i],1);
	For(i,0,n) upd(i,1);
	For(_,1,m)
	{
		int x=read(),y=read();
		S.erase(S.find(a[x]));
		upd(x-1,-1),upd(x,-1);
		mdfcnt(1,0,lim,a[x],-1);
		a[x]=y,S.insert(y);
		mdfcnt(1,0,lim,a[x],1);
		upd(x-1,1),upd(x,1);
		cout<<cnt[1]<<endl;
	}
	return 0;
}
/*
5 3
25 40 30 20 10
*/