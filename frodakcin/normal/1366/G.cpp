#include <cstdio>
#include <cstring>
#include <algorithm>

const int MN = 1e4+10;//CHANGE
const int INF = 0x3f3f3f3f;

char s[MN], t[MN];
int S, T, dpc[MN], dpn[MN], p[MN*2], nx[MN];
int main(void)
{
	scanf(" %s %s", s, t);
	for(;s[S];++S);
	for(;t[T];++T);
	s[S] = t[T] = '$';
	memset(p, -1, sizeof p);
	memset(nx, -1, sizeof nx);
	for(int i=S-1, c=MN;i>=0;--i)
		if(s[i] == '.')
			p[c++]=i;
		else
		{
			nx[i]=p[--c];
			if(~nx[i])++nx[i];
			//printf("%d: %d\n", i, nx[i]);
		}

	memset(dpn, 0x3f, sizeof dpn);
	dpn[0]=0;
	for(int i=0;i<=T;++i)
	{
		memcpy(dpc, dpn, sizeof dpc);
		memset(dpn, 0x3f, sizeof dpn);
		for(int j=0;j<=S;++j)
		{
			//if(dpn[j] < INF) printf("dp[%d][%d] = %d\n", i, j, dpn[j]);
			if(dpc[j] >= INF) continue;
			if(s[j]==t[i]) dpn[j+1] = std::min(dpn[j+1], dpc[j]);
			dpc[j+1] = std::min(dpc[j+1], dpc[j]+1);
			if(~nx[j]) dpc[nx[j]] = std::min(dpc[nx[j]], dpc[j]);
		}
	}
	printf("%d\n", dpn[S+1]);
	return 0;
}