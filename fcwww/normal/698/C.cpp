#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <set>
#include <cstdlib>
#include <cmath>
using namespace std;
#define N 25
typedef double f2;
int n,K,inq[N];
f2 p[N],ans[N],sp[1<<20],rp[N];
f2 f[1<<20],Div[1<<20];
int tot[1<<20];
int main() {
	scanf("%d%d",&n,&K);
	int i,cnt=0,j;
	for(i=1;i<=n;i++) scanf("%lf",&p[i]),rp[i]=p[i]*100;
	for(i=1;i<=n;i++) {
		if(abs(p[i])>1e-6) cnt++;
	}
	if(cnt<=K) {
		for(i=1;i<=n;i++) printf("%.6f ",(p[i]>0)?1.0:0.0); puts(""); return 0;
	}
	if(K==1) {
		for(i=1;i<=n;i++) printf("%.6f ",p[i]); puts(""); return 0;
	}
	int mask=(1<<n)-1;

	for(i=0;i<=mask;i++) {
		for(j=1;j<=n;j++) {
			if(i&(1<<(j-1))) {
				sp[i]+=p[j];
			}
		}
	}
	f[0]=1;
	for(i=0;i<mask;i++) {
		tot[i]=tot[i>>1]+(i&1);
		if(tot[i]!=K) {
			f[i]/=(1-sp[i]);
		}
		for(j=1;j<=n;j++) {
			if(i&(1<<(j-1))) continue;
			else f[i|(1<<(j-1))]+=f[i]*p[j];
		}
	}
	for(i=0;i<=mask;i++) {
		int cnt=0;
		for(j=1;j<=n;j++) if(i&(1<<(j-1))) cnt++;
		if(cnt!=K) continue;
		for(j=1;j<=n;j++) if(i&(1<<(j-1))) ans[j]+=f[i];
	}
	for(i=1;i<=n;i++) printf("%.6f ",ans[i]); 
	puts("");
	return 0;
}