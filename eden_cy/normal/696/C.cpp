#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)

typedef long long ll;
const int Mod=(int)1e9+7;

ll Fast(ll x,ll b) {
	ll tmp=1;
	for(;b;b>>=1,x=(x*x)%Mod) if(b&1) tmp=tmp*x%Mod;
	return tmp;
}
int main() {
	int n,f=1;
	ll H=2,x;
	scanf("%d",&n);
	FOR(i,1,n) {
		scanf("%lld",&x);
		if(!(x&1)) f=0;
		H=Fast(H,x)%Mod;
	}
	H=(H*Fast(2,Mod-2))%Mod;
	ll res_2=H;
	if(f) H--;
	else H++;
	H=(H+Mod)%Mod;
	ll res_1=H*Fast(3,Mod-2)%Mod;
	printf("%lld/%lld\n",res_1,res_2);
	return 0;
}