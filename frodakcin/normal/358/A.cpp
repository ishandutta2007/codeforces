#include <cstdio>
#include <algorithm>

const int MN = 1e3+10;
const int MV = 1e7;

int N, a[MN], l=-MV, h=MV;
bool bad(int a, int b, int c, int d)
{
	if(a < c && c < b && b < d) return 1;
	if(c < a && a < d && d < b) return 1;
	return 0;
}
int main()
{
	scanf("%d", &N);
	for(int i=0;i<N;++i)
		scanf("%d", a+i);
	for(int i=0;i+1<N;++i)
	{
		for(int j=i+1;j+1<N;++j)
		{
			if(bad(std::min(a[i], a[i+1]), std::max(a[i], a[i+1]), std::min(a[j], a[j+1]), std::max(a[j], a[j+1])))
				return printf("yes\n"), 0;
		}
	}
	printf("no\n");
	return 0;
}