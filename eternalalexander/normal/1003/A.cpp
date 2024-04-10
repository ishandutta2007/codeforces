#include <cstdio>
#include <algorithm>
int bucket[120]={0};

int main() {
	int min=0;
	int n; int a[120];
	scanf("%d", &n);
	for (int i=1;i<=n;++i) {
		scanf("%d", &a[i]);
		bucket[a[i]]++;
		min=std::max(min, bucket[a[i]]);
	}printf("%d", min);
	return 0;
}