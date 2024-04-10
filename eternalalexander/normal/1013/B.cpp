#include <cstdio>
#include <cstring>

int a[100005], b[100005];
int vis[100005]={0};

int main() {
	int n, x; scanf("%d %d", &n, &x);
	for (int i=1;i<=n;++i) {
		scanf("%d", &a[i]); b[i]=a[i]&x;
		if (vis[a[i]]==1) {printf("0"); return 0;}
		vis[a[i]]=1;
	}for (int i=1;i<=n;++i) {
		//printf("%d", b[i]);
		if (b[i]!=a[i]&&vis[b[i]]) {
			printf("1"); return 0;
		}
	}for (int i=1;i<=n;++i) {
		if (b[i]!=a[i]&&vis[b[i]]) {
			printf("2"); return 0;
		}vis[b[i]]=1;
	}printf("-1");
	return 0;
}