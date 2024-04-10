#include <bits/stdc++.h>
#define N 5050
using namespace std;
int F[N][N],ans[N][N],a[N],n,q,L,R;
inline int rd() {int r;scanf("%d",&r);return r;}
int main() {
	n = rd();
	for (int i=1;i<=n;i++) a[i] = rd();

	for (int i=1;i<=n;i++) ans[i][i] = F[i][i] = a[i];
	for (int len=2;len<=n;len++)
		for (int i=1;i<=n;i++) {
			int j = i+len-1;
			F[i][j] = F[i][j-1] ^ F[i+1][j];
			ans[i][j] = max(ans[i][j-1], ans[i+1][j]);
			ans[i][j] = max(ans[i][j], F[i][j]);
		}

	q = rd();
	while (q--) {
		L = rd(), R = rd();
		printf("%d\n",ans[L][R]);
	}
	return 0;
}