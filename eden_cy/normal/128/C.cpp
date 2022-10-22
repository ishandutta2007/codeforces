#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define M 1005

typedef long long ll;
const int Mod=(int)1e9+7;

ll Fast(ll x,int b) {
	ll tmp=1;
	for(;b;b>>=1,x=x*x%Mod) if(b&1) tmp=tmp*x%Mod;
	return tmp;
}
ll C(int n,int m) {
	if(n<m) return 0;
	ll x=1,y=1;
	FOR(i,1,m) {
		x=x*(n-i+1)%Mod;
		y=y*i%Mod;
	}
	return x*Fast(y,Mod-2)%Mod;
}
int main() {
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	printf("%lld\n",C(n-1,k*2)*C(m-1,k*2)%Mod);
	return 0;
}