// November 13, 2020
// https://codeforces.com/contest/1446/problem/A

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1446A.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1446A.cpp -ggdb && gdb a
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


  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    long long w;
    cin >> n >> w;
    vector<int> a(n);
    vector<int> order;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] <= w) {
        order.push_back(i);
      }
    }
    sort(order.begin(), order.end(), [&](int i, int j) { return a[i] < a[j]; });
    if (order.empty()) {
      cout << "-1\n";
      continue;
    }
    if ((w + 1) / 2 <= a[order.back()]) {
      cout << "1\n";
      cout << order.back() + 1 << '\n';
      continue;
    }
    int m = -1;
    long long sum = 0;
    for (int i = 0; i < (int) order.size(); i++) {
      sum += a[order[i]];
      if ((w + 1) / 2 <= sum) {
        m = i + 1;
        break;
      }
    }
    if (m == -1) {
      cout << "-1\n";
    } else {
      cout << m << '\n';
      for (int i = 0; i < m; i++) {
        if (i > 0) {
          cout << ' ';
        }
        cout << order[i] + 1;
      }
      cout << '\n';
    }
  }


  return 0;
}