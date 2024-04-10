#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 300'000;
const int M = 1'000'000;

int sigma[M + 1], n, a[N];
long long fenwick[N];

void add(int k, int v) {
  for (; ~k; k -= ~k & k + 1) {
    fenwick[k] += v;
  }
}

long long ask(int k) {
  long long result = 0;
  for (; k < n; k += ~k & k + 1) {
    result += fenwick[k];
  }
  return result;
}

int main() {
  for (int i = 1; i <= M; ++i) {
    for (int j = i; j <= M; j += i) {
      sigma[j]++;
    }
  }
  int q;
  scanf("%d%d", &n, &q);
  std::set<int> candidates;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    add(i, a[i]);
    if (a[i] > 2) {
      candidates.insert(i);
    }
  }
  while (q--) {
    int op, l, r;
    scanf("%d%d%d", &op, &l, &r);
    l--;
    if (op == 1) {
      auto iterator = candidates.lower_bound(l);
      while (iterator != candidates.end() && *iterator < r) {
        auto backup = iterator;
        iterator++;
        int i = *backup;
        add(i, -a[i]);
        a[i] = sigma[a[i]];
        add(i, a[i]);
        if (a[i] <= 2) {
            candidates.erase(backup);
        }
      }
    } else {
      printf("%lld\n", ask(l) - ask(r));
    }
  }
}