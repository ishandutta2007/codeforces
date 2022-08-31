#include <cstdio>
#include <cstring>

using namespace std;

const int N = 5010;

int n;
int f[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &f[i]);
	for (int i = 1; i <= n; ++i)
		if (f[f[i]] != i && f[f[f[i]]] == i) {
			puts("Yes");
			return 0;
		}
	puts("No");
	return 0;
}