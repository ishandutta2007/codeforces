#include<cstdio>
#include<cstring>
#define N 45
char s[N][N],a[N][N];
int n,m,L,now=1,ans,f[N][N][N][N],c[N][N],b[N*N];
int mex(){for (int i=0;;i++) if (b[i]!=now) return i;}
void work(int color)
{
	memset(a,' ',sizeof(a)),memset(f,0,sizeof(f)),memset(c,0,sizeof(c));
	for (int i=0;i<n;i++) for (int j=0;j<m;j++)
		if ((i+j)%2==color) a[i+j+1][i-j+m]=s[i][j],c[i+j+1][i-j+m]++;
	for (int i=L;i;i--) for (int j=L;j;j--)
		c[i][j]+=c[i+1][j]+c[i][j+1]-c[i+1][j+1];
	for (int i=1;i<L;i++) for (int j=1;j<L;j++)
		for (int x=1;x+i<=L;x++) for (int y=1;y+j<=L;y++)
			if (c[x][y]+c[x+i][y+j]-c[x+i][y]-c[x][y+j]){
				for (int dx=x;dx<x+i;dx++) for (int dy=y;dy<y+j;dy++){
					if (a[dx][dy]=='L') b[f[x][y][dx][y+j]^f[dx+1][y][x+i][y+j]]=now;
					if (a[dx][dy]=='R') b[f[x][y][x+i][dy]^f[x][dy+1][x+i][y+j]]=now;
					if (a[dx][dy]=='X') b[f[x][y][dx][dy]^f[dx+1][y][x+i][dy]^
									f[x][dy+1][dx][y+j]^f[dx+1][dy+1][x+i][y+j]]=now;
					}
				f[x][y][x+i][y+j]=mex(),now++;
				}
	ans^=f[1][1][L][L];
}
int main()
{
	scanf("%d%d",&n,&m),L=n+m; for (int i=0;i<n;i++) scanf("%s",s[i]);
	work(0),work(1),printf(ans?"WIN\n":"LOSE\n"); return 0;
}