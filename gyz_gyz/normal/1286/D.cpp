#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=1e5+10;
const int mo=998244353;
ll ans,ls=1,nw=1;int n;
ll qk(ll x,int y){ll r=1;
	for(;y;y>>=1){
		if(y&1)r=r*x%mo;x=x*x%mo;
	}return r;
}
struct fs{ll x,y;
	fs(ll X=0,ll Y=1){
		ll z=__gcd(X,Y);x=X/z;y=Y/z;
	}
	friend bool operator<(const fs&a,const fs&b){
		return a.x*b.y<a.y*b.x;
	}
	ll gt(){return x*qk(y,mo-2)%mo;}
};
struct pp{
	ll x;int t;
	pp(ll X=1){
		x=X%mo;t=0;
		if(!x)x=1,t=1;
	}
	friend pp operator+(pp a,const pp&b){
		if(a.t==b.t)a.x=(a.x+b.x)%mo;
		else if(a.t>b.t)a=b;
		return a;
	}
	friend pp operator*(pp a,const pp&b){
		a.x=a.x*b.x%mo;a.t+=b.t;return a;
	}
	friend pp operator/(pp a,const pp&b){
		a.x=a.x*qk(b.x,mo-2)%mo;a.t-=b.t;return a;
	}
	ll gt(){return t?0:x;}
}p0[N],p1[N],p2[N*4];
struct EV{
	int x,ty;fs t;
	friend bool operator<(const EV&a,const EV&b){return a.t<b.t;}
}ev[N*2];
ll X[N],V[N],p[N],w[N],t[N];
int f[N];bool v[N];
ll q0(int l,int r){return (p0[r]/p0[l-1]).gt();}
ll q1(int l,int r){return (p1[r]/p1[l-1]).gt();}
void bd(int x,int l,int r){
	if(l==r){
		p2[x]=p0[l-1]*p1[n]/p1[l-1];return;
	}
	int m=(l+r)>>1;
	bd(x<<1,l,m);bd(x<<1|1,m+1,r);
	p2[x]=p2[x<<1]+p2[x<<1|1];
}
pp q(int x,int l,int r,int L,int R){
	if(l==L&&r==R)return p2[x];
	int m=(L+R)>>1;
	if(r<=m)return q(x<<1,l,r,L,m);
	if(l>m)return q(x<<1|1,l,r,m+1,R);
	return q(x<<1,l,m,L,m)+q(x<<1|1,m+1,r,m+1,R);
}
ll q2(int l,int r){
	if(l>r)return 0;
	return (q(1,l,r+1,1,n+1)*p1[r]/p0[l-1]/p1[n]).gt();
}
struct SG{
	int l,r,L,R;
	ll cal(){return q0(l,L)*q1(R,r)%mo*q2(L+1,R-1)%mo;}
}sg[N];
void ext(int i){exit(printf("%lld\n",(ans+ls*ev[i].t.gt())%mo)*0);}
int gf(int x){return x==f[x]?x:f[x]=gf(f[x]);}
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%lld%lld%lld",&X[i],&V[i],&p[i]);
		p[i]=p[i]*qk(100,mo-2)%mo;
	}
	p0[0]=p1[0]=pp(1);
	rep(i,1,n)p0[i]=p0[i-1]*pp(mo+1-p[i]),p1[i]=p1[i-1]*pp(p[i]);
	bd(1,1,n+1);
	int tot=0;
	rep(i,1,n-1){
		ev[++tot]={i,0,fs(X[i+1]-X[i],(V[i]+V[i+1]))};
		if(V[i]!=V[i+1])ev[++tot]={i,V[i]<V[i+1]?1:2,fs(X[i+1]-X[i],abs(V[i]-V[i+1]))};
	}
	sort(ev+1,ev+tot+1);
	rep(i,1,tot){
		int x=ev[i].x;
		if(ev[i].ty){
			int y=gf(x);
			nw=nw*qk(sg[y].cal(),mo-2)%mo;
			if(ev[i].ty==1)sg[y].R=min(sg[y].R,x+1);
			else sg[y].L=max(sg[y].L,x);
			if(sg[y].L>sg[y].R)ext(i);
			nw=nw*sg[y].cal()%mo;
		}else{
			sg[x]={x,x+1,x-1,x+2};f[x]=x;
			int l=f[x-1]?gf(x-1):0,r=f[x+1]?gf(x+1):0;
			if(l){
				nw=nw*qk(sg[l].cal(),mo-2)%mo;
				f[l]=x;sg[x].l=sg[l].l;
				sg[x].L=sg[l].L;
			}
			if(r){
				nw=nw*qk(sg[r].cal(),mo-2)%mo;
				f[r]=x;sg[x].r=sg[r].r;
				sg[x].R=sg[r].R;
			}
			if(l&&sg[l].R<=sg[l].r)sg[x].R=sg[l].R;
			if(r&&sg[r].L>=sg[r].l)sg[x].L=sg[r].L;
			if(sg[x].L>sg[x].R)ext(i);
			nw=nw*sg[x].cal()%mo;
		}
		ans=(ans+(ls+mo-nw)*ev[i].t.gt())%mo;ls=nw;
	}
	printf("%lld\n",ans);
}