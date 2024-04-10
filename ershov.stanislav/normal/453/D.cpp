#include <iostream>
#include <cstdio>

using namespace std;

int n, m, p, d[1<<20][21], a;
long long b[21][70], c[21][70], t, bb[21], ans[1<<20], cc[30][30];

int main() {
	cin >> m >> t >> p;
	n=1<<m;
	
	cc[0][0]=1;
	for (int i=1; i<25; i++) for (int j=0; j<=i; j++) cc[i][j]=(cc[i-1][j]+(j?cc[i-1][j-1]:0))%p;
	
	for (int i=0; i<n; i++) scanf("%d", &d[i][0]);
	for (int i=0; i<=m; i++) scanf("%d", &a), b[i][0]=a;
	for (int i=1; i<70; i++) for (int j=0; j<=m; j++) for (int k=0; k<=j; k++) for (int kk=0; kk+j<=m; kk++)
		b[j][i]=(b[j][i]+    ((((b[k+kk][i-1]*b[kk+j-k][i-1])%p)*cc[j][k])%p)*cc[m-j][kk]    )%p;
	
	if (!(t&1)) c[0][0]=1;
	else for (int i=0; i<=m; i++) c[i][0]=b[i][0];
	for (int i=1; i<62; i++) {
		if (!(t&(1ll<<i))) for (int j=0; j<=m; j++) c[j][i]=c[j][i-1];
		else for (int j=0; j<=m; j++) for (int k=0; k<=j; k++) for (int kk=0; kk+j<=m; kk++)
				c[j][i]=(c[j][i]+    ((((c[k+kk][i-1]*b[kk+j-k][i])%p)*cc[j][k])%p)*cc[m-j][kk]    )%p;
	}
	
	for (int i=0; i<m; i++) for (int j=min(m, i+1); j>=1; j--) for (int k=0; k<n; k++) d[k][j]=(d[k][j]+d[k^(1<<i)][j-1])%p;
	for (int i=0; i<n; i++) for (int j=0; j<21; j++) ans[i]=(ans[i]+c[j][61]*d[i][j])%p;
	for (int i=0; i<n; i++) printf("%d\n", (int)ans[i]);
	return 0;
}