#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;
  while (T--) {
    string A, B;
    cin >> A >> B;
    vector<int> cnt(26);
    for (auto i : A) cnt[i - 'A'] += 1;
    for (auto i : B) cnt[i - 'A'] -= 1;
    bool ans = true;
    for (int i = 0; i < 26; i++) {
      if (cnt[i] < 0) {
        ans = false;
      }
    }
    if (ans) {
      vector<vector<int>> occ(26);
      for (int i = 0; i < int(A.size()); i++) {
        occ[A[i] - 'A'].emplace_back(i);
      }
      string T;
      vector<int> non(A.size());
      for (int i = 0; i < 26; i++) {
        for (int j = 0; j < cnt[i]; j++) {
          non[occ[i][j]] = 1;
        }
      }
      for (int i = 0; i < int(A.size()); i++) {
        if (non[i]) continue;
        T.push_back(A[i]);
      }
      if (B != T) ans = false;
    }
    cout << (ans ? "YES" : "NO") << '\n';
  }
  return 0;
}