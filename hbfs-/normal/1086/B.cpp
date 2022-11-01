#include <bits/stdc++.h>
#define N 2000500
using namespace std;

int d[N],n,m,tot;
inline int rd() {int r;scanf("%d",&r);return r;}
int main() {
	n = rd(), m = rd();
	for (int i=1;i<n;i++) {
		d[rd()]++;
		d[rd()]++;
	}

	for (int i=1;i<=n;i++) if (d[i] == 1) ++tot;
	printf("%.10f\n",2.0 * (double)m / (double)tot); 
	
	return 0;
}