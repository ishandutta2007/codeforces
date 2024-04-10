#include <bits/stdc++.h>

template <int N> struct PrefixTable {
  void compute(int n, const char *s) {
    z[0] = 0;
    for (int i = 1, j = 0; i < n; ++i) {
      z[i] = i < j + z[j] ? std::min(z[i - j], j + z[j] - i) : 0;
      while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
        z[i]++;
      }
      if (i + z[i] > j + z[j]) {
        j = i;
      }
    }
    z[0] = n;
  }

  int z[N];
};

const int N = 500000;

int n, m;
char a[N + 1], b[N + 1], s[N * 3 + 1];
PrefixTable<N * 3> prefix;
std::pair<int, int> aorder[N], border[N];

struct Fenwick {
  template <int delta> void add(int k) {
    for (; k < n; k += ~k & k + 1) {
      count[k] += delta;
    }
  }

  int ask(int k) const {
    int result = 0;
    for (k = std::min(k, n - 1); k >= 0; k -= ~k & k + 1) {
      result += count[k];
    }
    return result;
  }

  int count[N];
} acount, bcount;

int main() {
  scanf("%d%d%s%s%s", &n, &m, a, b, s);
  s[m] = '#';
  strcpy(s + m + 1, a);
  prefix.compute(m + n + 1, s);
  for (int i = 0; i < n; ++i) {
    aorder[i] = {prefix.z[m + 1 + i], i};
  }
  std::sort(aorder, aorder + n);

  std::reverse(s, s + m);
  for (int i = 0; i < n; ++i) {
    s[m + 1 + i] = b[n - 1 - i];
  }
  prefix.compute(m + n + 1, s);
  for (int i = 0; i < n; ++i) {
    border[i] = {prefix.z[m + n - i], i};
  }
  std::sort(border, border + n);

  long long result = 0;
  long long sum = 0;
  for (int i = 0; i < n; ++ i) {
    acount.add<1>(aorder[i].second);
  }
  for (int i = 0, j = 0, k = n; i < m; ++i) {
    while (k && border[k - 1].first == m - i) {
      int y = border[--k].second;
      bcount.add<1>(y);
      sum += acount.ask(y) - acount.ask(y - m + 1);
    }
    if (i) {
      result += sum;
    }
    while (j < n && aorder[j].first == i) {
      int x = aorder[j++].second;
      acount.add<-1>(x);
      sum -= bcount.ask(x + m - 2) - bcount.ask(x - 1);
    }
  }
  printf("%lld\n", result);
}