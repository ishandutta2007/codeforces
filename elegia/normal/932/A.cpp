#include <cstdio>
#include <cstring>

#include <algorithm>
#include <numeric>

const int N = 1010;

char s[N];

int main() {
	scanf("%s", s);
	int n = strlen(s);
	printf("%s", s);
	for (int i = n - 1; i >= 0; --i)
		putchar(s[i]);
	return 0;
}