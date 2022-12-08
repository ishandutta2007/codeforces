#include <cstdio>
#include <cstring>
#include <algorithm>

const int MN = 50;

int N;
char s[MN], t[MN];

void solve()
{
	scanf("%d", &N);
	scanf(" %s", s);
	memcpy(t, s, N*sizeof*s);
	int ans=0;
	std::sort(t, t+N);
	for(int i=0;i<N;++i) ans+=s[i]!=t[i];
	printf("%d\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}