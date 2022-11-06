#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 100 + 5

int len, Max;
char s[N];

inline bool Check(char ch)
{
	return ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'Y';
}

int main()
{
	scanf("%s", s);
	len = strlen(s);
	for (int i = 0, last = -1; i <= len; i ++)
		if (i == len || Check(s[i]))
			Max = max(Max, i - last), last = i;
	printf("%d\n", Max);
	return 0;
}