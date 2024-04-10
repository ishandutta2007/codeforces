#include <bits/stdc++.h>
using namespace std;

int n,t,k,d;

int main() {
	scanf("%d %d %d %d", &n, &t, &k, &d);

	int t1 = ((n+k-1) / k) * t; 
	if (t1 > d+t) printf("YES\n");
	else printf("NO\n");
}