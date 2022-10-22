#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)

typedef long long ll;
const int Mod=(int)1e9+7;

ll Fast(ll x,int b) {
	ll tmp=1;
	for(;b;b>>=1,x=x*x%Mod) if(b&1) tmp=tmp*x%Mod;
	return tmp;
}
int mob(int x) {
	if(x==1) return 1;
	int tmp=1;
	for(int i=2;1ll*i*i<=x;i++) if(x%i==0) {
		if(x%(1ll*i*i)==0) return 0;
		x/=i;tmp=-tmp;
	}
	if(x!=1) tmp=-tmp;
	return tmp;
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	if(m%n) {
		puts("0");
		return 0;
	}
	n=m/n;
	ll res=0;
	for(int x=1;x*x<=n;x++) if(n%x==0) {
		int y=n/x;
		res=(res+mob(x)*Fast(2,y-1)%Mod)%Mod;
		if(y!=x) res=(res+mob(y)*Fast(2,x-1)%Mod)%Mod;
	}
	printf("%lld\n",(res+Mod)%Mod);
	return 0;
}