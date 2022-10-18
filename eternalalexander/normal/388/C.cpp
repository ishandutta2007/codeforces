#include <bits/stdc++.h>

int n,c,a[1005],A,B;
std::vector<int>v;

int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d",&c);
		for (int j = 1; j <= c; ++ j) scanf("%d",&a[j]);
		if (c % 2) v.push_back(a[c/2+1]);
		for (int j = 1; j <= c / 2; ++ j) A += a[j];
		for (int j = (c + 1) / 2 + 1; j <= c; ++ j) B += a[j];
	}
	std::sort(v.begin(),v.end(),[](int a,int b) { return a > b; });
	int c = 0;
	for (int x:v) { if (c == 0) A += x; else B += x; c ^= 1; }
	printf("%d %d",A,B);
	return 0;
}