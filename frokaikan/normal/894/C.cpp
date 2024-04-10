#include <bits/stdc++.h>
const int maxN = 1e5 + 5;
typedef int intvec[maxN];
int gcd(int x,int y)
{
	while (y)
	{
		int tmp = x;
		x = y;
		y = tmp%y;
	}
	return x;
}
int m,g;
intvec nums;
int main()
{
	std::scanf("%d",&m);
	for (int i=0;i<m;++i)
	{
		int t;
		std::scanf("%d",&t);
		nums[i] = t;
	}
	g = nums[0];
	for (int i=0;i<m;++i) g = gcd(g,nums[i]);
	if (nums[0] == g)
	{
		std::printf("%d\n",2*m);
		for (int i=0;i<m;++i)
		{
			std::printf("%d %d",nums[i],g);
			if (i < m-1) std::printf(" ");
			else std::printf("\n");
		}
	}
	else std::printf("-1\n");
}