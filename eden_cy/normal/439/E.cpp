#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define M 100005

typedef long long ll;
const int Mod=(int)1e9+7;

ll Fast(ll x,int b) {
	ll tmp=1;
	for(;b;b>>=1,x=x*x%Mod) if(b&1) tmp=tmp*x%Mod;
	return tmp;
}
ll Fac[M],Inv[M];
ll C(int n,int m) {
	if(n<m) return 0;
	return Fac[n]*Inv[m]%Mod*Inv[n-m]%Mod;
}
int prim[M],mo[M];
bool mark[M];
void Init() {
	int n=100000;
	Fac[0]=1;
	FOR(i,1,n) Fac[i]=Fac[i-1]*i%Mod;
	Inv[n]=Fast(Fac[n],Mod-2);
	DOR(i,n,1) Inv[i-1]=Inv[i]*i%Mod;
	mo[1]=1;
	int top=0;
	FOR(i,2,n) {
		if(!mark[i]) {
			prim[++top]=i;
			mo[i]=-1;
		}
		FOR(j,1,top) {
			if(1ll*i*prim[j]>n) continue;
			mark[i*prim[j]]=true;
			if(i%prim[j]==0) {
				mo[i*prim[j]]=0;
				break;
			} else mo[i*prim[j]]=-mo[i];
		}
	}
}
int main() {
	Init();
//	cerr<<mo[2]<<endl;
	int q,n,m;
	scanf("%d",&q);
	FOR(t,1,q) {
		scanf("%d%d",&n,&m);
		ll res=0;
		for(int x=1;x*x<=n;x++) if(n%x==0) {
			int y=n/x;
			res=(res+mo[x]*C(y-1,m-1))%Mod;
			if(y!=x) res=(res+mo[y]*C(x-1,m-1))%Mod;
		}
		printf("%lld\n",(res+Mod)%Mod);
	}
	return 0;
}