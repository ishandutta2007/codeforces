#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int main() {
  string s;
  getline(cin, s);
  string tmp = "";
  for (char c : s) {
    if (c != ' ') tmp += c;
  }
  s = tmp;

  int n = 0;
  for (int pos = s.find('=') + 1; pos < s.size(); ++pos) {
    n = n * 10 + s[pos] - '0';
  }
  vector<int> v;
  int sg = 1, res = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '?') {
      v.push_back((v.size() == 0 ? n : 1) * sg);
      res += v.back();
    }
    if (s[i] == '+') sg = 1;
    if (s[i] == '-') sg = -1;
  }

  while (res != n) {
    bool found = false;
    if (res > n) {
      for (int i = 0; i < v.size(); ++i) {
        if (v[i] <= -1 && abs(v[i]) < n || v[i] > 1) {
          --v[i];
          --res;
          found = true;
          break;
        }
      }
    } else {
      for (int i = 0; i < v.size(); ++i) {
        if (v[i] < -1 || v[i] >= 1 && v[i] < n) {
          ++v[i];
          ++res;
          found = true;
          break;
        }
      }
    }

    if (!found) {
      puts("Impossible");
      return 0;
    }
  }

  cout << "Possible\n";
  cout << v[0];
  for (int i = 1; i < v.size(); ++i) {
    cout << " " << (v[i] > 0 ? '+' : '-') << " " << abs(v[i]);
  }
  cout << " = " << n << endl;

  return 0;
}