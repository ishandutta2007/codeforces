#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  map <int, int> last;
  vector <int> d(n), p(n);
  for (int i = 0; i < n; i++) {
    last[a[i]] = i;
    if (last.find(a[i] - 1) == last.end()) {
      d[i] = 1;
      p[i] = -1;
      continue;
    }
    int pos = last[a[i] - 1];
    d[i] = d[pos] + 1;
    p[i] = pos;
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
    ans = max(ans, d[i]);
  for (int i = 0; i < n; i++) {
    if (d[i] == ans) {
      cout << d[i] << '\n';
      vector <int> answer;
      while (i != -1) {
        answer.push_back(i + 1);
        i = p[i];
      }
      reverse(answer.begin(), answer.end());
      for (auto &now : answer)
        cout << now << ' ';
      return 0;
    }
  }
  return 0;
}