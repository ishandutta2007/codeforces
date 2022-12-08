#include <cstdio>

int N;
char s[110], t[110];
int main(void)
{
	scanf(" %s %s", s, t);
	for(;s[N];++N);
	int i=0;
	for(i=N-1;i>=0;--i)
	{
		if(s[i] != 'z')
		{
			++s[i];
			break;
		}
		s[i] = 'a';
	}
	if(!~i) goto fail;
	for(i=0;i<N;++i)
	{
		if(s[i] != t[i])
			if(s[i] > t[i])
				goto fail;
			else
				return printf("%s\n", s), 0;
	}
fail: ;
	printf("No such string\n");
	return 0;
}