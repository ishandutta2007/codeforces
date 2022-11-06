#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int mo=998244353;
ll qk(ll x,ll y){ll r=1;
	for(;y;y>>=1){
		if(y&1)r=r*x%mo;x=x*x%mo;
	}return r;
}
ll a[3010][3010],w[N];int p[N];
int main(){int n,m;ll t1=0,t2=0;
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&p[i]);
	rep(i,1,n){
		scanf("%lld",&w[i]);
		if(p[i])t1+=w[i];else t2+=w[i];
	}
	a[0][0]=1;
	rep(i,0,m-1)rep(j,0,i){
		if(j>t2)break;
		ll T1=t1+i-j,T2=t2-j,ny=qk(T1+T2,mo-2);
		a[i+1][j+1]=(a[i+1][j+1]+a[i][j]*T2%mo*ny)%mo;
		a[i+1][j]=(a[i+1][j]+a[i][j]*T1%mo*ny)%mo;
	}ll tot1=0,tot2=0;
	rep(i,0,m){
		if(i>t2)break;
		tot1=(tot1+a[m][i]*(t1+m-i))%mo;
		tot2=(tot2+a[m][i]*(t2-i))%mo;
	}
	rep(i,1,n)
		if(p[i])printf("%lld\n",tot1*w[i]%mo*qk(t1,mo-2)%mo);
		else printf("%lld\n",tot2*w[i]%mo*qk(t2,mo-2)%mo);
}