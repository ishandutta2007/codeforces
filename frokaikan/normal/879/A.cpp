#include <bits/stdc++.h>
#define constant const constexpr
typedef long long ll;
typedef long double db;
typedef std::string str;
constant int maxN = 1e5 + 3;
constant int iinf = 2147483647;
constant ll linf = 9223372036854775807LL;
constant db pi = std::acos(-1.0);
constant db eps = 1e-8;
int N,M;
template <typename T> inline constant T abs(T x){return x>=0?x:-x;}

int main()
{
	std::scanf("%d",&N);
	int a,b;
	int ans = 0;
	while (N--)
	{
		std::scanf("%d %d",&a,&b);
		if (ans < a) ans = a;
		else if (ans == a) ans = a+b;
		else if ((ans-a)%b) ans = a+(((ans-a)/b+1)*b);
		else ans += b;
	}
	std::printf("%d",ans);
}