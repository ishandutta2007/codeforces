#include <cstdio>
#include <cstring>

int main() {
	char s[101]; scanf("%s", s);
	int n = strlen(s);
	int res = 0;
	for (int i = 0; i < n - 2; ++i)
		for (int j = i + 1; j < n - 1; ++j)
			for (int k = j + 1; k < n; ++k)
				if (s[i] == 'Q' && s[j] == 'A' && s[k] == 'Q')
					++res;
	printf("%d", res);
}