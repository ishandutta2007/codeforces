#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 998244353;
const int maxn = 1e3 + 10;

inline int MOD(int x){return x<mod ? x:x-mod;}
inline void MODR(int &x,int a){x+=a;if(x>=mod) x-=mod;}
inline ll qpow(ll a,ll x){ll ans=1;for(;x;x>>=1,a=a*a%mod) if(x&1) ans=ans*a%mod;return ans;}

int n,m;

int main()
{

	// int i,j;
	scanf("%d%d",&n,&m);
	printf("%I64d\n",qpow(2,n+m));


	return 0;
}