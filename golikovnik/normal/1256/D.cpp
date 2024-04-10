#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int q;
  cin >> q;
  while (q--) {
    int64_t n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int64_t> pos_zero;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0') {
        pos_zero.push_back(i);
      }
    }
    int nzeros = (int) pos_zero.size();
    for (int i = 0; i < nzeros && k; ++i) {
      auto try_pos = i ? pos_zero[i - 1] + 1 : 0;
      auto can = min(k, pos_zero[i] - (i ? pos_zero[i - 1] + 1 : 0));
      pos_zero[i] -= can;
      k -= can;
    }
    string answer(n, '1');
    for (int i : pos_zero) {
      answer[i] = '0';
    }
    cout << answer << '\n';
  }
  return 0;
}