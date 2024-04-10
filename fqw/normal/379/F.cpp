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

const int MAXN=5*100000*2+1000;
const int MAXLog=21;

VI childs[MAXN];
int op[MAXN];
int n, q;

int up[MAXN][MAXLog];
int dep[MAXN];

void dfs(int x, int fa) {
	up[x][0]=fa;
	dep[x]=dep[fa]+1;
	for(int i=0; up[x][i]>0; ++i)
		up[x][i+1]=up[up[x][i]][i];
	forn(i, childs[x].size())
		dfs(childs[x][i], x);
}

int lca(int a, int b) {
	for(int i=MAXLog-1; i>=0; --i) {
		if(dep[up[a][i]]>=dep[b]) a=up[a][i];
		if(dep[up[b][i]]>=dep[a]) b=up[b][i];
	}
	for(int i=MAXLog-1; i>=0; --i)
		if(up[a][i]!=up[b][i])
			a=up[a][i], b=up[b][i];
	if(a!=b) a=up[a][0];
	return a;
}

int dis(int a, int b) {
	return dep[a]+dep[b]-2*dep[lca(a,b)];
}

int main() {
	scanf("%d", &q);
	n=4;
	childs[1].clear();
	forint(i, 2, n) {
		childs[1].PB(i);
		childs[i].clear();
	}
	forint(i, 1, q) {
		scanf("%d", &op[i]);
		childs[op[i]].PB(++n);
		childs[op[i]].PB(++n);
		op[i]=n;
	}
	dfs(1, 0);
	forint(i, 1, n) if(up[i][0]>0)
		childs[i].PB(up[i][0]);
	int w=1, c1=1, c2=1;
	forint(i, 1, q) {
		int x=op[i];
		int d1=dis(c1, x);
		int d2=dis(c2, x);
		//printf("\nx=%d\n",x);
		//printf("c1=%d c2=%d d1=%d d2=%d w=%d\n",c1,c2,d1,d2,w);
		if(d1>w && d2>w) {
			if(c1==c2) {
				forn(i, childs[c1].size()) {
					int y=childs[c1][i];
					if(dis(y, x)<=w) {
						c1=y; break;
					}
				}
			} else {
				if(d1>d2) c1=c2;
					else c2=c1;
				++w;
			}
		}
		int t=w*2; if(c1!=c2) ++t;
		//printf("c1=%d c2=%d w=%d t=%d\n",c1,c2,w,t);
		printf("%d\n", t);
	}
	return 0;
}