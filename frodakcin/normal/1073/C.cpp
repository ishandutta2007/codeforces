#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>

const int MN = 2e5+10;
char s[MN], d[]="URDL";
int p[MN][4], x, y, N;
int abs(int v){return v<0?-v:v;}

bool ok(int l, int r)//[l,r)
{
	if(l>r) return 0;
	int X = (p[N][1]-p[r][1]+p[l][1])-(p[N][3]-p[r][3]+p[l][3]);
	int Y = (p[N][0]-p[r][0]+p[l][0])-(p[N][2]-p[r][2]+p[l][2]);
	if(std::abs(X-x)+std::abs(Y-y) <= r-l)
		return 1;
	return 0;
}
int main(void)
{
	scanf("%d", &N);
	scanf(" %s", s);
	scanf("%d%d", &x, &y);
	for(int i=0;i<N;++i)
	{
		int j=0;
		for(;s[i]!=d[j];++j);
		s[i]=j;
		memcpy(p[i+1], p[i], 16);
		p[i+1][s[i]]++;
	}
	if(abs(x)+abs(y)>N || (abs(x)+abs(y)&1)!=(N&1))
		return printf("-1\n"), 0;
	int f=N*5;
	for(int i=0,j=0;j<=N;++j)
	{
		if(!ok(i,j)) continue;
		while(ok(i+1, j))
			++i;
		assert(i <= j);
		f = std::min(f, j-i);
	}
	assert(f<=N);
	printf("%d\n", f);
	return 0;
}