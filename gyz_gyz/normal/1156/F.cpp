#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=5e3+10;
const int mo=998244353;
ll a[N][N],ny[N],p[N];
ll qk(ll x,int y){ll r=1;
	for(;y;y>>=1){
		if(y&1)r=r*x%mo;x=x*x%mo;
	}return r;
}
int main(){int n,m=0;
	scanf("%d",&n);
	rep(i,1,n)ny[i]=qk(i,mo-2);
	rep(i,1,n){int x;
		scanf("%d",&x);++p[x];
		m=max(m,x);
	}ll ans=0;
	rep(i,0,m)a[0][i]=1;
	rep(i,1,n)rep(j,1,m){
		a[i][j]=(a[i-1][j-1]*p[j]%mo*ny[n-i+1])%mo;
		if(i<n){
			ans=(ans+a[i][j]*(p[j]-1)%mo*ny[n-i])%mo;
			a[i][j]=(a[i][j]+a[i][j-1])%mo;
		}
	}
	printf("%lld\n",ans);
}