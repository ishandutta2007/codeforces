#include <bits/stdc++.h>
#define N 5050
using namespace std;

inline void ut(int &x,int y) {x>y?x=y:0;}
inline int rd() {int r;scanf("%d",&r);return r;}

int F[N][N/2][3],n,h[N],ans[N];

int main() {
	n = rd();
	for (int i=1;i<=n;i++) h[i] = rd();
	h[0] = h[n+1] = -(1<<29);
	memset(F,127/3,sizeof(F));
	F[0][0][0] = 0;
	int k = (n+1) / 2;
	for (int i=0;i<=n;i++) {
		for (int j=0;j<=k;j++) {
			ut(F[i+1][j][0], F[i][j][0]);
			if (j!=k)
				ut(F[i+1][j+1][1], F[i][j][0] + max(0, h[i]-h[i+1]+1)); 	
			
			ut(F[i+1][j][2], F[i][j][1] + max(0, h[i+1]-h[i]+1));
			
			ut(F[i+1][j][0], F[i][j][2]);
			if (j!=k) ut(F[i+1][j+1][1], F[i][j][2] + max(0, min(h[i], h[i-1]-1)-h[i+1]+1));
		}
	}
	for (int i=1;i<=k;i++) ans[i] = min(F[n+1][i][0], F[n+1][i][2]);
	for (int i=1;i<=k;i++) printf("%d%c",ans[i],i==k ? '\n':' ');
	return 0;
}