#include <bits/stdc++.h>
#define constant const constexpr
constant int maxN = 2e3 + 3;
typedef int intvec[maxN];
int N;
intvec nums1,nums2;
std::set<int> nums;

void readin()
{
	std::scanf("%d",&N);
	for (int i=0;i<N;++i) std::scanf("%d",nums1+i);
	for (int i=0;i<N;++i) std::scanf("%d",nums2+i);
	for (int i=0;i<N;++i)
	{
		nums.insert(nums1[i]);
		nums.insert(nums2[i]);
	}
}
bool doit()
{
	bool flag = true;
	for (int i=0;i<N;++i)
	for (int j=0;j<N;++j)
	if (nums.count(nums1[i]^nums2[j]))
	{
		flag ^= 1;
	}
	return flag;
}
int main()
{
	readin();
	if (doit()) std::printf("Karen");
	else std::printf("Koyomi");
}