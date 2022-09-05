//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
const int mod=998244353;
const int maxn = 1000111;
int n;
ll fac[maxn], inv[maxn], ifac[maxn];
ll C(int x, int y) {return fac[x]*ifac[y]%mod*ifac[x-y]%mod;}
int main()
{
	fac[0] = 1;
	for (int i=1; i<maxn; i++) fac[i] = fac[i-1]*i%mod;
	inv[1] = 1;
	for (int i=2; i<maxn; i++) inv[i] = mod-inv[mod%i]*(mod/i)%mod;
	ifac[0] = 1;
	for (int i=1; i<maxn; i++) ifac[i] = ifac[i-1]*inv[i]%mod;
	cin>>n;
	ll ans = fac[n];
	for (int i=1; i<n; i++)
	{
		ans = (ans+(fac[n-i]-1)*C(n, i)%mod*fac[i]%mod)%mod;
	}
	cout<<(ans%mod+mod)%mod<<endl;
	return 0;
}