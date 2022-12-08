#include <cstdio>
#include <algorithm>

int N, f=100;
char s[2000][10];

int diff(int a, int b)
{
	int r=0;
	for(int i=0;i<6;++i)
		r+=s[a][i]!=s[b][i];
	return r;
}

int main()
{
	scanf("%d", &N);
	if(N==1) return printf("6\n"), 0;
	for(int i=0;i<N;++i)
		scanf(" %s", s[i]);
	for(int i=0;i<N;++i)
		for(int j=i+1;j<N;++j)
		{
			int x=diff(i,j);
			f=std::min(f, (x-1)/2);
		}
	printf("%d\n", f);
	return 0;
}