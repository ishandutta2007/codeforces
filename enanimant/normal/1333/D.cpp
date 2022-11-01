// April 8, 2020
// https://codeforces.com/contest/1333/problem/D

/*

*/


#include <bits/stdc++.h>

using namespace std;


void print(const vector<int> &v) {
  assert(!v.empty());
  cout << v.size();
  for (int x : v) {
    cout << ' ' << x + 1;
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    a[i] = (c == 'L' ? -1 : 1);
  }
  vector<vector<int>> ops(n);
  int rounds;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (a[j] == 1 && a[j + 1] == -1) {
        ops[i].push_back(j);
        cnt++;
      }
    }
    if (ops[i].empty()) {
      rounds = i;
      break;
    }
    for (int x : ops[i]) {
      a[x] = -1;
      a[x + 1] = 1;
    }
  }
  if (cnt < k || rounds > k) {
    cout << "-1\n";
    return 0;
  }
  bool go = false;
  for (int i = 0; i < rounds; i++) {
    int g = (int) ops[i].size();
    for (int j = 0; j < g; j++) {
      if (k == rounds - i) {
        go = true;
      }
      if (go) {
        vector<int> v;
        for (int jj = j; jj < g; jj++) {
          v.push_back(ops[i][jj]);
        }
        print(v);
        break;
      }
      cout << "1 " << ops[i][j] + 1 << '\n';
      k--;
    }
  }


  return 0;
}