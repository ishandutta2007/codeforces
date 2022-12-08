#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define forint(i, a, b) for(int i=(int)(a); i<=(int)(b); ++i)
#define forintdown(i, a, b) for(int i=(int)(a); i>=(int)(b); --i)
#define forn(i, n) forint(i, 0, (n)-1)
#define forndown(i, n) forintdown(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPI;
#define MP make_pair
#define PB push_back
#define fi first
#define se second
void upt(int &x, int y) {
	if(y>x) x=y;
}

const int MAXN=2500+10;
const int MAXE=MAXN*10;
const int INFI=int(1E9);

int g[MAXN], g_lnk[MAXE*2], g_nxt[MAXE*2];
int n;

int f[MAXN][MAXN][3][3];
int tmp[MAXN][3][3];
int color[MAXN], up[MAXN];
int size[MAXN];

void trans1(int x, int y) {
	forint(a, 0, size[x]+size[y])
		forint(cx, 0, 2)
			forint(co, 0, 2)
				tmp[a][cx][co]=-INFI;
	if(up[y]==0) {
		forint(a, 0, size[x]) forint(cx, 0, 2) forint(co, 0, 2)
			forint(a2, 0, size[y]) forint(cy, 0, 2)
				if(cx+cy!=3)
					upt(tmp[a+a2][cx][co], f[x][a][cx][co]+f[y][a2][cy][0]);
	} else if(up[y]==x) {
		forint(a, 0, size[x]) forint(cx, 0, 2) forint(co, 0, 2)
			forint(a2, 0, size[y]) forint(cy, 0, 2)
				if(cx+cy!=3)
					upt(tmp[a+a2][cx][co], f[x][a][cx][co]+f[y][a2][cy][cx]);
	} else if(up[y]!=x) {
		forint(a, 0, size[x]) forint(cx, 0, 2) forint(co, 0, 2)
			forint(a2, 0, size[y]) forint(cy, 0, 2)
				if(cx+cy!=3)
					upt(tmp[a+a2][cx][co], f[x][a][cx][0]+f[y][a2][cy][co]);
	}
	forint(a, 0, size[x]+size[y])
		forint(cx, 0, 2)
			forint(co, 0, 2)
				f[x][a][cx][co]=tmp[a][cx][co];
}

void trans2(int x) {
	forint(a, 0, size[x])
		forint(cx, 0, 2) forint(co, 1, 2)
			if(cx+co!=3)
				f[x][a][cx][co]=f[x][a][cx][0];
}

void dfs(int x, int fa) {
	color[x]=1; up[x]=0;
	size[x]=1;
	f[x][0][0][0]=0;
	f[x][0][2][0]=1;
	f[x][1][1][0]=0;
	for(int e=g[x]; e; e=g_nxt[e]) {
		int y=g_lnk[e];
		if(y==fa || color[y]==2) continue;
		if(color[y]==0) {
			dfs(y, x);
			trans1(x, y);
			size[x]+=size[y];
			if(up[y]>0 && up[y]!=x)
				up[x]=up[y];
		} else {
			trans2(x);
			up[x]=y;
		}
	}
	/*
	forint(a, 0, size[x]) forint(cx, 0, 2) forint(cy, 0, 2)
		if(f[x][a][cx][cy]>=0)
			printf("f[%d,%d,%d,%d]=%d\n",x,a,cx,cy,f[x][a][cx][cy]); printf("\n");
			*/
	color[x]=2;
}

int main() {
	//double sz=(sizeof(f)+sizeof(g_lnk)+sizeof(g_nxt))/1024./1024.;
	//cout<<sz<<endl;

	int m; cin>>n>>m;
	fillchar(g, 0);
	for(int e=0; m--; ) {
		int a, b; cin>>a>>b;
		g_lnk[++e]=b, g_nxt[e]=g[a], g[a]=e;
		g_lnk[++e]=a, g_nxt[e]=g[b], g[b]=e;
	}

	int root=1;

	fillchar(color, 0);
	fillchar(f, 200);
	dfs(root, 0);

	forint(i, 0, n) {
		int ans=-INFI;
		forint(cx, 0, 2) upt(ans, f[root][i][cx][0]);
		cout<<ans<<" ";
	}
	cout<<endl;

	return 0;
}