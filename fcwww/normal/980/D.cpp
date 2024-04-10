#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
#define N 10050
int n,a[N],ans[N],v[N],c[N];
int main() {
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		int o;
		if(a[i]>0) o=1;
		else a[i]=-a[i],o=-1;
		for(j=2;j*j<=a[i];j++) {
			if(a[i]%j==0) {
				int q=0;
				while(a[i]%j==0) a[i]/=j,q++;
				if(q&1) o*=j;
			}
		}
		o*=a[i];
		a[i]=o;
		v[i]=a[i];
	}
	sort(v+1,v+n+1);
	int cnt=unique(v+1,v+n+1)-v-1;
	for(i=1;i<=n;i++) a[i]=lower_bound(v+1,v+cnt+1,a[i])-v;
	for(i=1;i<=n;i++) {
		memset(c,0,sizeof(c));
		int t=0;
		int flg=0;
		for(j=i;j<=n;j++) {
			if(v[a[j]]&&!c[a[j]]) {
				c[a[j]]=1; t++;
			}else if(v[a[j]]==0&&!t) t=1,flg=1;
			if(flg&&t>1) t--,flg=0;
			ans[t]++;
		}
	}
	for(i=1;i<=n;i++) printf("%d ",ans[i]);
}