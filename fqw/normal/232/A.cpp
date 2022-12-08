#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;

bool g[111][111];

int main() {
	int k; scanf("%d", &k);
	memset(g, 0, sizeof(g));
	int n=0;
	while((n+1)*n*(n-1)/6<=k) ++n;
	k-=n*(n-1)*(n-2)/6;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			g[i][j]=(i!=j);
	while(k>0) {
		int m=0;
		while((m+1)*m/2<=k && m<n) ++m;
		//printf("m=%d k=%d\n",m,k);
		if(m>=2) {
			while((m-1)*m/2<=k) {
				for(int i=1; i<=m; ++i) g[i][n+1]=g[n+1][i]=true;
				++n;
				k-=m*(m-1)/2;
			}
		} else break;
	}
	while(k>0) {
		g[1][n+1]=g[n+1][1]=true;
		g[2][n+1]=g[n+1][2]=true;
		++n;
		--k;
	}
	printf("%d\n", n);
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) printf("%d", g[i][j]?1:0);
		printf("\n");
	}
	/*
	int cnt=0;
	for(int i=1; i<=n; ++i)
		for(int j=i+1; j<=n; ++j)
			for(int k=j+1; k<=n; ++k)
				if(g[i][j] && g[j][k] && g[k][i])
					++cnt;
	printf("cnt=%d\n", cnt);
	*/
	return 0;
}