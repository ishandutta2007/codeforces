#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <vector>
using namespace std;
#define N 100050
#define mod 998244353
int n,a[N];
int f[N][201][2],s[201][2];
inline void upd(int &x,int y) {
	x=x+y; if(x>=mod) x-=mod;
}
int main() {
	scanf("%d",&n);
	int i,j,k;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	if(a[1]==-1) for(i=1;i<=200;i++) f[1][i][0]=1;
	else f[1][a[1]][0]=1;
	for(i=1;i<=200;i++) s[i][0]=s[i-1][0]+f[1][i][0];
	for(i=2;i<=n;i++) {
		if(a[i]==-1) {
			for(j=1;j<=200;j++) {
				f[i][j][0]=(s[j-1][0]+s[j-1][1])%mod;
				f[i][j][1]=((s[200][1]-s[j-1][1]+f[i-1][j][0])%mod+mod)%mod;
			}
		}else {
			j=a[i];
			f[i][j][0]=(s[j-1][0]+s[j-1][1])%mod;
			f[i][j][1]=((s[200][1]-s[j-1][1]+f[i-1][j][0])%mod+mod)%mod;	
		}
		memset(s,0,sizeof(s));
		for(j=1;j<=200;j++) for(k=0;k<2;k++) s[j][k]=(s[j-1][k]+f[i][j][k])%mod;
	}
	printf("%d\n",s[200][1]);
}