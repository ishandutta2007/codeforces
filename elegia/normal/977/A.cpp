#include <cstdio>
#include <cstring>

#include <algorithm>
#include <bitset>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

int n, k;

int main() {
	scanf("%d%d", &n, &k);
	while (k--) {
		if (n % 10 == 0)
			n /= 10;
		else
			--n;
	}
	printf("%d\n", n);
	return 0;
}