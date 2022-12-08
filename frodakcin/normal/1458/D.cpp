#include <cstdio>
#include <vector>

const int MN = 5e5+10;

char s[MN];
void solve()
{
	int N;
	scanf(" %s", s);
	for(N=0;s[N];++N);
	std::vector<int> c(2*N, 0);
	for(int i=0, v=N;i<N;++i)
		if(s[i]=='1')
			++c[v++];
		else
			++c[--v];

	for(int i=0, v=N;i<N;++i)
		if(c[v-1] && !(c[v-1]==1&&c[v]))
			s[i]='0', --c[--v];
		else
			s[i]='1', --c[v++];

	printf("%s\n", s);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}