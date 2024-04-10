#include <bits/stdc++.h>
#define N 200050
#define LOG 20
using namespace std;
inline int rd() {int r;scanf("%d",&r);return r;}
int n,m,q,a[N],b[N],pre[N],cur[N],ans[N];
int J[N][LOG+2];
int nxt[N];
int main() {
	n = rd(), m = rd(), q = rd();
	for (int i=1;i<=n;i++) a[i] = rd();
	for (int i=1;i<=m;i++) b[i] = rd();
	
	for (int i=2;i<=n;i++) pre[ a[i] ] = a[i-1];
	
	
	
	
	pre[ a[1] ] = a[n];
	
	for (int i=1;i<=m;i++) {
		J[i][0] = cur[ pre[ b[i] ] ];
		for (int k=1;k<LOG;k++) J[i][k] = J[ J[i][k-1] ][k-1];
		
		cur[ b[i] ] = i;
		
		int t = i;
		for (int k=0;k<LOG;k++) if (((n-1)>>k) & 1) t = J[t][k];
		ans[i] = max(ans[i-1], t);
	}
	
	while (q--) {
		int l = rd(), r = rd();
		if (ans[r] >= l) putchar('1'); else putchar('0');
	}
	
	return 0;
}