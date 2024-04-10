#include <bits/stdc++.h>
#define constant const constexpr
typedef long long ll;
typedef long double db;
typedef std::string str;
constant int maxN = 1e5 + 3;
typedef int intvec[maxN];
typedef ll llvec[maxN];
typedef bool boolvec[maxN];
typedef str strvec[maxN];
typedef db dbvec[maxN];
typedef char c_str[maxN];
template <typename T> inline constant T abs(T x) {return x>=0?x:-x;}
template <typename T>
T pow(T x,ll n)
{
	T ans = 1, tmp = x;
	while (n)
	{
		if (n&1) ans = ans*tmp;
		tmp = tmp*tmp;
		n >>= 1;
	}
	return ans;
}
ll pow(ll x,ll n,ll mod)
{
	ll ans = 1LL, tmp = x;
	while (n)
	{
		if (n&1) ans = ans*tmp%mod;
		tmp = tmp*tmp%mod;
		n >>= 1;
	}
	return ans;
}

int N;
ll X,K;
llvec nums;
void read()
{
	std::scanf("%d %I64d %I64d",&N,&X,&K);
	for (int i=0;i<N;++i) std::scanf("%I64d",nums+i);
	std::sort(nums,nums+N);
}
ll cnt = 0LL;
void doit(int p)
{
	if (K)
	{
		ll t = (nums[p]-1LL)/X+K;
		cnt += std::lower_bound(nums,nums+N,(t+1)*X)-std::lower_bound(nums,nums+N,t*X);
	}
	else
	{
		if (nums[p]%X) cnt += std::lower_bound(nums,nums+N,nums[p]/X*X+X)-std::lower_bound(nums,nums+N,nums[p]);
	}
}
int main()
{
	read();
	for (int i=0;i<N;++i) doit(i);
	std::printf("%I64d\n",cnt);
}