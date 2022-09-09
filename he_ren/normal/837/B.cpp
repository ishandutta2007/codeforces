#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int MAXN = 100 + 5;

inline void ok(void){ printf("YES"); exit(0);}

int n,m;
char s[MAXN][MAXN];

inline bool chk_c(int sx,int nx,char c)
{
	for(int i=sx; i<=nx; ++i)
		for(int j=1; j<=m; ++j)
			if(s[i][j]!=c) return 0;
	return 1;
}

void chk(void)
{
	if(n%3) return;
	
	int t=n/3;
	char c1=s[1][1], c2=s[t+1][1], c3=s[t*2+1][1];
	if(c1==c2 || c1==c3 || c2==c3) return;
	
	if(chk_c(1,t,c1) && chk_c(t+1,t*2,c2) && chk_c(t*2+1,n,c3))
		ok();
}

int main(void)
{
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%s",s[i]+1);
	
	chk();
	for(int i=1; i<=n || i<=m; ++i)
		for(int j=1; j<i; ++j) swap(s[i][j], s[j][i]);
	swap(n,m);
	chk();
	
	printf("NO");
	return 0;
}