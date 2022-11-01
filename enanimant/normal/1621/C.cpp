/*
 * author:  ADMathNoob
 * created: 01/03/22 09:35:40
 * problem: https://codeforces.com/contest/1621/problem/C
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

int Ask(int i) {
  // print query; don't forget to flush the output
  cout << "? " << i + 1 << endl;
  int res;
  cin >> res;
  --res;
  return res;
}

void Answer(const vector<int>& p) {
  // print the answer; don't forget to flush the output
  cout << '!';
  for (int x : p) {
    cout << ' ' << x + 1;
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int cnt = 0;
    vector<int> p(n, -1);
    for (int i = 0; i < n; i++) {
      if (p[i] != -1) {
        continue;
      }
      int init_cnt = cnt;
      vector<int> cycle;
      int start = Ask(i);
      ++cnt;
      cycle.push_back(start);
      int v;
      do {
        v = Ask(i);
        ++cnt;
        cycle.push_back(v);
      } while (v != start);
      cycle.pop_back();
      int len = cycle.size();
      int shift = (len - init_cnt) % len;
      // rotate(cycle.begin(), cycle.begin() + shift, cycle.end());
      // assert(cycle[0] == i);
      for (int z = 0; z < len; z++) {
        p[cycle[z]] = cycle[(z + 1) % len];
      }
    }
    Answer(p);
  }
  return 0;
}