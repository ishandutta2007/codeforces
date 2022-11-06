#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define N 3000010
#define mo 1000000007
using namespace std;
typedef long long ll;
int n,m,tot=-1;ll p[62],rp[62];char str[9];
ll qk(ll x,ll y){ll r=1;
	for(;y;y>>=1){
		if(y&1)r=r*x%mo;x=x*x%mo;
	}return r;
}
struct pr{ll s,v;pr(ll x=1,ll y=0){s=x;v=y;}
ll operator ~(){
	rep(i,0,tot){
		if(v&1)s=s*rp[i]%mo;v>>=1;
	}return s;
}
}a[N],b[N];
pr operator +(pr x,pr y){return {x.s*y.s%mo,x.v|y.v};}
pr operator *(pr x,ll y){return {qk(x.s,y),x.v};}
void f(int x,int l,int r,pr y,int L,int R){
	if(l<=L&&r>=R){
		a[x]=a[x]+y*(R-L+1);b[x]=b[x]+y;return;
	}int m=(L+R)/2;
	if(l<=m)f(x*2,l,r,y,L,m);
	if(r>m)f(x*2+1,l,r,y,m+1,R);
	a[x]=a[x*2]+a[x*2+1]+b[x]*(R-L+1);
}
pr q(int x,int l,int r,int L,int R){
	if(l==L&&r==R)return a[x];int m=(L+R)/2;
	if(r<=m)return q(x*2,l,r,L,m)+b[x]*(r-l+1);
	if(l>m)return q(x*2+1,l,r,m+1,R)+b[x]*(r-l+1);
	return q(x*2,l,m,L,m)+q(x*2+1,m+1,r,m+1,R)+b[x]*(r-l+1);
}
void cg(int l,int r,int x){pr s={x,0};
	rep(i,0,tot)if(!(x%p[i]))s.v|=1ll<<i;f(1,l,r,s,1,n);
}
int main(){
	rep(i,2,300){bool fl=1;
		rep(j,0,tot)if(!(i%p[j])){fl=0;break;}
		if(fl)p[++tot]=i,rp[tot]=(i-1)*qk(i,mo-2)%mo;
	}
	scanf("%d%d",&n,&m);
	rep(i,1,n){int x;
		scanf("%d",&x);cg(i,i,x);
	}
	while(m--){int l,r;
		scanf("%s%d%d",str,&l,&r);
		if(str[0]=='M'){int x;
			scanf("%d",&x);cg(l,r,x);
		}else printf("%lld\n",~q(1,l,r,1,n));
	}
}