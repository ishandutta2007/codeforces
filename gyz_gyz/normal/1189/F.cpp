#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=1e3+10;
const int mo=998244353;
ll f[N][N];int a[N];
int main(){int n,k;
	scanf("%d%d",&n,&k);
	rep(i,1,n)scanf("%d",&a[i]);
	sort(a+1,a+n+1);ll ans=0;
	rep(i,0,n)f[0][i]=1;
	rep(i,1,(a[n]-a[1])/(k-1)){
		rep(j,1,k){int x=0;
			rep(l,1,n){
				while(a[l]-a[x+1]>=i)++x;
				f[j][l]=f[j-1][x];
			}
			rep(l,1,n)f[j][l]=(f[j][l]+f[j][l-1])%mo;
		}
		ans=(ans+f[k][n])%mo;
	}
	printf("%lld\n",ans);
}