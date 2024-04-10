#include <cstdio>
#include <cstring>

#include <algorithm>
#include <numeric>

#define LOG(FMT...) fprintf(stderr)

using namespace std;

typedef long long ll;

char s[60];

bool check(int l, int r) {
	while (l < r) {
		if (s[l++] != s[r--])
			return false;
	}
	return true;
}

int main() {
	int ans = 0;
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for (int l = 1; l <= n; ++l)
		for (int r = l; r <= n; ++r)
			if (!check(l, r))
				ans = max(ans, r - l + 1);
	printf("%d\n", ans);
	return 0;
}