#include <cstdio>

const int Ans[3] = {8, 5, 3};
int cnt = 0;
char s[9];

int main()
{
	scanf("%s", s);
	if (s[0] == 'a' || s[0] == 'h') cnt ++;
	if (s[1] == '1' || s[1] == '8') cnt ++;
	printf("%d\n", Ans[cnt]);
	return 0;
}