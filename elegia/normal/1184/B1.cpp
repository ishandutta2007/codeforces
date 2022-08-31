#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int N = 100010;

int s, b;
pair<int, int> t[N];
int a[N], best[N], cur[N];

int main() {
  scanf("%d%d", &s, &b);
  for (int i = 1; i <= s; ++i)
    scanf("%d", &a[i]);
  for (int i = 1; i <= b; ++i) {
    int d, g;
    scanf("%d%d", &g, &d);
    t[i] = make_pair(g, d);
  }
  sort(t + 1, t + b + 1);
  for (int i = 1; i <= b; ++i) {
    cur[i] = t[i].first;
    best[i] = best[i - 1] + t[i].second;
  }
  for (int i = 1; i <= s; ++i) {
    printf("%d ", best[upper_bound(cur + 1, cur + b + 1, a[i]) - cur - 1]);
  }
	return 0;
}