#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
      return a[i] > a[j];
    });
    auto b = a;
    sort(b.rbegin(), b.rend());
    while (!b.empty() && b.back() == 1) {
      b.pop_back();
    }
    if (b == vector<int>{} || b == vector<int>{2} || b == vector<int>{2, 2}) {
      vector<vector<int>> all;
      if (b == vector<int>{2}) {
        int i = order[0];
        all.emplace_back(n, 0);
        all.back()[i] = 2;
        all.emplace_back(n, 0);
        all.back()[i] = 1;
      }
      if (b == vector<int>{2, 2}) {
        int i = order[0];
        int j = order[1];
        all.emplace_back(n, 0);
        all.back()[i] = 2; all.back()[j] = 2;
        all.emplace_back(n, 0);
        all.back()[i] = 1; all.back()[j] = 0;
        all.emplace_back(n, 0);
        all.back()[i] = 2; all.back()[j] = 1;
        all.emplace_back(n, 0);
        all.back()[i] = 0; all.back()[j] = 2;
        all.emplace_back(n, 0);
        all.back()[i] = 1; all.back()[j] = 1;
        all.emplace_back(n, 0);
        all.back()[i] = 2; all.back()[j] = 0;
        all.emplace_back(n, 0);
        all.back()[i] = 1; all.back()[j] = 2;
        all.emplace_back(n, 0);
        all.back()[i] = 0; all.back()[j] = 1;
      }
      for (int it = (int) b.size(); it < n; it++) {
        int sz = (int) all.size();
        all.resize(2 * sz);
        for (int i = sz; i < 2 * sz; i++) {
          all[i] = all[2 * sz - 1 - i];
        }
        for (int i = 0; i < 2 * sz; i++) {
          all[i][order[it]] = i % 2;
        }
        all.emplace_back(n, 0);
        all.back()[order[it]] = 1;
      }
      for (auto& p : all) {
        for (int i = 0; i < n; i++) {
          cout << p[i] << " \n"[i == n - 1];
        }
      }
      continue;
    }
    if (b == vector<int>{3}) {
      vector<vector<int>> all;
      {
        int i = order[0];
        all.emplace_back(n, 0);
        all.back()[i] = 3;
        all.emplace_back(n, 0);
        all.back()[i] = 1;
        all.emplace_back(n, 0);
        all.back()[i] = 2;
      }
      for (int it = (int) b.size(); it < n; it++) {
        int sz = (int) all.size();
        all.resize(2 * sz + 1);
        all[sz] = vector<int>(n, 0);
        for (int i = sz + 1; i < 2 * sz + 1; i++) {
          all[i] = all[i - sz - 1];
        }
        for (int i = 0; i < 2 * sz + 1; i++) {
          all[i][order[it]] = (i <= sz ? i % 2 : 1 - i % 2);
        }
        vector<int> needle(n, 0);
        needle[order[0]] = 1;
        for (int i = 0; i < 2 * sz + 1; i++) {
          if (all[i] == needle) {
            swap(all[i], all[sz]);
            break;
          }
        }
      }
      for (auto& p : all) {
        for (int i = 0; i < n; i++) {
          cout << p[i] << " \n"[i == n - 1];
        }
      }
      continue;
    }
    cout << -1 << '\n';
  }
  return 0;
}