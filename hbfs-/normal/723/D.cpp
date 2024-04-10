#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

#define N 150

using namespace std;

int n,m,tot,k;
char map[N][N],omap[N][N],s[N];
int vis[N][N],ocean[N][N];

bool aq(int x,int y) {
	if (x >= 1 && x <= n && y >= 1 && y <= m) return true;
	return false;
}

const int fx[] = {0,1,0,-1};
const int fy[] = {1,0,-1,0};

struct Monster{ int x,y,siz; }paul[N*N];
bool operator < (Monster p1,Monster p2) { return p1.siz < p2.siz; }

int DFS(int x,int y) {
	int siz = 1; vis[x][y] = 1;
	for (int i=0;i<=3;i++)
		if (!vis[x+fx[i]][y+fy[i]]) {
			if (!aq(x+fx[i],y+fy[i])) 
				ocean[x][y] = 1;
			else {
				siz += DFS(x+fx[i],y+fy[i]);
				if (ocean[x+fx[i]][y+fy[i]]) ocean[x][y] = 1;
			}
		}
	return siz;
}

void color(int x,int y) {
	vis[x][y] = true; omap[x][y] = '*';
	for (int i=0;i<=3;i++) {
		int xx = x + fx[i] , yy = y + fy[i];
		if (aq(xx,yy) && map[xx][yy] == '.' && !vis[xx][yy]) color(xx,yy);
	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++) {
		scanf("%s",s+1);
		for (int j=1;j<=m;j++) {
			map[i][j] = s[j];
			if (map[i][j] == '*') vis[i][j] = 1;
		}
	}
	
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			omap[i][j] = map[i][j];
	
	for (int i=1;i<=n;i++)  for (int j=1;j<=m;j++) if (!vis[i][j]) {
		//tot++;
		paul[++tot].siz = DFS(i,j);
		paul[tot].x = i;
		paul[tot].y = j;
		if (ocean[i][j]) tot--; 
	}
	
	sort(paul+1,paul+tot+1);
	
	memset(vis,0,sizeof(vis));
	
	int dest = tot - k , ans = 0;
	for (int i=1;i<=dest;i++) {
		ans += paul[i].siz;
		color(paul[i].x,paul[i].y);
	}
		
	printf("%d\n",ans);
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) printf("%c",omap[i][j]);
		printf("\n");
	}
	
	return 0;
}