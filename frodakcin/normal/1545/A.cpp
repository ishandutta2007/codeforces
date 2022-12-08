#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

const int MN = 1e5+10;

int N, a[MN], b[MN];
std::map<int, int> map[2];

void solve()
{
	scanf("%d", &N);
	for(int i=0;i<N;++i)
		scanf("%d", a+i), b[i]=a[i];
	std::sort(b, b+N);

	for(int i=0;i<N;++i)
		++map[i&1][b[i]];

	bool ok=1;
	for(int i=0;ok && i<N;++i)
		if(--map[i&1][a[i]]<0)
			ok=0;
	map[0].clear();
	map[1].clear();

	if(ok) printf("Yes\n");
	else printf("No\n");
}

int main()
{
	int T; scanf("%d", &T);
	while(T--) solve();
	return 0;
}