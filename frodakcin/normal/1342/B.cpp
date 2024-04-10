#include <cstdio>

char s[1010];
int T, t, same;
int main(void)
{
	scanf("%d", &T);
	while(T--)
	{
		scanf(" %s", s);
		same = 1;
		for(t=0;s[t];++t)
			if(t && s[t] != s[t-1])
				same = 0;
		if(same)
			printf("%s\n", s);
		else
		{
			for(int i = 0;i < t;++i)
				printf("01");
			printf("\n");
		}
	}
	return 0;
}