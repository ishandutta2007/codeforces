#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int p[111][5];
double dx[555], dy[555];
int cnt;
int n;

int main() {
	scanf("%d", &n);
	cnt=0;
	for(int j=0; j<5; ++j) p[1][j]=++cnt;
	dx[p[1][0]]=3.830127018922193; dy[p[1][0]]=3.366025403784439;
	dx[p[1][1]]=-3.601321235851749; dy[p[1][1]]=10.057331467373021;
	dx[p[1][2]]=0.466045194906253; dy[p[1][2]]=19.192786043799030;
	dx[p[1][3]]=10.411264148588986; dy[p[1][3]]=18.147501411122495;
	dx[p[1][4]]=12.490381056766580; dy[p[1][4]]=8.366025403784439;
	for(int i=2; i<=n; ++i) {
		p[i][0]=p[i-1][2];
		for(int j=1; j<5; ++j) p[i][j]=++cnt;
		double x0=dx[p[i-1][2]]-dx[p[i-1][0]];
		double y0=dy[p[i-1][2]]-dy[p[i-1][0]];
		for(int j=0; j<5; ++j) {
			dx[p[i][j]]=dx[p[i-1][j]]+x0;
			dy[p[i][j]]=dy[p[i-1][j]]+y0;
		}
	}
	printf("%d\n", cnt);
	for(int i=1; i<=cnt; ++i) printf("%.15lf %.15lf\n", dx[i], dy[i]);
	for(int i=1; i<=n; ++i)
		for(int j=0; j<5; ++j)
			printf("%d%c", p[i][j], j==4?'\n':' ');
	printf("%d", p[1][0]); for(int i=1; i<=n; ++i) printf(" %d", p[i][2]);
	for(int i=n; i>=1; --i) printf(" %d %d %d %d", p[i][4], p[i][1], p[i][3], p[i][0]);
	printf("\n");
	return 0;
}