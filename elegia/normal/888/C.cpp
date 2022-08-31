#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <queue>
#include <stack>
#include <numeric>
#include <limits>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int N = 100010;

int n;
int cost[26], lst[26];
char s[N];

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; ++i) {
		int j = s[i] - 'a';
		cost[j] = max(cost[j], i - lst[j]);
		lst[j] = i;
	}
	for (int i = 0; i < 26; ++i)
		cost[i] = max(cost[i], n + 1 - lst[i]);
	printf("%d\n", *min_element(cost, cost + 26));
	return 0;
}