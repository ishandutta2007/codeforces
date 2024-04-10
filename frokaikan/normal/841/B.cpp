#include <iostream>
#include <cstdio>
int n;
int main()
{
	bool flag = false;
	int tmp;
	std::scanf("%d",&n);
	for (int i=0;i<n;++i)
	{
		std::scanf("%d",&tmp);
		if (tmp%2) flag = true;
	}
	if (flag) std::printf("First");
	else std::printf("Second");
}