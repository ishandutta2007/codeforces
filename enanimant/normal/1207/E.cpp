// August 22, 2019
// https://codeforces.com/contest/1207/problem/E

/*

*/


#include <bits/stdc++.h>

using namespace std;


int ask(const vector<int> &v) {
  cout << "?";
  for (int i : v) {
    cout << ' ' << i;
  }
  cout << endl;
  int res;
  cin >> res;
  return res;
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


  vector<int> v(100);
  iota(v.begin(), v.end(), 1);
  int ans = ask(v); // leftmost 7 bits are correct
  for (int i = 0; i < 100; i++) {
    v[i] <<= 7;
  }
  int res = ask(v);
  for (int i = 0; i < 7; i++) {
    if (res & (1 << i)) {
      ans |= 1 << i;
    } else {
      ans &= ~(1 << i);
    }
  }
  cout << "! " << ans << endl;


  return 0;
}