#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define _ (size_t)
#define all(a) a.begin(), a.end()
#define forint(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define forintdown(i, a, b) for(int i=int(a); i>=int(b); --i)
#define forn(i, n) forint(i, 0, (n)-1)
#define forndown(i, n) forintdown(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define fi first
#define se second
#define PB push_back
#define MP make_pair
typedef long long LL;
typedef pair<double,double> PDD;
typedef pair<int,int> PII;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<PII> VPI;
template<class T> void setmax(T &a, T b) { if(b>a) a=b; }
template<class T> void setmin(T &a, T b) { if(b<a) a=b; }
template<class T> T gcd(T a, T b) { return b==0?a:gcd(b,a%b); }


// ------------------------ template ends here ------------------------ //
const int MAXN=2222;
const int dx[4]={0, 1, 0, -1};
const int dy[4]={1, 0, -1, 0};
const char dc[4]={'<', '^', '>', 'v'};

char g[MAXN][MAXN];
int n, m;

int deg(int x, int y) {
	if(g[x][y]!='.') return 0;
	int d=0;
	forn(i, 4) if(g[x+dx[i]][y+dy[i]]=='.')
		++d;
	return d;
}

void upt(queue<PII> &q, int x, int y) {
	forn(i, 4) if(deg(x+dx[i], y+dy[i])==1)
		q.push(MP(x+dx[i], y+dy[i]));
}

int main() {
	fillchar(g, '*');
	scanf("%d%d", &n,&m);
	forint(i, 1, n) scanf("%s", g[i]+1);

	queue<PII> q;
	forint(i, 1, n) forint(j, 1, m)
		if(deg(i, j)==1)
			q.push(MP(i, j));
	while(!q.empty()) {
		PII a=q.front(); q.pop();
		if(deg(a.fi, a.se)!=1)
			continue;
		int x=a.fi, y=a.se;
		forn(i, 4) if(g[x+dx[i]][y+dy[i]]=='.') {
			g[x][y]=dc[i];
			g[x+dx[i]][y+dy[i]]=dc[(i+2)%4];
			upt(q, x, y);
			upt(q, x+dx[i], y+dy[i]);
			break;
		}
	}
	bool ok=true;
	forint(i, 1, n) forint(j, 1, m)
		if(g[i][j]=='.')
			ok=false;
	if(ok) {
		forint(i, 1, n) printf("%s\n", g[i]+1);
	} else
		printf("Not unique\n");
	
	return 0;
}