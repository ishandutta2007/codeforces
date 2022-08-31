#include <iostream>
#include <cstdio>
using namespace std;
int n, pls;
int nums[24][3];
int main()
{
	scanf("%d%d", &n, &pls);
	nums[0][0] = 0, nums[0][1] = 1, nums[0][2] = 2;
	int cyc = 0;
	for(int i = 1; i <= 6; i++)
	{
		for(int j = 0; j < 3; j++)
			nums[i][j] = nums[i - 1][j];
		if(i % 2) swap(nums[i][0], nums[i][1]);
		else swap(nums[i][1], nums[i][2]);
		if(nums[i][0] == 0 && nums[i][1] == 1 && nums[i][2] == 2)
		{
			cyc = i;
			break;
		}
	}
	n %= cyc;
	printf("%d\n", nums[n][pls]);
}