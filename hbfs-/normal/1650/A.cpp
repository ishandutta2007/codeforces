#include <bits/stdc++.h>
using namespace std;
char s[100050], c[100050];
int main() {
	int T; scanf("%d",&T);
	while (T--) {
		scanf("%s",s+1);
		int n = strlen(s+1);
		scanf("%s",c+1);
		bool flag = 0;
		for (int i=1;i<=n;i+=2) if (s[i] == c[1]) flag = 1;
		puts(flag ? "YES" : "NO"); 
	}
	return 0;
}