#include <cstdio>
#include <algorithm>

template<typename T> bool ckmin(T& a, T b){return b<a?a=b,1:0;}

const int MN=1e6+10;
int T, N, K, p[MN], b[MN], ans;
char a[MN];

int main(void)
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &N, &K);
		scanf(" %s", a);
		for(int i=0;i<N;++i) a[i]=a[i]=='1';
		for(int i=0;i<N;++i)
			p[i+1]=p[i]+a[i];
		ans=N;
		for(int j=N-1;j>=0;--j)
		{
			b[j] = p[N]-p[j+1];
			if(j+K<N)
				ckmin(b[j], b[j+K]+p[j+K]-p[j+1]+!a[j]);
			ckmin(ans, b[j]+p[j]);
		}
		printf("%d\n", ans);
	}
	return 0;
}