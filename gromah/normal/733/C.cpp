#include <cstdio>
#define N 500 + 5

int n, m, last = 1, cnt, Delta, A[N], B[N], Pos[N];
char Op[N];
bool ok = 1;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", A + i);
		Delta += A[i];
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i ++)
	{
		scanf("%d", B + i);
		int end = last, sum = 0, Max = 0;
		while (1)
		{
			sum += A[end];
			if (A[end] > Max) Max = A[end];
			if (sum >= B[i]) break ;
			end ++;
		}
		Delta -= sum;
		if (sum > B[i])
		{
			ok = 0;
			break ;
		}
		if (last == end)
		{
			last ++;
			continue ;
		}
		ok = 0;
		for (int j = last; !ok && j < end; j ++)
			ok = A[j] != A[end];
		if (!ok) break ;
		if (A[last] == Max)
		{
			int st = last;
			for (; A[st + 1] == Max; st ++) ;
			for (int j = st + 1; j <= end; j ++)
			{
				cnt ++;
				Pos[cnt] = i + st - last;
				Op[cnt] = 'R';
			}
			for (; st > last; st --)
			{
				cnt ++;
				Pos[cnt] = i + st - last;
				Op[cnt] = 'L';
			}
		}
		else
		{
			int st = last;
			for (; A[st] != Max; st ++) ;
			for (int j = st; j > last; j --)
			{
				cnt ++;
				Pos[cnt] = i + j - last;
				Op[cnt] = 'L';
			}
			for (int j = st + 1; j <= end; j ++)
			{
				cnt ++;
				Pos[cnt] = i;
				Op[cnt] = 'R';
			}
		}
		last = end + 1;
	}
	if (!ok || Delta) puts("NO");
	else
	{
		puts("YES");
		for (int i = 1; i <= cnt; i ++)
			printf("%d %c\n", Pos[i], Op[i]);
	}
	return 0;
}