#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define check(x,y) x>0&&y>0&&x<=n&&y<=m&&!p[x][y]
#define For(i,x,y) for (i=x;i<=y;i++)
using namespace std;
const int a[4][5][2]={0,0,0,1,0,2,1,1,2,1,0,0,1,0,1,1,1,2,2,0,0,0,1,0,1,-1,1,-2,
	2,0,0,0,1,0,2,0,2,-1,2,1};
int i,j,k,n,m,an;
char p[10][10],re[10][10];
void dfs(int x,int y,int s,int sum) {
	if (s+sum/5<=an) return;
	if (y>m) y=1,x++;
	if (x>n) {
		an=s;
		memcpy(re,p,sizeof(re));
		return;
	}
	dfs(x,y+1,s,sum-(!p[x][y]));
	if (p[x][y]) return;
	int i,j;
	char P=s+'A';
	For(i,0,3) {
		int F=0;
		For(j,0,4) {
			int A=x+a[i][j][0],B=y+a[i][j][1];
			if (!(check(A,B))) {
				F=1;
				break;
			} else p[A][B]=P;
		}
		if (!F)
		dfs(x,y+1,s+1,sum-5);
		For(j,0,4) {
			int A=x+a[i][j][0],B=y+a[i][j][1];
			if (p[A][B]==P) p[A][B]=0;
		}
	}
}
int main() {
	scanf("%d%d",&n,&m);
	dfs(1,1,0,n*m);
	printf("%d\n",an);
	For(i,1,n) {
		For(j,1,m) printf("%c",!re[i][j]?'.':re[i][j]);
		printf("\n");
	}
	//for(;;);
	return 0;
}