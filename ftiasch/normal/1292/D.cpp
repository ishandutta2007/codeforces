#include <atomic>
#include <bits/stdc++.h>
#include <functional>

const int M = 5000 + 2;

int getExp(int p, int n) {
  int result = 0;
  while (n >= p) {
    result += (n /= p);
  }
  return result;
}

int sum[M], maxdiv[M];
std::vector<int> primes;

struct Entry {
  int exp, index, size;
} entries[M];

struct Oracle {
  void add(int k, int n, int c) {
    for (int i = 0; i < k; ++i) {
      result += 1LL * c * getExp(primes[i], n);
    }
  }

  long long sum() { return result; }

  long long result = 0;
};

int main() {
  memset(maxdiv, -1, sizeof(maxdiv));
  for (int d = 2; d < M; ++d) {
    if (maxdiv[d] == -1) {
      maxdiv[d] = primes.size();
      primes.push_back(d);
    }
    for (int p : primes) {
      if (d * p >= M) {
        break;
      }
      maxdiv[d * p] = maxdiv[d];
      if (d % p == 0) {
        break;
      }
    }
  }
  int n;
  while (scanf("%d", &n) == 1) {
    int m = 1;
    sum[1] = 0;
    for (int i = 0, k; i < n; ++i) {
      scanf("%d", &k);
      k = std::max(1, k);
      while (k >= m) {
        sum[m++] = 0;
      }
      sum[k]++;
    }
    for (int i = m; --i;) {
      sum[i] += sum[i + 1];
    }
    int k = 0;
    while (k < static_cast<int>(primes.size()) && primes[k] < m) {
      k++;
    }
    std::vector<std::pair<int, int>> dividens(m - 2);
    for (int i = 2; i < m; ++i) {
      dividens[i - 2] = std::make_pair(maxdiv[i], i);
    }
    std::sort(dividens.begin(), dividens.end(),
              std::greater<std::pair<int, int>>());
    int low = 1, high = m; // [low, high)
    long long result = 0;
    Oracle oracle;
    for (int j = 0; k--;) {
      int p = primes[k];
      int count = 1;
      entries[0] = {getExp(p, low), low, sum[low]};
      int outSize = n - (sum[low] - sum[high]);
      if (entries[0].exp) {
        count = 2;
        entries[1] = entries[0];
        entries[0] = {0, -1, outSize};
      } else {
        entries[0].size += outSize;
      }
      while (j < m - 1 && dividens[j].first == k) {
        int d = dividens[j++].second;
        if (low < d && d <= high) {
          entries[count - 1].size -= sum[d];
          entries[count++] = {getExp(p, d), d, sum[d]};
        }
      }
      entries[count - 1].size -= sum[high];
      entries[count].index = high;
      int total = 0, pivot = 0;
      while ((total + entries[pivot].size) * 2 <= n) {
        total += entries[pivot++].size;
      }
      for (int i = low; i < entries[pivot].index; ++i) {
        oracle.add(k, i, sum[i] - sum[i + 1]);
      }
      for (int i = entries[pivot + 1].index; i < high; ++i) {
        oracle.add(k, i, sum[i] - sum[i + 1]);
      }
      for (int i = 0; i < count; ++i) {
        result += 1LL * std::abs(entries[i].exp - entries[pivot].exp) *
                  entries[i].size;
      }
      low = entries[pivot].index, high = entries[pivot + 1].index;
      if (entries[pivot].size * 2 <= n) {
        for (int i = low; i < high; ++i) {
          oracle.add(k, i, sum[i] - sum[i + 1]);
        }
        break;
      }
    }
    printf("%lld\n", result + oracle.sum());
  }
}