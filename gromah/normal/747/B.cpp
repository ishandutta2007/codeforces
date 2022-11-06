#include <cstdio>
#define N 300

int n, T[5];
char s[N], ch[5] = {"ATCG"};

inline int Trans(char x)
{
	if (x == 'A') return 0;
	if (x == 'T') return 1;
	if (x == 'C') return 2;
	if (x == 'G') return 3;
}

inline bool Solve()
{
	if (n & 3) return 0;
	for (int i = 0; i < n; i ++)
	{
		if (s[i] == '?') continue ;
		T[Trans(s[i])] ++;
	}
	for (int i = 0; i < 4; i ++)
	{
		if (T[i] > (n >> 2)) return 0;
		T[i] = (n >> 2) - T[i];
	}
	for (int i = 0, t = 0; i < n; i ++)
	{
		if (s[i] != '?') continue ;
		for (; t < 4 && !T[t]; t ++) ;
		s[i] = ch[t], T[t] --;
	}
	return 1;
}

int main()
{
	scanf("%d", &n);
	scanf("%s", s);
	if (Solve()) printf("%s\n", s);
		else puts("===");
	return 0;
}