#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double f2;
#define N 100050
int f[N][3][3],n,a[N],t[5]={0,-1,1};
int main() {
	int i,j,k,l;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n<=2) {
		puts("0"); return 0;
	}
	memset(f,0x3f,sizeof(f));
	for(i=0;i<3;i++) {
		for(j=0;j<3;j++) {
			f[2][i][j]=(i!=0)+(j!=0);
		}
	}
	for(i=3;i<=n;i++) {
		for(j=0;j<3;j++) {
			for(k=0;k<3;k++) {
				for(l=0;l<3;l++) {
					if(a[i-1]+t[k]-a[i-2]-t[j]==a[i]+t[l]-a[i-1]-t[k]) {
						f[i][k][l]=min(f[i][k][l],f[i-1][j][k]+(l!=0));
					}
				}
			}
		}
	}
	int ans=1<<30;
	for(i=0;i<3;i++) for(j=0;j<3;j++) ans=min(ans,f[n][i][j]);
	if(ans>n) ans=-1;
	printf("%d\n",ans);
}