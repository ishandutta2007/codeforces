#include <cmath>
#include <cstdio>

#include <vector>

using namespace std;

typedef long long ll;

bool f[1002];

int main() {
	int n, f1 = 1, f2 = 1, t;
	scanf("%d", &n);
	while (f1 <= n) {
		t = f1;
		f1 = f2;
		f2 = f1 + t;
		f[t] = true;
	}
	for (int i = 1; i <= n; ++i)
		putchar(f[i] ? 'O' : 'o');
	putchar('\n');
	return 0;
}