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

int main()
{
	int k;
	std::scanf("%d",&k);
	if (k > 36)
	{
		std::printf("-1\n");
		return 0;
	}
	else
	{
		while (k >= 2)
		{
			std::printf("8");
			k -= 2;
		}
		if (k == 1) std::printf("9");
		std::printf("\n");
	}
}