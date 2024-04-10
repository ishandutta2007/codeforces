#include <cstdio>
const char f[11] = "aeiou13579";

int main() {
	char s[51]; scanf("%s", s);
	int cnt = 0;
	for (int i = 0; s[i] != '\0'; ++i)
		for (int j = 0; j < 10; ++j)
			cnt += s[i] == f[j];
	printf("%d", cnt);
}