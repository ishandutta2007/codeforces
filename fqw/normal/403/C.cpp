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

const int MAXN=2020;

int g[MAXN][MAXN];
int n;

int low[MAXN], dfn[MAXN], stack[MAXN], top, tt;
int belong[MAXN], cur;
void dfs(int x) {
	low[x]=dfn[x]=++tt;
	stack[++top]=x;
	belong[x]=-1;
	for(int y=1; y<=n; ++y) if(g[x][y]>0) {
		if(belong[y]<0) low[x]=min(low[x], dfn[y]);
		if(belong[y]==0) {
			dfs(y);
			low[x]=min(low[x], low[y]);
		}
	}
	if(low[x]==dfn[x]) {
		++cur;
		do belong[stack[top--]]=cur; while(stack[top+1]!=x);
	}
}

int main() {
	scanf("%d", &n);
	forint(i, 1, n) forint(j, 1, n) scanf("%d", &g[i][j]);

	top=tt=cur=0;
	fillchar(belong, 0);
	dfs(1);

	bool flag=true;
	forint(i, 1, n) if(belong[i]!=belong[1]) flag=false;
	cout<<(flag?"YES":"NO")<<endl;
	return 0;
}