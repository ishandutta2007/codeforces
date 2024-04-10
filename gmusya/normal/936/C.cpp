#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector <int> vi;

int n;
vector <int> ans;

vi shift(vi a, int x) {
  if (!x)
    return a;
  if (x)
    rotate(a.begin(), a.begin() + n - x, a.end());
  reverse(a.begin(), a.begin() + x);
  ans.push_back(x);
  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  vector <char> a(n), b(n);
  vector <vector <int>> a_cnt(26), b_cnt(26);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a_cnt[a[i] - 'a'].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    b_cnt[b[i] - 'a'].push_back(i);
  }
  for (int i = 0; i < 26; i++)
    if (a_cnt[i].size() != b_cnt[i].size()) {
      cout << -1;
      return 0;
    }
  vector <int> a_int(n), b_int(n);
  int cnt = 0;
  for (int i = 0; i < 26; i++)
    while (!a_cnt[i].empty()) {
      a_int[a_cnt[i].back()] = cnt++;
      a_cnt[i].pop_back();
    }
  cnt = 0;
  for (int i = 0; i < 26; i++)
    while (!b_cnt[i].empty()) {
      b_int[b_cnt[i].back()] = cnt++;
      b_cnt[i].pop_back();
    }
  for (int i = n - 1; i >= 0; i--) {
    int pos = 0, val = b_int[i];
    for (int j = 0; j < n; j++)
      if (a_int[j] == b_int[i]) {
        pos = j;
        break;
      }
    a_int = shift(a_int, n);
    a_int = shift(a_int, pos);
    a_int = shift(a_int, 1);
  }
  cout << ans.size() << '\n';
  for (int x : ans)
    cout << x << ' ';
  return 0;
}