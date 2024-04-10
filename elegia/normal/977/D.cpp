#include <cstdio>
#include <cstring>

#include <algorithm>
#include <map>
#include <iostream>
#include <bitset>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int N = 110;

int n;
int gt[N];
bool f[N];
ll a[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &a[i]);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (a[i] / 3 == a[j] && a[i] % 3 == 0) {
				gt[i] = j;
				f[j] = true;
			} else if (a[i] * 2 == a[j]) {
				gt[i] = j;
				f[j] = true;
			}
	int t = 1;
	for (int i = 1; i <= n; ++i)
		if (!f[i])
			t = i;
	while (t) {
		printf("%lld ", a[t]);
		t = gt[t];
	}
	return 0;
}