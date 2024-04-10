//N log N instead of N log N sqrt N
#include <cstdio>
#include <algorithm>
#define NDEBUG
#include <cassert>

using ll = long long;
const int MN = 2e5 + 100;
const int B = 400;

ll ans;
int N;
char s[MN];
bool a[MN];
int p[MN], n1[MN];
int c[MN];

int main(void)
{
	scanf(" %s", s);
	for(;s[N];++N)
		a[N] = s[N]=='1', p[N+1] = p[N]+a[N];

	//small
	for(int j = 0;j < B;++j)
	{
		for(int i = 0, x = 0, y = 0;i <= N;++i)
		{
			c[i] = y*j-x;
			if(a[i]) ++y; else ++x;
		}
		std::sort(c, c+N+1);
		for(int i = 0, k;i <= N;i=k)
			for(k=i+1;k <= N && c[k] == c[i];++k)
				ans += k-i;
	}
	//printf("SMALL: %lld\n", ans);

	//big
	n1[N] = N;
	for(int i = N-1, k = N;i >= 0;--i)
		n1[i] = k = a[i]?i:k;
	for(int l = 0, r;l < N;++l)
	{
		r = n1[l];
		for(int i = 1;l+i*B <= N && r < N;r = n1[r+1], ++i)
		{
			//[l,r] contains i ones
			//count r < k <= n1[r+1], (k-l) divides i
			assert(i == p[r+1]-p[l]);
			if(n1[r+1]-l >= i*B)
				ans += (n1[r+1]-l)/i - std::max(B, (r-l)/i);
		}
	}

	printf("%lld\n", ans);
	return 0;
}