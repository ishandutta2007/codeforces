#include <cstdio>
#include <cstring>
#include <algorithm>

const int MN = 3e5+10;
int T, N, a[MN];

int main()
{
	scanf("%d", &T);
	for(;T--;)
	{
		scanf("%d", &N);
		for(int i=0;i<N;++i) scanf("%d", a+i);
		if(a[0] < a[N-1]) printf("YES\n");
		else printf("NO\n");
	}
	//i am retarded
	return 0;
}