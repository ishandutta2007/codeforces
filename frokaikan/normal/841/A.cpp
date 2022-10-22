#include <iostream>
#include <cstdio>
#include <map>
int n,k;
std::map<char,int> balloons;
char balloon[103];
int main()
{
	std::scanf("%d %d",&n,&k);
	std::scanf("%s",balloon);
	for (int i=0;i<n;++i)
	{
		if (balloons.count(balloon[i]))
		{
			++balloons[balloon[i]];
			if (balloons[balloon[i]] > k)
			{
				std::printf("NO");
				return 0;
			}
		}
		else balloons[balloon[i]] = 1;
	}
	std::printf("YES");
	return 0;
}