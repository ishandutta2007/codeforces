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

const int MAXN=22;
const int MAXS=1<<20;

char g[MAXN][MAXN];
int px[MAXN][MAXN], py[MAXN][MAXN];
int ix[MAXN*2][MAXN], iy[MAXN*2][MAXN], in[MAXN*2];
bool valid[MAXN*2][MAXS];
int f[MAXS], f0[MAXS];
int n;

int main() {
	scanf("%d", &n);
	forint(i, 1, n) scanf("%s", g[i]+1);
	fillchar(px, 0);
	forint(i, 1, n) forint(j, 1, i) {
		px[i-j+1][j]=i;
		py[i-j+1][j]=j-1;
	}
	forint(j, 2, n) forintdown(i, n, j) {
		px[i][j+n-i]=n+j-1;
		py[i][j+n-i]=n-i;
	}
	fillchar(in, 0);
	forint(i, 1, n) forint(j, 1, n) {
		++in[px[i][j]];
		ix[px[i][j]][py[i][j]]=i;
		iy[px[i][j]][py[i][j]]=j;
	}
	/*
	forint(i, 1, n) {
		forint(j, 1, n) printf("%d ", px[i][j]);
		printf("\n");
	}
	printf("\n");
	forint(i, 1, n) {
		forint(j, 1, n) printf("%d ", py[i][j]);
		printf("\n");
	}
	*/
	fillchar(valid, false);
	valid[1][1]=true;
	forint(i, 2, 2*n-1) forn(st, 1<<in[i-1]) if(valid[i-1][st]) {
		vector<pair<char,int> > lst;
		forn(j, in[i]) {
			int x=ix[i][j], y=iy[i][j];
			bool flag=false;
			if(px[x-1][y]>0 && (st&(1<<py[x-1][y]))>0) flag=true;
			if(px[x][y-1]>0 && (st&(1<<py[x][y-1]))>0) flag=true;
			if(flag) lst.PB(MP(g[x][y], 1<<py[x][y]));
		}
		sort(lst.begin(), lst.end());
		for(int s=0, t=0; s<(int)lst.size(); s=t) {
			int msk=0;
			for(t=s; t<(int)lst.size() && lst[t].first==lst[s].first; ++t)
				msk|=lst[t].second;
			valid[i][msk]=true;
		}
	}

	fillchar(f, 50);
	f[1]=0;
	if(g[n][n]=='a') ++f[1];
	if(g[n][n]=='b') --f[1];
	int FIR=1;
	forintdown(i, 2*n-1, 2) {
		memmove(f0, f, sizeof(f));
		if(i%2==FIR) fillchar(f, 200); else fillchar(f, 50);
		forn(st, 1<<in[i-1]) if(valid[i-1][st]) {
			vector<pair<char,int> > lst;
			forn(j, in[i]) {
				int x=ix[i][j], y=iy[i][j];
				bool flag=false;
				if(px[x-1][y]>0 && (st&(1<<py[x-1][y]))>0) flag=true;
				if(px[x][y-1]>0 && (st&(1<<py[x][y-1]))>0) flag=true;
				if(flag) lst.PB(MP(g[x][y], 1<<py[x][y]));
			}
			sort(lst.begin(), lst.end());
			for(int s=0, t=0; s<(int)lst.size(); s=t) {
				int msk=0;
				for(t=s; t<(int)lst.size() && lst[t].first==lst[s].first; ++t)
					msk|=lst[t].second;
				// do it
				//printf("msk %d ->%d\n", msk,f0[msk]);
				if(i%2==FIR) setmax(f[st], f0[msk]);
					else setmin(f[st], f0[msk]);
			}
			forn(j, in[i-1]) if(st&(1<<j)) {
				int x=ix[i-1][j], y=iy[i-1][j];
				if(g[x][y]=='a') ++f[st];
				if(g[x][y]=='b') --f[st];
				break;
			}
			//printf("f[%d][%d]=%d\n", i-1,st,f[st]);
		}
	}
	if(f[1]>0) printf("FIRST\n");
	else if(f[1]<0) printf("SECOND\n");
	else printf("DRAW\n");

	return 0;
}