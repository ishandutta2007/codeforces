#include<cstdio>
const int n = 10;
const int MAXN = n + 5;

char s[MAXN][MAXN];

inline bool chk_l(int x,int y)
{
	if(x>6) return 0;
	for(int k=1; k<=5; ++k)
		if(s[x+k-1][y]!='X') return 0;
	return 1;
}

inline bool chk_r(int x,int y)
{
	if(y>6) return 0;
	for(int k=1; k<=5; ++k)
		if(s[x][y+k-1]!='X') return 0;
	return 1;
}

inline bool chk_rd(int x,int y)
{
	if(x>6 || y>6) return 0;
	for(int k=1; k<=5; ++k)
		if(s[x+k-1][y+k-1]!='X') return 0;
	return 1;
}

inline bool chk_ld(int x,int y)
{
	if(x<5 || y>6) return 0;
	for(int k=1; k<=5; ++k)
		if(s[x-k+1][y+k-1]!='X') return 0;
	return 1;
}

inline bool chk(void)
{
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			if(chk_l(i,j) || chk_r(i,j) || chk_ld(i,j) || chk_rd(i,j)) return 1;
	return 0;
}

int main(void)
{
	for(int i=1; i<=n; ++i) scanf("%s",s[i]+1);
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j) if(s[i][j]=='.')
		{
			s[i][j]='X';
			if(chk())
			{
				printf("YES");
				return 0;
			}
			s[i][j]='.';
		}
	printf("NO");
	return 0;
}