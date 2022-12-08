#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef pair<int,int> PII;
#define fi first
#define se second
#define PB push_back
#define MP make_pair
template<class T> bool setmin(T &a, T b) {
	if(b<a) {a=b; return true;} else return false;
}
template<class T> bool setmax(T &a, T b) {
	if(b>a) {a=b; return true;} else return false;
}
#define forint(i, a, b) for(int i=(int)(a); i<=(int)(b); ++i)
#define forintdown(i, a, b) for(int i=(int)(a); i>=(int)(b); --i)
#define forn(i, n) for(int i=0; i<(int)(n); ++i)
#define forndown(i, n) for(int i=(int)(n)-1; i>=0; --i)
#define fillchar(a, x) memset(a, x, sizeof(a))

const int MAXN=555;
const int MAXQ=MAXN*MAXN;

char grid[MAXN][MAXN];
int qx[MAXQ], qy[MAXQ];
int n, m, k;
const int dx[4]={-1, 0, 1, 0};
const int dy[4]={0, 1, 0, -1};
bool vis[MAXN][MAXN];

int main() {
	scanf("%d%d%d", &n,&m,&k);
	forint(i, 1, n) scanf("%s", grid[i]+1);
	if(k==0) {
		forint(i, 1, n) printf("%s\n", grid[i]+1);
		return 0;
	}
	int x=0, y=0; forint(i, 1, n) forint(j, 1, m) if(grid[i][j]=='.') x=i, y=j;
	int ss=0, tt=1; qx[1]=x, qy[1]=y;
	fillchar(vis, false); vis[x][y]=true;
	while(ss<tt) {
		x=qx[++ss], y=qy[ss];
		forn(i, 4) {
			int x0=x+dx[i], y0=y+dy[i];
			if(x0<1 || x0>n || y0<1 || y0>m) continue;
			if(!vis[x0][y0] && grid[x0][y0]=='.') {
				++tt; qx[tt]=x0, qy[tt]=y0;
				vis[x0][y0]=true;
			}
		}
	}
	forint(i, tt-k+1, tt) grid[qx[i]][qy[i]]='X';
	forint(i, 1, n) printf("%s\n", grid[i]+1);
	return 0;
}