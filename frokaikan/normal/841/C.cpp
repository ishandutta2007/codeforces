#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>

int main()
{
	int n,tmp,tmp2;
	std::scanf("%d",&n);
	std::vector<int> A,B;
	std::map<int,int> B_count;
	for (int i=0;i<n;++i)
	{
		std::scanf("%d",&tmp);
		A.push_back(tmp);
	}
	for (int i=0;i<n;++i)
	{
		std::scanf("%d",&tmp);
		B.push_back(tmp);
		if (B_count.count(tmp)) ++B_count[tmp];
		else B_count[tmp] = 1;
	}
	std::sort(A.begin(),A.end(),std::greater<int>());
	tmp = 0;
	for (std::pair<const int,int>& x:B_count)
	{
		tmp2 = x.second;
		x.second += tmp;
		tmp += tmp2;
	}
	for (int i=0;i<n;++i)
	{
		std::printf("%d",A[--B_count[B[i]]]);
		if (i != n-1) std::printf(" ");
	}
}