#include <bits/stdc++.h>
#define N 50050
using namespace std;

int n,p,tp,tot,w[60],ys[N],a[N],b[N],ans[N];
bool F[35][35][N][2];
inline int rd() {int r;scanf("%d",&r);return r;}

inline int qp(int a,int b) {
	int ret = 1;
	while (b) {
		if (b&1) ret = 1LL * ret * a % p;
		b >>= 1, a = 1LL * a * a % p;
	}
	return ret;
}

void o(int x,int y,int z,int c) {
	if (!x) return ;
	if (F[x-1][y][z][c]) {
		o(x-1,y,z,c);
		return ;
	}

	ans[++tot] = ys[x];
	for (int i=0;i<p;i++)
		if ((i*w[ b[x] ]+b[x])%p == z) {
			if (F[x-1][y^b[x]][i][0]) {
				o(x-1,y^b[x],i,0);
				return ;
			}
			if (F[x-1][y^b[x]][i][1]) {
				o(x-1,y^b[x],i,1);
				return ;
			}
		}
}

int calc(int x) {
	int ret = 10;
	while (x>=10) x /= 10, ret*=10;
	return ret;
}

int main() {
	n = rd(), p = rd();
	for (int i=1;i<=n;i++) a[i] = rd();

	for (int i=1;i<=n;i++) if (a[i]<32) b[++tp] = a[i], ys[tp] = i;
	for (int i=0;i<=32;i++) w[i] = calc(i);

	F[0][0][0][0] = 1;
	for (int _=0;_<tp;_++) {
		int x = b[_+1];
		for (int i=0;i<=32;i++) {
			for (int j=0;j<p;j++) {
				if (F[_][i][j][1]) {
					F[_+1][i^x][(j*w[x]+x)%p][1] = 1;
					F[_+1][i][j][1] = 1;
				}
				if (F[_][i][j][0]) {
					F[_+1][i^x][(j*w[x]+x)%p][1] = 1;
					F[_+1][i][j][0] = 1;
				}
			}
		}
	}

	for (int _=1;_<=tp;_++) if (F[_][0][0][1]) {
		puts("Yes");
		o(_,0,0,1);
		printf("%d\n",tot);
		for (int _=tot;_>=1;_--) printf("%d%c",ans[_],_==1?'\n':' ');
		return 0;
	}
	puts("No");
	return 0;
}