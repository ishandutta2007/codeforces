#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back

const int MAXN=220;

int f[MAXN][MAXN*MAXN][2];
int h[MAXN];
int n, a, b;

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w", stdout);
	scanf("%d%d%d", &n, &a, &b);
	for(int i=1; i<=n; ++i) scanf("%d", h+i);
	memset(f, 50, sizeof(f));
	h[0]=0;
	int maxval=f[0][0][0];
	f[0][0][0]=f[0][0][1]=0;
	for(int i=1, s=0; i<=n; s+=h[i], ++i)
		for(int j=0; j<=s; ++j)
			for(int c1=0; c1<2; ++c1) {
				for(int c2=0; c2<2; ++c2) {
					int c=min(h[i-1],h[i]);
					int &v=f[i][j+c2*h[i]][c2];
					int t=f[i-1][j][c1];
					if(c1!=c2) t+=c;
					if(t<v) v=t;
				}
			}
	int s=0; for(int i=1; i<=n; ++i) s+=h[i];
	int l=s-a, r=b;
	int ans=maxval;
	for(int i=l; i<=r; ++i) {
		ans=min(ans, f[n][i][0]);
		ans=min(ans, f[n][i][1]);
	}
	if(ans<maxval) printf("%d\n", ans);
	else printf("-1\n");
	return 0;
}