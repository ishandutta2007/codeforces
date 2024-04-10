#include <bits/stdc++.h>

int n,a[2005],b[2005],ans=1e9;
void work1() {
	for (int i = 1; i <= 2 * n; i += 2) std::swap(b[i],b[i+1]);
} void work2() {
	for (int i = 1; i <= n; ++ i) std::swap(b[i],b[i+n]);
}

void try1(int x) {
	for (int i = 1; i <= 2 * n; ++ i) b[i] = a[i];
	for (int i = 1; i <= x; ++ i) {
		if (i & 1) work1();
		else work2();
		if (std::is_sorted(b+1,b+2*n+1)) {
			ans = std::min(ans,i);
			return;
		}
	}
}

void try2(int x) {
	for (int i = 1; i <= 2 * n; ++ i) b[i] = a[i];
	for (int i = 1; i <= x; ++ i) {
		if (i & 1) work2();
		else work1();
		if (std::is_sorted(b+1,b+2*n+1)) {
			ans = std::min(ans,i);
			return;
		}
	}
}

int main() {
	scanf("%d",&n);
	for (int i = 1; i <= 2*n; ++ i) 
		scanf("%d",&a[i]);
	if (std::is_sorted(a+1,a+2*n+1)) { puts("0"); return 0; }
	try1(2*n);
	try2(2*n);
	if (ans > 4 * n ) puts("-1");
	else printf("%d",ans);
	return 0;
}