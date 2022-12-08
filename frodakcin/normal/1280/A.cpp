#include <cstdio>

using ll = long long;
const int MN = 1e3 + 10;
const int MX = 1e6 + 100;
const int MOD = 1e9 + 7;
char s[MX];

int x, N;
ll f;

void generate()
{
	for(int i = 0, cn = N;N < x;++i, cn = N)
		for(char k = '1';k < s[i] && N < x;++k)
			for(int j = i+1;j < cn && N < x;++j)
				s[N++] = s[j];
}
ll L = 0LL;
void solve()
{
	scanf("%d %s", &x, s);
	for(N=0;s[N];++N);
	L = N;
	generate();
	for(int i = 0;i < x;++i)
		L = (L-1)*(s[i]-48)%MOD + MOD;
	printf("%d\n", static_cast<int>((L+x)%MOD));
}

int t;
int main(void)
{
	scanf("%d", &t);
	for(;t--;)
		solve();
	return 0;
}