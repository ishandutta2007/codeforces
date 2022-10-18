#include <cstdio>
#include <algorithm>
using namespace std;

int a[120];
int vis[120]={0};
int b[120]={0};

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i=1;i<=n;++i) {
		scanf("%d", &a[i]);
		b[i]=a[i];
	}
	int cnt=n;
    sort(a+1,a+cnt+1);
    cnt=unique(a+1,a+cnt+1)-a-1;
	if (cnt<k) {
		printf("NO");
		return 0;
	} else {
		printf("YES\n");
		for (int i=1;i<=n;i++) {
			if (vis[b[i]]==0) {
				printf("%d ", i);
				vis[b[i]]=1; k--;
			}if (k==0) break;
		}
	}
	return 0;
}