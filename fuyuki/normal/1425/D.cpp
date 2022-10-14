#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=2e3+1,mod=1e9+7;
int n,m,R,ans;
bitset<N>val[N],tmp;
int X[N],Y[N],w[N],fac[N],inv[N],siz[N];
I pw(int x){return 1ll*x*x%mod;}
V check(int&x){x-=mod,x+=x>>31&mod;}
I f(int x,int y){
	if(x<y)return 0;
	return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
V input(){
	scanf("%d%d%d",&n,&m,&R);
	FOR(i,1,n)scanf("%d%d%d",X+i,Y+i,w+i);
}
V init(){
	inv[0]=inv[1]=fac[0]=1;
	FOR(i,1,n)FOR(j,1,n)if(abs(X[i]-X[j])<=R&&abs(Y[i]-Y[j])<=R)
		val[i][j]=1,siz[i]++;
	FOR(i,2,n)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	FOR(i,1,n)inv[i]=1ll*inv[i-1]*inv[i]%mod,fac[i]=1ll*fac[i-1]*i%mod;
}
V work(int A=0,int B=0,int C=0,int p=0,int sum=f(n,m)){
	FOR(i,1,n)
		check(ans+=1ll*(sum-f(n-siz[i],m)+mod)*pw(w[i])%mod);
	FOR(i,1,n)FOR(j,i+1,n){
		A=siz[i],B=siz[j],C=(val[i]&val[j]).count();
		p=(2ll*mod+sum-f(n-B,m)-f(n-A,m)+f(n-A-B+C,m))%mod;
		check(ans+=2ll*p*w[i]%mod*w[j]%mod);
	}
	cout<<ans;
}
int main(){
//	freopen("test.in","r",stdin);
	input();
	init();
	work();
	return 0;
}