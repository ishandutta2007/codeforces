#include <bits/stdc++.h>
#define N 5050
#define mod 1000000007
using namespace std;
int n,a,b,k,F[N][N];
inline int rd() {int r;scanf("%d",&r);return r;}
void inc(int &x,int y) {x=(x+y)%mod;}
int main() {
	n = rd(), a = rd(), b = rd(), k = rd();
	F[0][a] = 1;
	if (a<b) {
		for (int _=1;_<=k;_++) {
			int T = 0, sum = 0;
			for (int i=1;i<b;i++) {
				while (abs(i-(T+1)) < abs(b-(T+1)))
					inc(sum, F[_-1][T+1]), T++;
				F[_][i] = (sum - F[_-1][i] + mod) % mod;
			}
		}
	} else {
		for (int _=1;_<=k;_++) {
			int T = n+1, sum = 0;
			for (int i=n;i>b;i--) {
				while (abs(i-(T-1)) < abs(b-(T-1)))
					inc(sum, F[_-1][T-1]), T--;
				F[_][i] = (sum - F[_-1][i] + mod) % mod;
			}
		}
	}
	
	int ans = 0;
	for (int _=1;_<=n;_++) inc(ans, F[k][_]);
	cout << ans << endl;
	return 0;
}