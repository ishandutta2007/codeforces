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

const int MAXN=1010;

int a[MAXN][MAXN];
int height, width;

int gcd(int a, int b) {
	return b==0?a:gcd(b,a%b);
}

const int dx[4]={0, 1, 0, -1};
const int dy[4]={1, 0, -1, 0};

int vis[MAXN][MAXN];
bool pass[MAXN][MAXN][4];
int deg[MAXN*MAXN], num;

void dfs(int x, int y, int k) {
//printf("%d %d vis=%d\n",x,y,vis[x][y]);
	if(vis[x][y]>0) return;
	vis[x][y]=++num;
	forn(i, 4) if(!pass[x][y][i] && a[x+dx[i]][y+dy[i]]==1) {
		int x0=x, y0=y;
		forn(j, k) {
			int x1=x0+dx[i], y1=y0+dy[i];
			pass[x0][y0][i]=true;
			pass[x1][y1][(i+2)%4]=true;
			x0=x1, y0=y1;
			if(j<k-1) vis[x1][y1]=-1;
		}
		dfs(x0, y0, k);
		++deg[vis[x][y]];
		++deg[vis[x0][y0]];
	}
}

bool check(int k) {
	int sx, sy;
	forint(i, 1, height) forint(j, 1, width) if(a[i][j]==1) sx=i, sy=j;
	fillchar(vis, 0);
	fillchar(pass, false);
	num=0;
	fillchar(deg, 0);
	dfs(sx, sy, k);
	
	//forint(i, 1, height) forint(j, 1, width)
		//printf("%2d%c", vis[i][j],j<width?' ':'\n');

	forint(i, 1, height) forint(j, 1, width) {
		if(a[i][j]==1 && vis[i][j]==0) return false;
		if(a[i][j]!=1 && vis[i][j]!=0) return false;
	}
	int no=0;
	forint(i, 1, num) if(deg[i]%2!=0) ++no;
	if(no>2) return false;
	return true;
}

int main() {
	scanf("%d%d", &height, &width);
	fillchar(a, 0);
	forint(i, 1, height) forint(j, 1, width) scanf("%d", &a[i][j]);
	vector<int> box;
	int sx, sy;
	forint(i, 1, height) forint(j, 1, width) if(a[i][j]==1) sx=i, sy=j;
//printf("#x\n");
	forint(i, 1, height) {
		int cur=1;
		while(cur<=width) {
			while(cur<=width && a[i][cur]!=1) ++cur;
			if(cur>width) break;
			int j=cur;
			while(j<width && a[i][j+1]==1) ++j;
			box.PB(cur-sy);
			box.PB(j-sy);
			cur=j+1;
		}
	}
//printf("#0\n");
	forint(i, 1, width) {
		int cur=1;
		while(cur<=height) {
			while(cur<=height && a[cur][i]!=1) ++cur;
			if(cur>height) break;
			int j=cur;
			while(j<height && a[j+1][i]==1) ++j;
			box.PB(cur-sx);
			box.PB(j-sx);
			cur=j+1;
		}
	}
//printf("#1\n");
	int k=0;
	forn(i, box.size()) if(box[i]!=0) k=box[i];
	if(k==0) {
		printf("-1\n");
		return 0;
	}
	forn(i, box.size()) if(box[i]!=0) k=gcd(k, box[i]);
	if(k<0) k=-k;
	if(k<=1) {
		printf("-1\n");
		return 0;
	}
//printf("#2 k=%d\n",k);
	if(check(k)) {
		forint(i, 2, k) if(k%i==0) printf("%d ", i);
		printf("\n");
	} else
		printf("-1\n");

	return 0;
}