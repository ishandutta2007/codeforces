#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

typedef long long LL;

const int N = 200005;

int n, c1, c2;

char s[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%s", s + 1);
		n = strlen(s + 1);
		c1 = c2 = 0;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i] == '[') ++c1;
			else if (s[i] == '(') ++c2;
			else if (s[i] == ']') {
				if (c1) c1--, ans++;
			} else if (s[i] == ')') {
				if (c2) c2--, ans++;
			}
		}
		printf("%d\n", ans);
	}	
	return 0;
}