#include <iostream>
#include <cstdio>

using namespace std;
int n,k,p,t;
char s[10];
int main() {
	scanf("%d",&n);
	for (int _=1;_<=n;_++) {
		scanf("%d%s",&t,s+1);
		if (s[1] == 'W' || s[1] == 'E') {
			if (k == 0 || k == 20000) {
				puts("NO"); return 0;
			} 
			continue;
		}
		if (s[1] == 'N') k -= t; else k += t;
		if (k < 0 || k > 20000) {
			puts("NO"); return 0;
		}
	}
	if (k == 0 && p == 0) puts("YES"); else puts("NO");
	return 0;
}