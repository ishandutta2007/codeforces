#include <cstdio>
#include <cstring>

#include <algorithm>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

char s[110];
bool f[3];

int main() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for (int i = 2; i < n; ++i) {
		f[0] = f[1] = f[2] = false;
		f[s[i - 1] - 'A'] = true;
		f[s[i + 1] - 'A'] = true;
		f[s[i] - 'A'] = true;
		if (f[0] && f[1] && f[2]) {
			puts("Yes");
			return 0;
		}
	}
	puts("No");
	return 0;
}