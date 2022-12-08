#include <cstdio>
#include <cassert>
#include <queue>

const int MN = 2.5e2+10;

int N, M, a[MN][MN], b[MN][MN], x=-1, y=-1, wh[MN*MN];
bool vr[MN], vc[MN], ur, uc;
std::queue<int> q;

int main()
{
	scanf("%d%d", &N, &M);
	for(int i=0;i<N;++i)
		for(int j=0;j<M;++j)
		{
			scanf("%d", a[i]+j);
			wh[a[i][j]]=i*M+j;
		}
	for(int i=N*M;i;--i)
	{
		int r=wh[i]/M, c=wh[i]-r*M;
		if(!vr[r]) ++x, ur=1, vr[r]=1; else ur=0;
		if(!vc[c]) ++y, uc=1, vc[c]=1; else uc=0;
		if(ur||uc)
		{
			b[x][y]=i;
			if(ur)
				for(int j=y-1;j>=0;--j)
					q.push(x*M+j);
			if(uc)
				for(int j=x-1;j>=0;--j)
					q.push(j*M+y);
		}
		else
		{
			assert(!q.empty());
			int t=q.front(); q.pop();
			b[t/M][t%M]=i;
		}
	}
	assert(q.empty());
	for(int i=0;i<N;++i)
		for(int j=0;j<M;++j)
			printf("%d%c", b[i][j], " \n"[j+1==M]);
	return 0;
}