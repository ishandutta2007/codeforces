#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
int nums[10];
int a[4];
int main()
{
	int nows = 0;
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 4; j++)	
			printf("%d", i);
		printf("\n");
		fflush(stdout);
		int as, b;
		scanf("%d%d", &as, &b);
		if(as == 1) a[nows++] = i; 
	}
	bool ri = false;
	int xh[4];
	for( xh[0] = 0; xh[0] < 4; xh[0]++)
		for(xh[1] = 0; xh[1] < 4; xh[1]++)
			for(xh[2] = 0; xh[2] < 4; xh[2]++)
				for(xh[3] = 0; xh[3] < 4; xh[3]++)
				{
					if(ri) continue;
					bool flag = true;
					for(int i = 0; i < 4; i++)
						for(int j = i + 1; j < 4; j++)	
							if(xh[i] == xh[j]) 
								flag = false;
					if(!flag) continue;
					for(int i = 0; i < 4; i++)
						printf("%d", a[xh[i]]);
					printf("\n");
					fflush(stdout);
					int a, b;
					scanf("%d%d", &a, &b);
					if(a == 4) ri = true;
				}
}