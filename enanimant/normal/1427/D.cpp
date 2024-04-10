// October 10, 2020
// https://codeforces.com/contest/1427/problem/D

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1427D.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1427D.cpp -ggdb && gdb a
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
    --a[i];
  }
  vector<vector<int>> ops;
  for (int i = 0; i < n; i++) {
    // for (int j = 0; j < n; j++) cerr << a[j] << ' '; cerr << '\n';
    bool rev = ((n - 1 - i) % 2 == 1);
    if (rev) {
      reverse(a.begin(), a.end());
    }
    int pos = (int) (find(a.begin(), a.end(), i) - a.begin());
    vector<int> res;
    for (int j = 0; j < i; j++) {
      res.push_back(1);
    }
    res.push_back(n - i - pos);
    if (pos > 0) {
      res.push_back(pos);
    }
    reverse(res.begin(), res.end());
    if (rev) {
      reverse(a.begin(), a.end());
      reverse(res.begin(), res.end());
    }
    if ((int) res.size() > 1) {
      ops.push_back(res);
    }
    vector<int> b;
    int p = n;
    reverse(res.begin(), res.end());
    for (int sz : res) {
      for (int j = p - sz; j < p; j++) {
        b.push_back(a[j]);
      }
      p -= sz;
    }
    swap(a, b);
  }
  cout << ops.size() << '\n';
  for (auto op : ops) {
    cout << op.size();
    for (int i : op) {
      cout << ' ' << i;
    }
    cout << '\n';
  }


  return 0;
}