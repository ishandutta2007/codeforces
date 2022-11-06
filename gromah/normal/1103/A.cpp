#include <cstdio>
#include <algorithm>
using namespace std;
#define N 1000 + 5

int Cur[2];
char s[N];

int main()
{
	scanf("%s", s);
	for (int i = 0; s[i]; i ++)
	{
		Cur[s[i] - '0'] ^= 1;
		if (s[i] == '0')
			printf("%d 1\n", Cur[s[i] - '0'] * 2 + 1);
		else printf("1 %d\n", Cur[s[i] - '0'] * 2 + 1);
	}
	return 0;
}