#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, i, j, v[1005];
char s[1005];

int main() {
	scanf("%d\n", &n);
	scanf("%s", s + 1);
	s[0] = 'L';
	s[n] = 'R';
	for (i = 1; i <= n; ++i) {
		j = i - 1;
		while (s[j] != 'L') {
			if (s[j] == 'R')
				++v[i];
			--j;
		}

		int aux = 0;
		j = i;
		while (s[j] != 'R') {
			if (s[j] == 'L')
				++aux;
			++j;
		}
		v[i] = max(v[i], aux);
		++v[i];
	}

	for (i = 1; i <= n; ++i)
		printf("%d ", v[i]);
}