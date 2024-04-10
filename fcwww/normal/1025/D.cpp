#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 705
int mp[N][N],n,a[N];
bool f[N][N][2];
int main() {
	scanf("%d",&n);
	int i,j,l,k;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=0;i<=n;i++) for(j=i+1;j<=n+1;j++) mp[i][j]=__gcd(a[i],a[j])>1;
	for(i=1;i<=n;i++) {
		if(i==1||mp[i-1][i]) f[i][i][0]=1;
		if(i==n||mp[i][i+1]) f[i][i][1]=1;
		f[i][i-1][0]=f[i][i-1][1]=1;
	}
	f[n+1][n][0]=f[n+1][n][1]=1;
	for(l=2;l<=n;l++) {
		for(i=1;i<=n-l+1;i++) {
			j=i+l-1;
			for(k=i;k<=j;k++) {
				if(f[i][k-1][1]&&f[k+1][j][0]) {
					if(mp[i-1][k]) f[i][j][0]=1;
					if(mp[k][j+1]) f[i][j][1]=1;
				}
			}
		}
	}
	puts((f[1][n][0]||f[1][n][1])?"Yes":"No");
}