#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
#define PB push_back
#define MP make_pair
#define forint(i, a, b) for(int i=(int)(a); i<=(int)(b); ++i)
#define forintdown(i, a, b) for(int i=(int)(a); i>=(int)(b); --i)
#define forn(i, n) for(int i=0; i<(int)(n); ++i)
#define forndown(i, n) for(int i=(int)(n)-1; i>=0; --i)
#define fillchar(a, x) memset(a, x, sizeof(a))
template<class T> void setmin(T &a, T b) { if(b<a) a=b; }
template<class T> void setmax(T &a, T b) { if(b>a) a=b; }
template<class T> T gcd(T a, T b) { return b==0 ? a : gcd(b,a%b); }

const int MAXN=1100;
int num[MAXN][MAXN]; char buf[MAXN];
bool ok[MAXN][MAXN];
int n, m, sx, sy, tx, ty;

int dis[MAXN][MAXN], qx[MAXN*MAXN], qy[MAXN*MAXN];

const int dx[4]={0, 1, 0, -1};
const int dy[4]={1, 0, -1, 0};

void bfs(int x0, int y0) {
	fillchar(dis, 0xff);
	int ss=0, tt=1; qx[1]=x0, qy[1]=y0;
	dis[x0][y0]=0;
	while(ss<tt) {
		int x=qx[++ss], y=qy[ss];
		for(int k=0; k<4; ++k) {
			int a=x+dx[k], b=y+dy[k];
			if(a>=1 && a<=n && b>=1 && b<=m)
				if(ok[a][b] && dis[a][b]<0) {
					dis[a][b]=dis[x][y]+1;
					++tt; qx[tt]=a, qy[tt]=b;
				}
		}
	}
}
int main() {
	scanf("%d%d", &n,&m); fillchar(ok, true);
	forint(i, 1, n) {
		scanf("%s", buf+1);
		forint(j, 1, m) {
			if(buf[j]=='T') ok[i][j]=false, num[i][j]=0;
			else if(buf[j]=='S') num[i][j]=0, sx=i, sy=j;
			else if(buf[j]=='E') num[i][j]=0, tx=i, ty=j;
			else num[i][j]=(int)(buf[j]-'0');
		}
	}
	bfs(sx, sy);
	int len=dis[tx][ty];
	bfs(tx, ty);
	int ans=0;
	forint(i, 1, n) forint(j, 1, m) if(dis[i][j]>=0 && dis[i][j]<=len) ans+=num[i][j];
	printf("%d\n", ans);

	return 0;
}