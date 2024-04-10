#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  string s;
  cin >> s;
  int n = (int) s.size();
  reverse(s.begin(), s.end());
  int ans = 100;
  {
    int cnt = 0;
    string t = s;
    int pos = -1;
    for (int i = 0; i < n; i++)
      if (s[i] == '5') {
        pos = i;
        break;
      }
    if (pos != -1) {
      while (pos) {
        swap(t[pos], t[pos - 1]);
        pos--;
        cnt++;
      }
      pos = -1;
      for (int i = 0; i < n; i++)
        if (t[i] == '2' || t[i] == '7') {
          pos = i;
          break;
        }
      if (pos != -1) {
        while (pos > 1) {
          swap(t[pos], t[pos - 1]);
          pos--;
          cnt++;
        }
        int pos = n;
        for (int i = n - 1; i >= 2; i--) {
          if (t[i] != '0') {
            pos = i;
            break;
          }
        }
        if (pos != n || n == 2) {
          while (pos < n - 1) {
            pos++;
            cnt++;
          }
          ans = min(ans, cnt);
        }
      }
    }
  }
  {
    int cnt = 0;
    string t = s;
    int pos = -1;
    for (int i = 0; i < n; i++)
      if (s[i] == '0') {
        pos = i;
        break;
      }
    if (pos != -1) {
      while (pos) {
        swap(t[pos], t[pos - 1]);
        pos--;
        cnt++;
      }
      pos = -1;
      for (int i = 1; i < n; i++) {
        if (t[i] == '0') {
          pos = i;
          break;
        }
      }
      if (pos != -1) {
        while (pos > 1) {
          swap(t[pos], t[pos - 1]);
          pos--;
          cnt++;
        }
        pos = n;
        for (int i = n - 1; i >= 2; i--) {
          if (t[i] != '0') {
            pos = i;
            break;
          }
        }
        if (pos != n) {
          while (pos < n - 1) {
            cnt++;
            pos++;
          }
          ans = min(ans, cnt);
        }
      }
    }
  }
  {
    int cnt = 0;
    string t = s;
    int pos = -1;
    for (int i = 0; i < n; i++)
      if (s[i] == '0') {
        pos = i;
        break;
      }
    if (pos != -1) {
      while (pos) {
        swap(t[pos], t[pos - 1]);
        pos--;
        cnt++;
      }
      pos = -1;
      for (int i = 1; i < n; i++) {
        if (t[i] == '5') {
          pos = i;
          break;
        }
      }
      if (pos != -1) {
        while (pos > 1) {
          swap(t[pos], t[pos - 1]);
          pos--;
          cnt++;
        }
        pos = n;
        for (int i = n - 1; i >= 2; i--) {
          if (t[i] != '0') {
            pos = i;
            break;
          }
        }
        if (pos != n || n == 2) {
          while (pos < n - 1) {
            cnt++;
            pos++;
          }
          ans = min(ans, cnt);
        }
      }
    }
  }
  if (ans == 100)
    ans = -1;
  cout << ans;
  return 0;
}