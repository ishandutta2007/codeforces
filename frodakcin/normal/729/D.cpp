#include <cstdio>
#include <vector>

int N, A, B, K;
char s[202000];
std::vector<int> f;
int main()
{
	scanf("%d%d%d%d", &N, &A, &B, &K);
	scanf(" %s", s);
	int c=0;
	for(int i=0;i<N;++i)
	{
		if(s[i] == '0')
			++c;
		else
			c=0;
		if(c == B)
			f.push_back(i+1), c=0;
	}
	printf("%d\n", f.size()-A+1);
	for(int i=0;i<f.size()-A+1;++i)
		printf("%d ", f[i]);
	return 0;
}