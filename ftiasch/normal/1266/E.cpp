#include <bits/stdc++.h>

const int N = 200001;

int n, q, a[N];
long long sum;

int get(int u) { return std::max(a[u], 0); }

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin >> n;
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
    sum += a[i];
  }
  std::cin >> q;
  std::map<std::pair<int, int>, int> m;
  while (q--) {
    int s, t, u;
    std::cin >> s >> t >> u;
    int &uprime = m[std::make_pair(s, t)];
    if (uprime) {
      sum -= get(uprime);
      a[uprime]++;
      sum += get(uprime);
    }
    uprime = u;
    if (uprime) {
      sum -= get(uprime);
      a[uprime]--;
      sum += get(uprime);
    }
    std::cout << sum << "\n";
  }
}