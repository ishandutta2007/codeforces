#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
#define N 1050
#define rep(n) for(i=1;i<=n;i++)
char mp[N][N];
int can[N][N],n,m,newmp[N][N];
int tx[]={0,1,0,-1,1,1,-1,-1};
int ty[]={1,0,-1,0,1,-1,1,-1};
int main() {
	scanf("%d%d",&n,&m);
	int i,j,k;
	rep(n)scanf("%s",mp[i]+1);
	for(i=2;i<n;i++)for(j=2;j<m;j++)can[i][j]=1;
	rep(n) {
		for(j=1;j<=m;j++) {
			if(mp[i][j]=='.') {
				for(k=0;k<8;k++) {
					int dx=i+tx[k],dy=j+ty[k];
					if(dx>=1&&dx<=n&&dy>=1&&dy<=m) can[dx][dy]=0;
				}	
			}
		}
	}
	rep(n) for(j=1;j<=m;j++) if(mp[i][j]!='.') {
		int flg=0;
		for(k=0;k<8;k++) {
			int dx=i+tx[k],dy=j+ty[k];
			if(dx>=1&&dx<=n&&dy>=1&&dy<=m&&can[dx][dy]) {flg=1; break;}
		}
		if(!flg) return puts("NO"),0;
	}
	puts("YES");
}