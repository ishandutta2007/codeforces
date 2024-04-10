#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <map>
#include <set>

using namespace std;

map<string, set<string>> f, rf;

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    int pos = s.find('/', 7);
    if (pos != -1) {
      f[s.substr(0, pos)].insert(s.substr(pos));
      // cout << s.substr(0, pos) << " " << s.substr(pos) << endl;
    } else {
      f[s].insert("$Fuck$Facebook$");
    }
  }
  for (auto p : f) {
    string ss;
    for (auto s : p.second) {
      ss += s;
      ss += '$';
    }
    rf[ss].insert(p.first);
  }
  int cnt = 0;
  for (auto p : rf) {
    if (p.second.size() > 1) {
      ++cnt;
    }
  }
  cout << cnt << endl;
  for (auto p : rf) {
    if (p.second.size() > 1) {
      for (string s : p.second) {
        cout << s << " ";
      }
      cout << endl;
    }
  } 
  return 0;
}