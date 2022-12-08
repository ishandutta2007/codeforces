#include <cstdio>
#include <bitset>

const int ML = 1 << 11;
using bs = std::bitset<ML>;

void mul(int a, int &b)
{
	int f=0;
	f|=((a&1)&(b&1)^(a>>1&1)&(b>>2&1))<<0;
	f|=((a&1)&(b>>1&1)^(a>>1&1)&(b>>3))<<1;
	f|=((a>>2&1)&(b&1)^(a>>3)&(b>>2&1))<<2;
	f|=((a>>2&1)&(b>>1&1)^(a>>3)&(b>>3))<<3;
	b=f;
}

bs m[ML];//find x
int N, K, mod[ML];
bool u[ML];
char s[10];

int main()
{
	scanf("%d%d", &N, &K);
	for(int i=0;i<N;++i)
		mod[i] = 9;//identity
	for(int i=0,x,p;i<K;++i)
	{
		scanf(" %s%d", s, &x);
		if(s[0] == 'm') //add rule
		{
			for(int j=0,k;j<x;++j)
			{
				scanf("%d", &k), --k;
				if(mod[k]&1) m[i*2][k*2] = 1;
				if(mod[k]&2) m[i*2][k*2+1] = 1;
				if(mod[k]&4) m[i*2+1][k*2] = 1;
				if(mod[k]&8) m[i*2+1][k*2+1] = 1;
			}
			scanf(" %c", s);
			if(s[0] == 'R' || s[0] == 'B') m[i<<1][N*2]=1;
			if(s[0] == 'Y' || s[0] == 'B') m[i<<1|1][N*2]=1;
		}
		else if(s[1] == 'Y') //RY
			for(int j=0,k;j<x;++j)
				scanf("%d", &k), mul(6, mod[--k]);
		else if(s[0] == 'Y') //YB
			for(int j=0,k;j<x;++j)
				scanf("%d", &k), mul(11, mod[--k]);
		else // RB
			for(int j=0,k;j<x;++j)
				scanf("%d", &k), mul(13, mod[--k]);
	}
	//for(int i=0;i<2*K;++i) for(int j=0;j<=2*N;++j) printf("%d%c", m[i][j] == true, " \n"[j==2*N]); printf("\n");
	for(int i=0,c=0;i<=2*N;++i) //benq is actually so goddamn smart
	{
		int x=-1;
		for(int j=c;j<2*K;++j)
			if(m[j][i])
			{
				x=j;
				break;
			}
		if(!~x) continue;
		std::swap(m[x], m[c]);
		for(int j=0;j<2*K;++j)
			if(j!=c&&m[j][i])
				m[j]^=m[c];
		++c;
	}
	//for(int i=0;i<2*K;++i) for(int j=0;j<=2*N;++j) printf("%d%c", m[i][j] == true, " \n"[j==2*N]); printf("\n");
	for(int i=0;i<2*K;++i)
	{
		int x=0;
		for(;x<=2*N;++x)
			if(m[i][x]) break;
		if(x==2*N)
			return printf("NO\n"), 0;
		else
			u[x]=m[i][2*N];
	}
	printf("YES\n");
	for(int i=0;i<N;++i)
		printf("%c", ".RYB"[u[i<<1]|u[i<<1|1]<<1]);
	printf("\n");
	return 0;
}