#include <iostream>
#include <cstdio>
#include <cstring>
#define N 200050 

using namespace std;
int a[N],t[N],cur[N],n,pos,ret;
int main() {
	bool flag = false;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) t[ a[i] ]++;
	for (int i=1;i<=n;i++) if (t[i]&1) {
		if (flag) { puts("0"); return 0; } else flag = 1;
	}
	
	int pos = 0;
	for (int i=1;i<=n;i++) {
		if (a[i] != a[n-i+1]) { pos = i; break; }
		t[ a[i] ] -= 2;
	}
	if (!pos) {
		cout << 1LL * n * (n+1) / 2LL << endl;
		return 0;
	}
	
	for (int i=pos;i<=n;i++) {
		cur[ a[i] ]++;
		if (2 * cur[ a[i] ] > t[ a[i] ]) {
			if (i < n-i+1) break;
			if (i == n-i+1 && t[ a[i] ] % 2 == 0) break;
			if (a[i] != a[n-i+1]) break;
		}
		ret++;
	}
	
	memset(cur,0,sizeof(cur));
	for (int i=n-pos+1;i>=1;i--) {
		cur[ a[i] ]++;
		if (cur[ a[i] ] * 2 > 	t[ a[i] ]) {
			if (i > n-i+1) break;
			if (i == n-i+1 && t[ a[i] ] % 2 == 0) break;
			if (a[i] != a[n-i+1]) break;
		}
		ret++;
	}
	
	cout << 1LL * (pos) * (pos + ret) << endl;
	return 0;	
}