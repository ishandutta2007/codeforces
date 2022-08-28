#include <cstdio>
#include <cstring>

#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

typedef long long ll;

const int N = 1000010;

int pc;
int p[N], sum[N], sum2[N];
bool vis[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int x = 2; x <= n; ++x) {
		if (!vis[x])
			p[++pc] = x;
		for (int i = 1; x * p[i] <= n; ++i) {
			vis[x * p[i]] = true;
			if (x % p[i] == 0)
				break;
		}
	}
	for (int i = 1; i <= pc; ++i)
		if (n % p[i] == 0) {
			++sum[n - p[i] + 1];
			--sum[n + 1];
		}
	for (int i = 1; i <= n; ++i) {
		sum[i] += sum[i - 1];
	}
	for (int i = 1; i <= pc; ++i) {
		for (int j = 2; j * p[i] <= n; ++j)
			if (sum[j * p[i]]) {
				++sum2[j * p[i] - p[i] + 1];
				--sum2[j * p[i] + 1];
			}
	}
	for (int i = 1; i <= n; ++i) {
		sum2[i] += sum2[i - 1];
		if (sum2[i]) {
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}