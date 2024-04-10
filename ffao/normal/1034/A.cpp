#include <bits/stdc++.h>
using namespace std;
 
int n;
int cnt[21000000];
int p[16000000];
int v[310000];

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b,a%b);
}

int main() {
	scanf("%d", &n);
 	
 	int g = 0;
 	for (int i = 0; i < n; i++) {
 		scanf("%d", &v[i]);
 		g = gcd(g,v[i]);
 	}

 	for (int i = 0; i < n; i++) {
 		cnt[v[i]/g]++;
 	}

 	int mx = 0;
 	for (int i = 2; i <= 15000000; i++) if (!p[i]) {
 		for (int j = i+i; j <= 15000000; j += i) {
 			cnt[i] += cnt[j];
 			p[j] = 1;
 		}
 		if (cnt[i] != n) mx = max(mx, cnt[i]);
 	}

 	printf("%d\n", mx == 0 ? -1 : n-mx);
}