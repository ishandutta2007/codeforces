#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define N 200050
typedef long long ll;
int n,K,a[N];
void solve() {
	scanf("%d%d",&n,&K);
	int i; K++;
	int mnfk=1<<30,ans=0;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i+K-1<=n;i++) {
		int l=a[i],r=a[i+K-1];
		int mid=(l+r)>>1;
		int t=max(mid-l,r-mid);
		if(t<mnfk) mnfk=t,ans=mid;
	}
	printf("%d\n",ans);
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) solve();
}