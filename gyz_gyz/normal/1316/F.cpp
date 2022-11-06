#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e5+10;
const int mo=1e9+7;
const ll n2=(mo+1)/2;
int rot;
struct po{
	int ff,ch[2],size;
	ll val,lp,rp,xp;
	po(ll x=0){
		ff=ch[0]=ch[1]=0;
		val=x;lp=rp=x*n2%mo;
		size=x>0;xp=0;
	}
}a[N];
ll p2[N];
void up(int x){
	int ls=a[x].ch[0],rs=a[x].ch[1];
	int lsz=a[ls].size,rsz=a[rs].size;
	a[x].size=lsz+rsz+1;
	a[x].lp=(a[rs].lp+(a[x].val+a[ls].lp)*p2[rsz+1])%mo;
	a[x].rp=(a[ls].rp+(a[x].val+a[rs].rp)*p2[lsz+1])%mo;
	a[x].xp=(a[ls].xp+a[rs].xp+(a[ls].lp*a[rs].rp+a[x].val*(a[ls].lp+a[rs].rp))%mo*n2)%mo;
}
void rotate(int x){
	int y=a[x].ff,z=a[y].ff,k=(a[y].ch[1]==x);
	if(z)a[z].ch[a[z].ch[1]==y]=x;
	a[x].ff=z;
	a[y].ch[k]=a[x].ch[k^1];
	if(a[x].ch[k^1])a[a[x].ch[k^1]].ff=y;
	a[x].ch[k^1]=y;
	a[y].ff=x;
	up(y);
	up(x);
}
void splay(int x,int goal=0){
	while(a[x].ff!=goal){
		int y=a[x].ff,z=a[y].ff;
		if(z!=goal){
			if((a[z].ch[0]==y)^(a[y].ch[0]==x))rotate(x);else rotate(y);
		}
		rotate(x);
	}
	if(x)up(x);
	if(!goal)rot=x;
}
void insert(ll x,int y){
	int fa=0,u=rot;
	while(u){
		fa=u;
		u=a[u].ch[x==a[u].val?y>u:x>a[u].val];
	}
	u=y;
	if(!fa)rot=u;
	else a[fa].ch[x==a[fa].val?y>fa:x>a[fa].val]=u;
	a[u]=po(x);
	a[u].ff=fa;
	splay(u);
}
int nxt(int x,bool y){
	splay(x);
	x=a[x].ch[y];
	while(a[x].ch[y^1])x=a[x].ch[y^1];
	return x;
}
void erase(int x){
	int xp=nxt(x,0),xn=nxt(x,1);
	if(xn){
		if(xp){
			splay(xp);
			splay(xn,rot);
		}else splay(xn);
		a[xn].ch[0]=0;
		splay(xn);
	}else{
		if(xp){
			splay(xp);
			a[xp].ch[1]=0;
			splay(xp);
		}else rot=0;
	}
}
int main(){int n,m;
	scanf("%d",&n);p2[0]=1;
	rep(i,1,n)p2[i]=p2[i-1]*n2%mo;
	rep(i,1,n){ll x;
		scanf("%lld",&x);
		insert(x,i);
	}
	printf("%lld\n",a[rot].xp);
	scanf("%d",&m);
	rep(i,1,m){int x;ll y;
		scanf("%d%lld",&x,&y);
		erase(x);
		insert(y,x);
		printf("%lld\n",a[rot].xp);
	}
}