#include <cstdio>

char s[1010];
int N, P;

bool ok(int i, char x)
{
	if(--i<0) return 1;
	if(s[i]==x) return 0;
	if(--i<0) return 1;
	if(s[i]==x) return 0;
	return 1;
}
int main()
{
	scanf("%d%d", &N, &P);
	scanf(" %s", s);
	char max = 'a'+P;
	int pal=-1;
	for(int i=N-1;!~pal && i>=0;--i)
	{
		++s[i];
		for(;s[i]<max;++s[i])
			if(ok(i, s[i]))
			{
				pal=i+1;
				break;
			}
	}
	if(~pal)
	{
		for(int i=pal;i<N;++i)
		{
			s[i]='a';
			for(;!ok(i, s[i]);++s[i]);
		}
		printf("%s\n", s);
	}
	else
		printf("NO\n");
	return 0;
}