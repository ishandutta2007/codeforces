#include <bits/stdc++.h>
#define constant const constexpr
#define clr(x,v) std::memset(x,v,sizeof(x))
typedef long double db;
typedef long long ll;
typedef unsigned long long ull;
typedef std::string str;
constant int iinf = 0x3f3f3f;
constant ll linf = 0x3f3f3f3f3f3fLL;
constant db pi = std::acos(-1.0);
constant db eps = 1e-10;
constant ll mod = 1e9+7;
constant int maxN = 1<<22|3;
typedef int intvec[maxN];
typedef ll llvec[maxN];
typedef bool boolvec[maxN];
typedef str strvec[maxN];
typedef char c_str[maxN];
typedef db dbvec[maxN];
typedef ull ullvec[maxN];
template <typename T> inline constant T abs(T x) {return x>=0?x:-x;}
void quicker() {std::ios_base::sync_with_stdio(false);std::cin.tie(nullptr);}
ll pow(ll x,ll n,ll m)
{
	n %= m-1;
	if (n<0) return pow(x,n*(2-m),m);
	ll ans=1LL,tmp=x;
	while (n)
	{
		if (n&1) ans = ans*tmp%m;
		tmp = tmp*tmp%m;
		n >>= 1;
	}
	return ans;
}
int lowbit(int x) {return x&-x;}

boolvec exists,used;
int N,M,tmp;
void dfs(int x)
{
	if (used[x]) return;
	//std::printf("dfs %d\n",x);
	used[x] = true;
 	//int inv = (1<<N)-1-x;
	if (exists[x]) dfs((1<<N)-1-x);
	for (int i=0;i<N;++i)
	{
		if (x&(1<<i)) dfs(x^(1<<i));
	}
}
int main()
{
	std::fill_n(exists,maxN,false);
	std::fill_n(used,maxN,false);
	std::scanf("%d %d",&N,&M);
	for (int i=0;i<M;++i)
	{
		std::scanf("%d",&tmp);
		exists[tmp] = true;
	}
	int cnt = 0;
	for (int i=0;i<1<<N;++i)
	{
		if (used[i]||!exists[i]) continue;
		++cnt;
		//std::printf("++cnt\n");
		used[i] = true;
		dfs((1<<N)-1-i);
	}
	std::printf("%d\n",cnt);
}