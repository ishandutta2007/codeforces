#include <bits/stdc++.h>
using namespace std;

char buf[110];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%s", buf);
		int n = strlen(buf);
		if (buf[0] != buf[n - 1]) buf[0] = buf[n - 1];
		printf("%s\n", buf);
	}
	return 0;
}