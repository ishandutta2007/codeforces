// March 19, 2020
// https://codeforces.com/contest/1325/problem/D

/*

*/


#include <bits/stdc++.h>

using namespace std;


template <typename T>
vector<int> manacher(int n, const T &s) {
  if (n == 0) {
    return vector<int>();
  }
  vector<int> res(2 * n - 1, 0);
  int l = -1, r = -1;
  for (int z = 0; z < 2 * n - 1; z++) {
    int i = (z + 1) >> 1;
    int j = z >> 1;
    int p = (i >= r ? 0 : min(r - i, res[2 * (l + r) - z]));
    while (j + p + 1 < n && i - p - 1 >= 0) {
      if (!(s[j + p + 1] == s[i - p - 1])) {
        break;
      }
      p++;
    }
    if (j + p > r) {
      l = i - p;
      r = j + p;
    }
    res[z] = p;
  }
  return res;
  // res[2 * i] = odd radius in position i
  // res[2 * i + 1] = even radius between positions i and i + 1
  // s = "abaa" -> res = {0, 0, 1, 0, 0, 1, 0}
  // in other words, for every z from 0 to 2 * n - 2:
  // calculate i = (z + 1) >> 1 and j = z >> 1
  // now there is a palindrome from i - res[z] to j + res[z]
  // (watch out for i > j and res[z] = 0)
}

template <typename T>
vector<int> manacher(const T &s) {
  return manacher((int) s.size(), s);
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = (int) s.size();
    int x = 0, y = n - 1;
    while (x <= y && s[x] == s[y]) {
      x++;
      y--;
    }
    if (x > y) {
      cout << s << '\n';
      continue;
    }
    string m = s.substr(x, y - x + 1);
    int len = (int) m.size();
    vector<int> res = manacher(m);
    int ans1 = -1;
    for (int i = 0; i < 2 * len - 1; i++) {
      if (i % 2 == 0) {
        int p = i / 2;
        if (res[i] == p) {
          ans1 = 2 * p + 1;
        }
      } else {
        if (i == 2 * res[i] - 1) {
          ans1 = i + 1;
        }
      }
    }
    string a1 = (ans1 == -1 ? "" : m.substr(0, ans1));
    reverse(m.begin(), m.end());
    res = manacher(m);
    int ans2 = -1;
    for (int i = 0; i < 2 * len - 1; i++) {
      if (i % 2 == 0) {
        int p = i / 2;
        if (res[i] == p) {
          ans2 = 2 * p + 1;
        }
      } else {
        if (i == 2 * res[i] - 1) {
          ans2 = i + 1;
        }
      }
    }
    string a2 = (ans2 == -1 ? "" : m.substr(0, ans2));
    if (a1.size() < a2.size()) {
      swap(a1, a2);
    }
    cout << s.substr(0, x) << a1 << s.substr(y + 1) << '\n';
  }


  return 0;
}