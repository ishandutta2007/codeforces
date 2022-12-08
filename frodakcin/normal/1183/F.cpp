#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

const int MN = 2e5 + 100;
int N;
int a[MN];
bool e[MN];
int f;
int c[3], C;

bool test(int v)
{
	for(int i = 0;i < C;i++)
		if(!(c[i]%v))
			return 0;
	return 1;
}
void solve(void)
{
	f = 0;
	scanf("%d", &N);
	for(int i = 0;i < N;i++)
		scanf("%d", a+i);
	sort(a,a+N,greater<int>());
	N = unique(a,a+N)-a;
	for(int i = 0;i < N;i++)
		e[a[i]] = 1;
	C = 0;
	for(int i = 0;i < N && C < 3;i++)
		if(test(a[i]))
			c[C++] = a[i], f += a[i];
	for(int i = 0;i < N;i++)
		if(!(a[i]&1) && a[i]%3==0 && a[i]%5==0)
			if(e[a[i]>>1] && e[a[i]/3] && e[a[i]/5])
				f = max(f, (a[i]>>1) + a[i]/3 + a[i]/5);
	for(int i = 0;i < N;i++)
		e[a[i]] = 0;
	printf("%d\n", f);
}

int Q;
int main(void)
{
	scanf("%d", &Q);
	for(int i = 0;i < Q;i++)
		solve();
	return 0;
}