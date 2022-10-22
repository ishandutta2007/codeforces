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
intvec nums;
void read()
{
	int t;
	std::scanf("%d %d",&N,nums);
	for (int i=1;i<N;++i)
	{
		std::scanf("%d",&t);
		nums[i] = nums[i-1]+t;
	}
}
int MIN = 360;
void check(int l,int r)
{
	if (l == 0)
	{
		if (abs(nums[r]-180) < MIN) MIN = abs(nums[r]-180);
	}
	else
	{
		if (abs(nums[r]-nums[l-1]-180) < MIN) MIN = abs(nums[r]-nums[l-1]-180);
	}
}
int main()
{
	read();
	for (int i=0;i<N;++i)
	for (int j=0;j<=i;++j)
	{
		check(j,i);
	}
	std::printf("%d\n",MIN*2);
}