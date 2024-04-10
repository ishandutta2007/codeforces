#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const constexpr int maxN = 1e5 + 3;
const constexpr int iinf = 2147483647;
const constexpr ll linf = 9223372036854775807LL;
const constexpr int mod = 1e9 + 7;
const constexpr db pi = std::acos(-1.0);
const constexpr db eps = 1e-10;
typedef std::string str;
typedef int intvec[maxN];
typedef ll llvec[maxN];
typedef bool boolvec[maxN];
typedef db dbvec[maxN];
template <typename T> const constexpr T abs(T x){return x>=0?x:-x;}


llvec numsN,numsM;
int N,M;
int main()
{
	std::scanf("%d %d",&N,&M);
	for (int i=0;i<N;++i) std::scanf("%I64d",numsN+i);
	for (int i=0;i<M;++i) std::scanf("%I64d",numsM+i);
	std::sort(numsN,numsN+N);
	std::sort(numsM,numsM+M);
	ll ans1 = -linf,ans2 = -linf,ans = -linf, tmp = 0LL;
	
	tmp = numsN[1]*numsM[0];
	if (tmp > ans1) ans1 = tmp;
	tmp = numsN[N-1]*numsM[0];
	if (tmp > ans1) ans1 = tmp;
	tmp = numsN[1]*numsM[M-1];
	if (tmp > ans1) ans1 = tmp;
	tmp = numsN[N-1]*numsM[M-1];
	if (tmp > ans1) ans1 = tmp;
	
	tmp = numsN[0]*numsM[0];
	if (tmp > ans2) ans2 = tmp;
	tmp = numsN[N-2]*numsM[0];
	if (tmp > ans2) ans2 = tmp;
	tmp = numsN[0]*numsM[M-1];
	if (tmp > ans2) ans2 = tmp;
	tmp = numsN[N-2]*numsM[M-1];
	if (tmp > ans2) ans2 = tmp;
	ans = std::min(ans1,ans2);
	std::printf("%I64d\n",ans);
}