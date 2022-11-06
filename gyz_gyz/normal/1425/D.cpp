#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=2e3+10;
const int mo=1e9+7;
bitset<2000>p[N];
int x[N],y[N],w[N],s[N];ll f[N],ny[N];
ll qk(ll x,int y){ll r=1;
	for(;y;y>>=1){
		if(y&1)r=r*x%mo;x=x*x%mo;
	}return r;
}
ll c(ll x,ll y){
	return x<y?0:f[x]*ny[y]%mo*ny[x-y]%mo;
}
int main(){int n,m,R,ans=0;
	f[0]=ny[0]=1;
	scanf("%d%d%d",&n,&m,&R);
	rep(i,1,n){
		f[i]=f[i-1]*i%mo;
		ny[i]=qk(f[i],mo-2);
	}
	rep(i,0,n-1)scanf("%d%d%d",&x[i],&y[i],&w[i]);
	rep(i,0,n-1)rep(j,0,n-1)if(abs(x[i]-x[j])<=R&&abs(y[i]-y[j])<=R)p[i][j]=p[j][i]=1;
	rep(i,0,n-1)s[i]=p[i].count();
	rep(i,0,n-1)rep(j,0,n-1){
		int ss=(p[i]|p[j]).count();
		ans=(ans+(mo*2+c(n,m)-c(n-s[i],m)-c(n-s[j],m)+c(n-ss,m))*w[i]%mo*w[j])%mo;
	}
	printf("%d\n",ans);
}