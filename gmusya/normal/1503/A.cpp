#include <iostream>
#include <vector>

using namespace std;

bool check(vector <int> &a) {
  int n = a.size();
  int bal = 0;
  for (int i = 0; i < n; i++) {
    bal += a[i];
    if (bal < 0) {
      return false;
    }
  }
  return (bal == 0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> s(n);
    for (int i = 0; i < n; i++) {
      char ch;
      cin >> ch;
      s[i] = ch - '0';
    }
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 0) {
        cnt0++;
      } else {
        cnt1++;
      }
    }
    if ((cnt0 & 1) || (cnt1 & 1)) {
      cout << "NO\n";
      continue;
    }
    vector <int> a(n), b(n);
    int cur_cnt0 = 0, cur_cnt1 = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 1) {
        if (cur_cnt1 < cnt1 / 2) {
          a[i] = 1;
          b[i] = 1;
        } else {
          a[i] = -1;
          b[i] = -1;
        }
        cur_cnt1++;
      } else {
        if (cur_cnt0 & 1) {
          a[i] = 1;
          b[i] = -1;
        } else {
          a[i] = -1;
          b[i] = 1;
        }
        cur_cnt0++;
      }
    }
    if (check(a) && check(b)) {
      cout << "YES\n";
      for (int x : a) {
        cout << (x == 1 ? '(' : ')');
      }
      cout << '\n';
      for (int x : b) {
        cout << (x == 1 ? '(' : ')');
      }
      cout << '\n';
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}