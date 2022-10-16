#include <bits/stdc++.h>
using namespace std;
 
 
char s[1100000];
int n, k;
int a[1100000];
int h[1100000];

int main() {
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		h[a[i]]++;
	}

	for (int i = 200000 ; i>= 0; i--) h[i]+=h[i+1];

	int cur = 0,ans=0;
	for (int i = 210000; i >= 0; i--) {
		if (h[i] == n) break;
		if (cur + h[i] > k) {
			ans++;
			cur = 0;
		}

		cur += h[i];
	}

	if (cur != 0) ans++;
	printf("%d\n",ans);
}