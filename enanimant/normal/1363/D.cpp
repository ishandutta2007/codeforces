// May 31, 2020
// https://codeforces.com/contest/1363/problem/D

/*

*/


#include <bits/stdc++.h>

using namespace std;


int ask(vector<int> v) {
  if (v.empty()) {
    return -1;
  }
  cout << "? " << v.size();
  for (int x : v) {
    cout << ' ' << x + 1;
  }
  cout << endl;
  int res;
  cin >> res;
  return res;
}

void answer(const vector<int>& v) {
  cout << "!";
  for (int x : v) {
    cout << ' ' << x;
  }
  cout << endl;
  string s;
  cin >> s;
  assert(s[0] == 'C');
}

int main() {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
// 
// #ifdef _DEBUG
//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);
//   freopen("debug_output.txt", "w", stderr);
// #endif
  
  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> s(k);
    vector<int> set_id(n, -1);
    for (int i = 0; i < k; i++) {
      int c;
      cin >> c;
      s[i].resize(c);
      for (int j = 0; j < c; j++) {
        cin >> s[i][j];
        s[i][j]--;
        set_id[s[i][j]] = i;
      }
    }
    vector<int> v(n);
    iota(v.begin(), v.end(), 0);
    int mx = ask(v);
    int lo = 0, hi = n - 1;
    while (lo < hi) {
      int mid = (lo + hi) / 2;
      v.clear();
      for (int i = lo; i <= mid; i++) {
        v.push_back(i);
      }
      if (ask(v) == mx) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    int x = hi;
    vector<int> ans(k);
    for (int i = 0; i < k; i++) {
      if (i != set_id[x]) {
        ans[i] = mx;
      } else {
        vector<int> v;
        for (int j = 0; j < n; j++) {
          if (set_id[j] != i) {
            v.push_back(j);
          }
        }
        ans[i] = ask(v);
      }
    }
    answer(ans);
  }
  
  
  return 0;
}