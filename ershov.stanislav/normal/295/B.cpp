#include <cstdio>
#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;

#define maxn 510

int n, aa[maxn][maxn], a[maxn][maxn], x[maxn];
long long sum, best[maxn][maxn], ans[maxn];

int main() {
	cin >> n;
	for (int i=0; i<n; i++) for (int j=0; j<n; j++) cin >> aa[i][j];
	for (int i=0; i<n; i++) cin >> x[i], x[i]--;
	for (int i=0; i<n; i++) for (int j=0; j<n; j++) a[i][j]=aa[x[i]][x[j]];
	for (int i=n-1; i>=0; i--) {
		for (int j=n-1; j>i; j--)
			best[i][j]=a[i][j], best[j][i]=a[j][i], sum+=a[i][j]+a[j][i];
		for (int j=n-1; j>i; j--) for (int k=n-1; k>i; k--) {
			if (best[i][k]>best[i][j]+best[j][k]) sum+=best[i][j]+best[j][k]-best[i][k], best[i][k]=best[i][j]+best[j][k];
			if (best[k][i]>best[j][i]+best[k][j]) sum+=best[j][i]+best[k][j]-best[k][i], best[k][i]=best[j][i]+best[k][j];
		}
		for (int j=n-1; j>i; j--) for (int k=n-1; k>i; k--)
			if (best[j][k]>best[j][i]+best[i][k]) sum+=best[j][i]+best[i][k]-best[j][k], best[j][k]=best[j][i]+best[i][k];
		ans[i]=sum;
	}
	for (int i=0; i<n; i++) cout << ans[i] << ' ';
	return 0;
}