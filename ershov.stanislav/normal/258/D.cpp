#include <iostream>
#include <iomanip>

using namespace std;
#define mod 1000000007
int n, m, a[1010], x, y;
double p[1010][1010], ans;
int main(){
	cin >> n >> m;
	for (int i=1; i<=n; i++) cin >> a[i];
	for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) p[i][j]=a[i]>a[j];
	for (int j=0; j<m; j++) {
			cin >> x >> y; p[x][y]=p[y][x]=0.5;
			for (int i=1; i<=n; i++) if (i!=x&&i!=y) p[i][x]=p[i][y]=(p[i][x]+p[i][y])/2, p[x][i]=p[y][i]=(p[x][i]+p[y][i])/2;
	}
	for (int i=1; i<=n; i++) for (int j=i+1; j<=n; j++) ans+=p[i][j];
	cout << fixed << setprecision(10) << ans;
	return 0;
}