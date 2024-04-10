#include <iostream>
#include <cstdio>

using namespace std;
int Abs(int x) { return x < 0 ? -x : x; }
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	if (n == 0 && m == 0) {
		puts("NO"); return 0;
	}
	if (Abs(n-m) <= 1) puts("YES"); else puts("NO");
	return 0;
}