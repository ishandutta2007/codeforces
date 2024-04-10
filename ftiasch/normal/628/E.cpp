#line 1 "sol.cpp"
#include <bits/stdc++.h>

struct Entry {
  int left, right;
  char c;
};

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  std::vector<char> s(m + 1);
  std::vector<int> left(m);
  std::vector<std::vector<Entry>> diags((n - 1) + (m - 1) + 1);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s.data());
    for (int j = 0, z = 0; j < m; ++j) {
      z = s[j] == 'z' ? z + 1 : 0;
      left[j] = z;
    }
    for (int j = m, z = 0; j--;) {
      z = s[j] == 'z' ? z + 1 : 0;
      diags[i + j].push_back(Entry{left[j], z, s[j]});
    }
  }
  long long result = 0;
  std::vector<std::tuple<int, int, int>> events;
  int d = std::min(n, m);
  int now = 0;
  std::vector<std::pair<int, int>> fenwick(d + 1);
  for (auto &&diag : diags) {
    for (int b = 0; b < diag.size();) {
      if (diag[b].c == 'z') {
        int e = b;
        while (e < diag.size() && diag[e].c == 'z') {
          e++;
        }
        // for (int i = b; i < e; ++i) {
        //   for (int j = i; j < e; ++j) {
        //     result += diag[i].left >= j - i + 1 && diag[j].right >= j - i +
        //     1;
        //   }
        // }
        // left[i] >= j - i + 1 <=> left[i] + i >= j + 1
        // right[j] >= j - i + 1 <=> i >= j - right[j] + 1
        events.clear();
        for (int j = b; j < e; ++j) {
          events.emplace_back(j, j + 1, 1);
          if (j - diag[j].right >= b) {
            events.emplace_back(j - diag[j].right, j + 1, -1);
          }
        }
        std::sort(events.begin(), events.end());
        now++;
        for (int i = b, k = 0; i < e; ++i) {
          for (int j = std::min(diag[i].left + i, d); ~j; j -= ~j & j + 1) {
            if (fenwick[j].second != now) {
              fenwick[j] = {0, now};
            }
            fenwick[j].first++;
          }
          while (k < events.size() && std::get<0>(events[k]) == i) {
            auto [_, j, delta] = events[k++];
            int subtotal = 0;
            for (; j <= d; j += ~j & j + 1) {
              subtotal += fenwick[j].second == now ? fenwick[j].first : 0;
            }
            result += delta * subtotal;
          }
        }
        b = e;
      } else {
        b++;
      }
    }
  }
  printf("%lld\n", result);
}