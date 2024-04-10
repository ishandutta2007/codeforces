#include <iostream>
#include <vector>
#include <string>

using namespace std;

int slv(const vector<int> &s) {
  if (s.empty()) {
    return 0;
  }
  int ans = 0;
  int n = s.size();
  int last_used = -3;
  for (int i = 0; i < n; i++) {
    if (s[i] == 0) {
      ans++;
    } else {
      if ((i > 0 && s[i - 1] == 0) && last_used != i - 2) {
        ans++;
        last_used = -3;
      } else if (i + 1 < n && s[i + 1] == 0) {
        ans++;
        last_used = i;
      } else {
        last_used = -3;
      }
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
      char ch;
      cin >> ch;
      a[i] = ch - '0';
    }
    for (int i = 0; i < n; i++) {
      char ch;
      cin >> ch;
      b[i] = ch - '0';
    }
    int answer = 0;
    vector<int> tmp;
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i]) {
        answer += 2;
        answer += slv(tmp);
        tmp = {};
      } else {
        tmp.push_back(a[i]);
      }
    }
    answer += slv(tmp);
    cout << answer << '\n';
  }
  return 0;
}