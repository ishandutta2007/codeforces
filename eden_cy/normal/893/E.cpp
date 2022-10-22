#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define M 1100005

typedef long long ll;
const int Mod=(int)1e9+7;

ll Fast(ll x,int b) {
	ll tmp=1;
	for(;b;b>>=1,x=x*x%Mod) if(b&1) tmp=tmp*x%Mod;
	return tmp;
}
ll Fac[M],Inv[M];
ll C(int x,int y) {
	return Fac[x]*Inv[y]%Mod*Inv[x-y]%Mod;
}
int prim[M];
int mark[M];
ll H[M];
int main() {
	Fac[0]=1;
	FOR(i,1,1100000) Fac[i]=Fac[i-1]*i%Mod;
	Inv[1100000]=Fast(Fac[1100000],Mod-2);
	DOR(i,1100000,1) Inv[i-1]=Inv[i]*i%Mod;
	
	int top=0;
	FOR(i,2,1000000) {
		if(!mark[i]) prim[++top]=i;
		FOR(j,1,top) {
			if(1ll*prim[j]*i>1000000) break;
			mark[prim[j]*i]=prim[j];
			if(i%prim[j]==0) break;
		}
	}
	H[0]=1;
	FOR(i,1,1000000) H[i]=(H[i-1]<<1)%Mod;
	
	int q,n,m;
	scanf("%d",&q);
	FOR(i,1,q) {
		scanf("%d%d",&n,&m);
		ll res=1;
		while(mark[n]) {
			int x=mark[n],cnt=0;
			while(n%x==0) n/=x,cnt++;
			res=res*C(cnt-1+m,m-1)%Mod;
		}
		if(n!=1) res=res*m%Mod;
		res=res*H[m-1]%Mod;
		printf("%lld\n",res);
	}
	return 0;
}