#include <algorithm>
#include <bits/stdc++.h>

const int N = 200000;

int n;
std::pair<int, int> points[N];

long long fenwick[N][2];

void add(int k, int v) {
  for (; k < n; k += ~k & k + 1) {
    fenwick[k][0]++;
    fenwick[k][1] += v;
  }
}

void ask(int k, long long &s0, long long &s1) {
  s0 = s1 = 0;
  for (; k >= 0; k -= ~k & k + 1) {
    s0 += fenwick[k][0];
    s1 += fenwick[k][1];
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &points[i].first);
  }
  std::vector<int> velocities;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &points[i].second);
    velocities.push_back(points[i].second);
  }
  std::sort(velocities.begin(), velocities.end());
  velocities.erase(std::unique(velocities.begin(), velocities.end()),
                   velocities.end());
  std::sort(points, points + n);
  long long result = 0, s0, s1;
  for (int i = 0; i < n; ++i) {
    int x = points[i].first;
    int v = std::lower_bound(velocities.begin(), velocities.end(),
                             points[i].second) -
            velocities.begin();
    ask(v, s0, s1);
    result += s0 * x - s1;
    add(v, x);
  }
  printf("%lld\n", result);
}