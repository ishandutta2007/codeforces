#include <cstdio>
#include <algorithm>
using namespace std;
#define N 300000 + 5

int n, Cnt[3], Ret[3];
char s[N];

int main()
{
	scanf("%d", &n);
	scanf("%s", s);
	for (int i = 0; i < n; i ++)
		Cnt[s[i] - '0'] ++;
	for (int i = 0; i < 3; i ++)
		Ret[i] = n / 3;
	for (int i = 0; i < n; i ++)
		if (Cnt[s[i] - '0'] > n / 3)
		{
			if (s[i] == '0')
			{
				if (Ret[0])
					Ret[0] --;
				else
				{
					for (int j = 1; j <= 2; j ++)
						if (Cnt[j] < n / 3)
						{
							s[i] = '0' + j;
							Cnt[0] --, Cnt[j] ++;
							break ;
						}
				}
			}
			else if (s[i] == '2')
			{
				for (int j = 0; j <= 1; j ++)
					if (Cnt[j] < n / 3)
					{
						s[i] = '0' + j;
						Cnt[2] --, Cnt[j] ++;
						break ;
					}
			}
			else
			{
				if (Cnt[0] < n / 3)
				{
					s[i] = '0';
					Cnt[1] --, Cnt[0] ++;
				}
				else if (Ret[1])
					Ret[1] --;
				else
				{
					s[i] = '2';
					Cnt[1] --, Cnt[2] ++;
				}
			}
		}
	printf("%s\n", s);
	return 0;
}