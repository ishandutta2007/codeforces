#include <bits/stdc++.h>
#define maxn 100005

int n, vis[maxn]={0}, ans[maxn];
struct node {
	int v, id;
}arr[maxn];

int cmp(node a, node b) {return a.v<b.v;}

int main() {
	scanf("%d", &n);
	for (int i=1;i<=n;++i) {
		scanf("%d", &arr[i].v);
		arr[i].v=n-arr[i].v; arr[i].id=i;
		vis[arr[i].v]++;
	} std::sort(arr+1, arr+n+1, cmp);
	int p=1,cnt=1;
	for (int i=1;i<=n;++i) {
		while (vis[i]>0) {
			//printf("%d\n", i);
			if (cnt>n) {
				printf("Impossible");
				return 0;
			}if (p>n) {
				printf("Impossible");
				return 0;
			}
			for (int j=p;j<=p+i-1;++j) {
			//	printf("%d %d\n", j, arr[j].v);
				if (arr[j].v!=i) {
					printf("Impossible");
					return 0;
				}ans[arr[j].id]=cnt;
				vis[arr[j].v]--;
			}p+=i; 
			
			cnt++;
		}
	}printf("Possible\n");
	for (int i=1;i<=n;++i) printf("%d ", ans[i]);
	return 0;
}