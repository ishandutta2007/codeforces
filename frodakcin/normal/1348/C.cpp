#include <cstdio>
#include <algorithm>

const int MN = 1e5 + 100;
int T, N, K;
char s[MN], ans[MN];
int main(void)
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &N, &K);
		scanf(" %s", s);
		std::sort(s, s+N);
		if(K==1)
		{
			printf("%s\n", s);
			continue;
		}
		if(s[0] != s[K-1])
			printf("%c\n", s[K-1]);
		else
		{
			if(K == N)
				printf("%c\n", s[K-1]);
			else if(s[K] != s[N-1])
				printf("%s\n", s+(K-1));
			else
			{
				int j = 0;
				for(int i = 0;i < N;i += K)
					ans[j++] = s[i];
				ans[j] = 0;
				printf("%s\n", ans);
			}
		}
	}
	return 0;
}