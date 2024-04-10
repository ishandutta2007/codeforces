#include <bits/stdc++.h>
#define N 1000500
using namespace std;
inline int rd() {int r;scanf("%d",&r);return r;}
int main() {
	int T = rd();
	while (T--) {
		long long n, s;
		cin >> n >> s;
		long long t = 1LL*n*n;
		long long ans = s/t;
		printf("%d\n", (int)ans);
	}
	return 0;
}