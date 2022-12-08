#include <cstdio>

const int MN = 5e4+10;

int N, r[MN][5];
bool win(int i, int j)
{
	int c=0;
	for(int k=0;k<5;++k)
		if(r[i][k] < r[j][k])
			++c;
	return c >= 3;
}

void solve()
{
	scanf("%d", &N);
	for(int i=0;i<N;++i)
		for(int j=0;j<5;++j)
			scanf("%d", r[i]+j);

	int b=0;
	for(int i=1;i<N;++i)
		if(win(i, b))
			b=i;
	bool ok=1;
	for(int i=0;ok && i<N;++i)
		if(i!=b)
			if(win(i, b))
				ok=0;
	if(ok) printf("%d\n", b+1);
	else printf("-1\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}