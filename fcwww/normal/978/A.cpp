#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double f2;
int n,a[100],h[1050],ans[100];
int main() {
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	for(i=n;i>=1;i--) {
		if(!h[a[i]]) ans[++ans[0]]=a[i],h[a[i]]=1;
	}
	printf("%d\n",ans[0]);
	for(i=ans[0];i;i--) {
		printf("%d ",ans[i]);
	}
}