#include <bits/stdc++.h>

long long solve(const std::vector<int> &count) {
  long long result[4];
  memset(result, 0, sizeof(result));
  result[0] = 1;
  for (int c : count) {
    for (int i = 3; i >= 1; --i) {
      result[i] += result[i - 1] * c;
    }
  }
  return result[3];
}

long long binom2(int n) { return n * (n - 1LL) / 2; }

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::vector<std::pair<int, int>> pair(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", &pair[i].first, &pair[i].second);
      pair[i].first--;
      pair[i].second--;
    }
    long long result = 0;
    {
      std::vector<int> count(n);
      for (int i = 0; i < n; ++i) {
        count[pair[i].first]++;
      }
      result += solve(count);
      std::fill(count.begin(), count.end(), 0);
      for (int i = 0; i < n; ++i) {
        count[pair[i].second]++;
      }
      result += solve(count);
    }
    std::sort(pair.begin(), pair.end());
    long long a_pairs = 0, b_pairs = 0;
    std::vector<long long> a_delta(n);
    std::vector<int> b_count(n);
    for (int i = 0; i < n;) {
      int j = i;
      while (j < n && pair[i].first == pair[j].first) {
        j++;
      }
      for (int k = i; k < j; ++k) {
        int b = pair[k].second;
        long long sub_result = binom2(i - b_count[b]);
        sub_result -= a_pairs - a_delta[b];
        sub_result -= b_pairs - binom2(b_count[b]);
        result -= sub_result;
      }
      int size_a = j - i;
      a_pairs += binom2(size_a);
      for (int k = i; k < j; ++k) {
        int b = pair[k].second;
        a_delta[b] += size_a - 1;
        b_pairs += b_count[b];
        b_count[b]++;
      }
      i = j;
    }
    printf("%lld\n", result);
  }
}