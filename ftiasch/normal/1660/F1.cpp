#include <bits/stdc++.h>

struct Fenwick : std::vector<int> {
  Fenwick(int n) : n(n), std::vector<int>(n) {}

  void add(int k) {
    for (; ~k; k -= ~k & k + 1) {
      (*this)[k]++;
    }
  }

  int ask(int k) const {
    int result = 0;
    for (; k < n; k += ~k & k + 1) {
      result += (*this)[k];
    }
    return result;
  }

  int n;
};

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::vector<char> s(n + 1);
    scanf("%s", s.data());
    std::vector<Fenwick> fenwicks(3, Fenwick((n << 1) + 1));
    int sum = n;
    fenwicks[sum % 3].add(sum);
    long long result = 0;
    for (int i = 0; i < n; ++i) {
      sum += s[i] == '-' ? -1 : 1;
      result += fenwicks[sum % 3].ask(sum);
      fenwicks[sum % 3].add(sum);
    }
    printf("%lld\n", result);
  }
}