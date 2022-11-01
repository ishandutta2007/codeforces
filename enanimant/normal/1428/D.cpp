// October 16, 2020
// https://codeforces.com/contest/1428/problem/D

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1428D.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1428D.cpp -ggdb && gdb a
*/


#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<pair<int, int>> ret;
  bool ok = true;
  vector<int> ones, twos, threes;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == 1) {
      ret.emplace_back(i, i);
      ones.push_back(i);
    } else if (a[i] == 2) {
      if (!ones.empty()) {
        ret.emplace_back(ones.back(), i);
        ones.pop_back();
        twos.push_back(i);
      } else {
        ok = false;
        break;
      }
    } else if (a[i] == 3) {
      ret.emplace_back(i, i);
      if (!threes.empty()) {
        ret.emplace_back(i, threes.back());
        threes.pop_back();
      } else if (!twos.empty()) {
        ret.emplace_back(i, twos.back());
        twos.pop_back();
      } else if (!ones.empty()) {
        ret.emplace_back(i, ones.back());
        ones.pop_back();
      } else {
        ok = false;
        break;
      }
      threes.push_back(i);
    }
  }
  if (!ok) {
    cout << "-1\n";
  } else {
    cout << ret.size() << '\n';
    for (const auto& p : ret) {
      cout << p.first + 1 << ' ' << p.second + 1 << '\n';
    }
  }


  return 0;
}