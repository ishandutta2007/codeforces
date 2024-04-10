#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
using namespace std;
int n,m,ans[5050][5050],a[5050],f[5050][5050];
int main() {
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		ans[i][i]=f[i][i]=a[i];
	}
	for(i=2;i<=n;i++) {
		for(j=1;j+i-1<=n;j++) {
			f[j][j+i-1]=max(f[j][j+i-2],f[j+1][j+i-1]);
			ans[j][j+i-1]=(ans[j][j+i-2]^ans[j+1][j+i-1]);
			f[j][j+i-1]=max(f[j][j+i-1],ans[j][j+i-1]);
		}
	}
	scanf("%d",&m);
	int x,y;
	while(m--) {
		scanf("%d%d",&x,&y);
		printf("%d\n",f[x][y]);
	}
}
/////////////////////////////////////