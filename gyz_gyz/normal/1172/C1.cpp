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
ll a[99][99][99];int p[99];ll w[99];
int main(){int n,m;ll t1=0,t2=0;
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&p[i]);
	rep(i,1,n){
		scanf("%lld",&w[i]);
		if(p[i])t1+=w[i];else t2+=w[i];
	}
	rep(i,1,n){
		rep(j,0,m)rep(k,0,j)rep(l,0,j)a[j][k][l]=0;
		a[0][0][0]=1;
		rep(j,0,m-1)rep(k,0,j){
			ll T1=t1+k;
			ll T2=t2-(j-k);
			if(T2<0)continue;
			ll ny=qk(T1+T2,mo-2);			
			rep(l,0,j)if(a[j][k][l]){
				if(p[i]){
					a[j+1][k+1][l+1]=(a[j+1][k+1][l+1]+a[j][k][l]*(w[i]+l)%mo*ny)%mo;
					a[j+1][k+1][l]=(a[j+1][k+1][l]+a[j][k][l]*(T1-w[i]-l)%mo*ny)%mo;
					a[j+1][k][l]=(a[j+1][k][l]+a[j][k][l]*T2%mo*ny)%mo;
				}else{
					a[j+1][k][l+1]=(a[j+1][k][l+1]+a[j][k][l]*(w[i]-l)%mo*ny)%mo;
					a[j+1][k+1][l]=(a[j+1][k+1][l]+a[j][k][l]*T1%mo*ny)%mo;
					a[j+1][k][l]=(a[j+1][k][l]+a[j][k][l]*(T2-w[i]+l)%mo*ny)%mo;
				}
			}
		}ll ans=0;
		rep(k,0,m)rep(l,0,m){
			if(p[i])ans=(ans+a[m][k][l]*(w[i]+l))%mo;
			else ans=(ans+a[m][k][l]*(w[i]-l))%mo;
		}
		printf("%lld\n",ans);
	}
}