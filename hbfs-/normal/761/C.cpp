#include <iostream>
#include <cstdio>
#include <cstring>
#define INF (1<<30)
#define N 1050

using namespace std;
int F[10],g[10],n,m;
char s[1050];
int main() {
	scanf("%d%d",&n,&m);
	memset(F,127/3,sizeof(F)); F[0] = 0;
	for (int i=1;i<=n;i++) {
		scanf("%s",s+1);
		g[0] = g[1] = g[2] = INF;
		for (int j=1;j<=m;j++) {
			if (s[j] == '*' || s[j] == '#' || s[j] == '&') g[0] = min( min(j-1,m-(j-1)) , g[0] );
			if (s[j] >= '0' && s[j] <= '9') g[1] = min( min(j-1,m-(j-1)) , g[1] );
			if (s[j] >= 'a' && s[j] <= 'z') g[2] = min( min(j-1,m-(j-1)) , g[2] );
		}
		for (int j=7;j>=0;j--)
			for (int p=0;p<=2;p++) if (j&(1<<p))
				F[j] = min(F[j],F[j^(1<<p)] + g[p]);
	}
	printf("%d\n",F[7]);
	return 0;
}