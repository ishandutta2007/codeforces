#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, M;
  cin >> n >> M;
  vector <int> t(n);
  for (int i = 0; i < n; i++)
    cin >> t[i];
  int sum = 0;
  vector <int> cnt(101);
  vector <int> ans(n);
  for (int i = 0; i < n; i++) {
    sum += t[i];
    int izl = sum - M;
    for (int it = 100; it >= 1 && izl > 0; it--) {
      int c = min(cnt[it], (izl + it - 1) / it);
      ans[i] += c;
      izl -= c * it;
    }
    cnt[t[i]]++;
  }
  for (auto &now : ans)
    cout << now << ' ';
  return 0;
}