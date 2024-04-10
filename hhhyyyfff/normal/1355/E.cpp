#include <cstdio>
#include <algorithm>

using namespace std;

int N, A, R, M;
long long ans, h[100010], s[100010];

long long work(int i, long long t) {
  if (t < h[i] || t > h[i + 1]) return 1e18;
  long long a = i * t - s[i], b = s[N] - s[i] - (N - i) * t, c = min(a, b);
  return (a - c) * A + (b - c) * R + c * M;
}

long long work1(int i, long long t) { return min(work(i, t), work(i, t + 1)); }

int main() {
  scanf("%d%d%d%d", &N, &A, &R, &M);
  if (A + R < M) M = A + R;
  for (int i = 1; i <= N; ++i) scanf("%d", &h[i]);
  h[N + 1] = 1e18;
  sort(h + 1, h + N + 1);
  for (int i = 1; i <= N; ++i) s[i] = h[i] + s[i - 1];
  ans = 1e18;
  for (int i = 1; i <= N; ++i) {
    long long a = i, b = i * h[i] - s[i], c = i - N,
        d = s[N] - s[i] - (N - i) * h[i];
    ans = min(ans, min(work(i, h[i]), work1(i, h[i] + (d - b) / (a - c))));
  }
  printf("%lld\n", ans);
  return 0;
}