#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 100050
typedef long long ll;
int h[N],n,K,f[N];
int dp[550][5050],c[N];
ll ans;
void upd(int &x,int y) {
	x=x>y?x:y;
}
int main() {
	scanf("%d%d",&n,&K);
	int i,x;
	for(i=1;i<=n*K;i++) scanf("%d",&x),c[x]++;
	for(i=1;i<=n;i++) scanf("%d",&f[i]);
	for(i=1;i<=K;i++) scanf("%d",&h[i]);
	sort(f+1,f+n+1);
	int j,k,l,p;
	for(i=j=1;i<=n;i=j) {
		for(j=i;f[i]==f[j];j++) ;
		int len=j-i;
		for(k=0;k<=len;k++) for(l=0;l<=k*K;l++) dp[k][l]=0;
		for(k=0;k<len;k++) {
			for(l=0;l<=k*K&&l<=c[f[i]];l++) {
				for(p=0;p<=K;p++) {
					upd(dp[k+1][l+p],dp[k][l]+h[p]);
				}
			}
		}
		ans+=dp[len][min(c[f[i]],len*K)];
	}
	printf("%lld\n",ans);
}