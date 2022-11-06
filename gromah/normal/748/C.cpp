#include <cstdio>
#include <cstring>
#define N 200000 + 5

char s[N];
int n, step = 1;
bool Flag[4];

inline int Trans(char ch)
{
	if (ch == 'U') return 0;
	else if (ch == 'D') return 1;
	else if (ch == 'L') return 2;
	else return 3;
}

int main()
{
	scanf("%d", &n);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i ++)
	{
		int d = Trans(s[i]);
		if (Flag[d ^ 1])
		{
			step ++;
			Flag[0] = Flag[1] = Flag[2] = Flag[3] = 0;
		}
		Flag[d] = 1;
	}
	printf("%d\n", step);
	return 0;
}