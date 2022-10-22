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

void Mul(ll &x,ll y) {x=(x*y)%Mod;}
void Add(ll &x,ll y) {x=(x+y)%Mod;}

ll Fast(ll x,int b) {
	ll tmp=1;
	for(;b;b>>=1,x=x*x%Mod) if(b&1) tmp=tmp*x%Mod;
	return tmp;
}
ll Fac[M];
ll Inv[M];
ll C(ll x,ll y) {
	if(x<y) return 0;
	return Fac[x]*Inv[x-y]%Mod*Inv[y]%Mod;
}
ll Tmp[M];
ll sum[M];
ll H[M];
char str[M];
int main() {
	int n,K;
	scanf("%d%d%s",&n,&K,str+1);
	Fac[0]=1;
	FOR(i,1,n) Fac[i]=Fac[i-1]*i%Mod;
	Inv[n]=Fast(Fac[n],Mod-2);
	DOR(i,n-1,0) Inv[i]=Inv[i+1]*(i+1)%Mod;
	H[0]=1;
	FOR(i,1,n) H[i]=H[i-1]*10%Mod;
	FOR(i,1,n-1) Tmp[i]=H[i-1]*C(n-1-i,K-1);
//	cerr<<C(3,1)<<endl;
	FOR(i,1,n-1) sum[i]=(sum[i-1]+Tmp[i])%Mod;
	ll res=0;
	FOR(i,1,n) Add(res,(str[i]-'0')*sum[n-i]);
//	cerr<<res<<endl;
	FOR(i,1,n) Add(res,(str[i]-'0')*H[n-i]%Mod*C(i-1,K)%Mod);
	printf("%lld\n",(res+Mod)%Mod);
	return 0;
}