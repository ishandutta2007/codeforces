#include <cstdio>
#include <cstring>
#include <numeric>

const int MN = 1e2+10, MK = 1e2+10;

int N, K, c[MN*MK], ans[MN][2], p[MN], wh[MN*MK];
bool ok[MN];

int main()
{
	scanf("%d%d", &N, &K);
	for(int i=0;i<N*K;++i)
		scanf("%d", c+i);
	int len=N*K;
	std::iota(wh, wh+len, 1);

	memset(p, -1, sizeof p);
	for(int ctr=0;ctr<N;) // or just len>0
	{
		for(int i=0;i<len;++i)
		{
			if(!ok[c[i]] && p[c[i]]!=-1)
			{
				ans[c[i]][0]=wh[p[c[i]]];
				ans[c[i]][1]=wh[i];
				//printf("%d <-> %d\n", p[c[i]], i);
				ok[c[i]]=1;
				++ctr;
				memset(p+1, -1, N*sizeof*p);
			}
			else
				p[c[i]]=i;
		}
		memset(p+1, -1, N*sizeof*p);

		int nl=0;
		for(int i=0;i<len;++i)
			if(!ok[c[i]])
				c[nl]=c[i], wh[nl]=wh[i], ++nl;
		len=nl;
	}

	for(int i=1;i<=N;++i)
		printf("%d %d\n", ans[i][0], ans[i][1]);
	return 0;
}