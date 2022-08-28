#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>

using namespace std;

typedef long long ll;

int n;
char s[100010];
char cur = 'a';

int main() {
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; ++i)
		if (s[i] <= cur && cur <= 'z') {
			s[i] = cur;
			++cur;
		}
	if (cur != 'z' + 1) {
		puts("-1");
	} else
		puts(s);
	return 0;
}