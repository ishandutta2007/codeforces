#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 5005
typedef long long ll;
int n,a[N];
ll f[N][N>>1][2];
int main() {
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	int lim=(n+1)>>1;
	memset(f,0x3f,sizeof(f));
	f[0][0][0]=0;
	f[1][0][0]=f[1][1][1]=0;
	for(i=2;i<=n;i++) {
		f[i][0][0]=0;
		for(j=1;j<=lim;j++) {
			f[i][j][1]=min(f[i-1][j-1][0]+max(0,a[i-1]-a[i]+1),
							f[i-2][j-1][1]+max(0,a[i-1]-min(a[i-2],a[i])+1));
			f[i][j][0]=min(f[i-1][j][0],f[i-1][j][1]+max(0,a[i]-a[i-1]+1));
		}
	}
	for(i=1;i<=lim;i++) printf("%lld ",min(f[n][i][0],f[n][i][1]));
	return 0;
}