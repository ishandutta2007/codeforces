// October 10, 2020
// https://codeforces.com/contest/1427/problem/B

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1427B.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1427B.cpp -ggdb && gdb a
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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> won;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'W') {
        won.push_back(i);
      }
    }
    int w = (int) won.size();
    if (w == 0) {
      cout << max(2 * k - 1, 0) << '\n';
      continue;
    }
    vector<int> order(w - 1);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) { return won[i + 1] - won[i] < won[j + 1] - won[j]; });
    for (int z = 0; z < w - 1; z++) {
      int i = order[z];
      int flip = won[i + 1] - won[i] - 1;
      if (flip <= k) {
        k -= flip;
        for (int j = won[i] + 1; j < won[i + 1]; j++) {
          s[j] = 'W';
        }
      }
    }
    for (int j = 1; j < n; j++) {
      if (k > 0 && s[j] != 'W' && s[j - 1] == 'W') {
        s[j] = 'W';
        k--;
      }
    }
    for (int j = n - 2; j >= 0; j--) {
      if (k > 0 && s[j] != 'W' && s[j + 1] == 'W') {
        s[j] = 'W';
        k--;
      }
    }
    int score = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'W') {
        score++;
        if (i > 0 && s[i - 1] == 'W') {
          score++;
        }
      }
    }
    cout << score << '\n';
  }


  return 0;
}