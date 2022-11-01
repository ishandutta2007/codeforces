#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int map[2][310][310][8];
int vis[310][310];
int n,ans,t;
#define F map[i&1]
#define G map[i&1^1]

const int fx[] = {-1,-1, 0, 1, 1, 1, 0,-1};
const int fy[] = { 0, 1, 1, 1, 0,-1,-1,-1};

int main() {
	int x = 150 , y = 150;
	map[0][x][y][0] = 1;
	vis[x][y] = 1;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%d",&t); if (i == 1) t--;
		memset(F,0,sizeof(F));
		for (int x=0;x<=300;x++)
			for (int y=0;y<=300;y++)
				for (int p=0;p<=7;p++)
					if (G[x][y][p]) {
						int p1 = (p-1+8) % 8 , p2 = (p+1) % 8;
						for (int _=1;_<=t;_++) 
							vis[x+_*fx[p]][y+_*fy[p]] = 1;
						F[x+t*fx[p]][y+t*fy[p]][p1] = 1;
						F[x+t*fx[p]][y+t*fy[p]][p2] = 1;
					}
	}
	
	for (int x=0;x<=300;x++)
		for (int y=0;y<=300;y++)
			if (vis[x][y]) ans++;
	printf("%d\n",ans);
	return 0;
}