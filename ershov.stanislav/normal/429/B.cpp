#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int a[2011][2011], n, m, b1[2011][2011], b2[2011][2011], b3[2011][2011], b4[2011][2011], ans1[2011][2011], a2[2011][2011], ans;

int main() {
	scanf("%d%d", &n, &m);
	for (int i=0; i<n; i++) for (int j=0; j<m; j++) scanf("%d", &a[i][j]), a2[i][j]=a[i][j];
	b1[0][0]=a[0][0];
	b2[n-1][0]=a[n-1][0];
	for (int i=1; i<n; i++) b1[i][0]=b1[i-1][0]+a[i][0];
	for (int i=1; i<m; i++) b1[0][i]=b1[0][i-1]+a[0][i];
	for (int ij=0; ij<2*n-1; ij++) for (int i=1; i<ij; i++) b1[i][ij-i]=max(b1[i][ij-i-1], b1[i-1][ij-i])+a[i][ij-i];
	for (int i=1; i<n; i++) b2[n-1-i][0]=b2[n-1-i+1][0]+a[n-1-i][0];
	for (int i=1; i<m; i++) b2[n-1][i]=b2[n-1][i-1]+a[n-1][i];
	for (int ij=0; ij<2*n-1; ij++) for (int i=1; i<ij; i++) b2[n-1-i][ij-i]=max(b2[n-1-i][ij-i-1], b2[n-1-(i-1)][ij-i])+a[n-1-i][ij-i];
	
	for (int i=0; i<n; i++) for (int j=0; j<m; j++) a[i][j]=a2[n-1-i][m-1-j];
	b3[0][0]=a[0][0];
	b4[n-1][0]=a[n-1][0];
	for (int i=1; i<n; i++) b3[i][0]=b3[i-1][0]+a[i][0];
	for (int i=1; i<m; i++) b3[0][i]=b3[0][i-1]+a[0][i];
	for (int ij=0; ij<2*n-1; ij++) for (int i=1; i<ij; i++) b3[i][ij-i]=max(b3[i][ij-i-1], b3[i-1][ij-i])+a[i][ij-i];
	for (int i=1; i<n; i++) b4[n-1-i][0]=b4[n-1-i+1][0]+a[n-1-i][0];
	for (int i=1; i<m; i++) b4[n-1][i]=b4[n-1][i-1]+a[n-1][i];
	for (int ij=0; ij<2*n-1; ij++) for (int i=1; i<ij; i++) b4[n-1-i][ij-i]=max(b4[n-1-i][ij-i-1], b4[n-1-(i-1)][ij-i])+a[n-1-i][ij-i];
	for (int i=1; i<n-1; i++) for (int j=1; j<m-1; j++) {
		int ans2=0;
		ans2=max(ans2, b1[i-1][j]+b2[i][j-1]+b3[n-1-(i+1)][m-1-j]+b4[n-1-i][m-1-(j+1)]);
		ans2=max(ans2, b1[i][j-1]+b2[i+1][j]+b3[n-1-i][m-1-(j+1)]+b4[n-1-(i-1)][m-1-j]);
		ans=max(ans, ans2);
	}
	cout << ans;
    return 0;
}