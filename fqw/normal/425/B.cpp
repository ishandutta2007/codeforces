#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <vector>
using namespace std;

#define forint(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define forintdown(i, a, b) for(int i=int(a); i>=int(b); --i)
#define forn(i, n) forint(i, 0, (n)-1)
#define forndown(i, n) forintdown(i, (n)-1, 0)
#define fi first
#define se second
#define PB push_back
#define MP make_pair
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<PII> VPI;
typedef pair<double,double> PDD;

int a[111][111];
int n, m, k;
int ans;

int c[111][2];
int cv[111];

void dfs(int cj, int ct) {
	if(ct>k) return;
	if(cj>m) {
		int tmp=0;
		forint(i, 1, n) {
			int z[2]={0,0};
			forint(j, 1, m) {
				if(a[i][j]==cv[j]) ++z[0]; else ++z[1];
			}
			tmp+=min(z[0], z[1]);
		}
		if(tmp<=k) ans=min(ans, tmp);
		return;
	}
	forn(v, 2) {
		cv[cj]=v; 
		dfs(cj+1, ct+c[cj][v]);
	}
}

int main() {
	scanf("%d%d%d",&n,&m,&k); forint(i, 1, n) forint(j, 1, m) scanf("%d", &a[i][j]);
	int maxval=ans=1<<30;
	int h=min(n, 11);
	forn(st, 1<<h) {
		memset(c, 0, sizeof(c));
		forint(i, 1, h) forint(j, 1, m) {
			int x=a[i][j]; if(st&(1<<(i-1))) x^=1;
			++c[j][x^1];
		}
		dfs(1, 0);
	}
	if(ans>k) ans=-1;
	printf("%d\n", ans);

	return 0;
}