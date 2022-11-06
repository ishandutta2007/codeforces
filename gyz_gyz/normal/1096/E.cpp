#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=5110;
const int mo=998244353;
int c[N][N],f[N];
int qk(int x,int y){ll r=1;
	for(;y;y>>=1){
		if(y&1)r=1ll*r*x%mo;x=1ll*x*x%mo;
	}return r;
}
int main(){int n,m,s;
	scanf("%d%d%d",&n,&m,&s);
	rep(i,0,n+m){c[i][0]=1;
		rep(j,1,i)c[i][j]=(c[i-1][j-1]+c[i-1][j])%mo;
	}int ans=0;
	rep(i,s,m){
		if(n*i==m)ans+=qk(n,mo-2);
		if(n*i<=m)continue;		
		int mx=min(n-1,m/i);
		rep(j,1,mx){
			dep(k,mx,j){
				f[k]=1ll*c[m-k*i+n-j-1][n-j-1]*c[n-j][k-j]%mo;
				rep(l,k+1,mx)f[k]=(f[k]+mo-1ll*f[l]*c[l-j][k-j]%mo)%mo;
			}
			ans=(ans+1ll*f[j]*c[n-1][j-1]%mo*qk(j,mo-2))%mo;
		}
	}
	printf("%lld\n",1ll*ans*qk(c[n+m-s-1][n-1],mo-2)%mo);
}