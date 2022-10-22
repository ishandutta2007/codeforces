#include <bits/stdc++.h>
#define constant const constexpr
int main()
{
	int N,k,x,t,ans;
	std::scanf("%d %d %d",&N,&k,&x);
	ans = 0;
	for (int i=0;i<N;++i)
	{
		std::scanf("%d",&t);
		if (i < N-k) ans += t;
		else ans += x;
	}
	std::printf("%d",ans);
}