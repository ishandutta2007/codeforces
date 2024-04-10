#include <cstdio>
#include <vector>

void out(const std::vector<int>& x)
{
	printf("next");
	for(auto a:x) printf(" %d", a);
	printf("\n");
	fflush(stdout);
}
int N, g[20];
char s[20];
void read()
{
	scanf("%d", &N);
	for(int i=0;i<N;++i)
	{
		scanf(" %s", s);
		for(int j=0;s[j];++j)
			g[s[j]-'0']=i;
	}
}
int main()
{
	for(;;)
	{
		out({0,1});
		read();
		out({0});
		read();
		if(g[0] == g[1]) break;
	}
	for(;;)
	{
		out({0,1,2,3,4,5,6,7,8,9});
		read();
		if(g[0] == g[2]) break;
	}
	printf("done\n");
	return 0;
}