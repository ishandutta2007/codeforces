#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

string get(char f[3][3]) {
  string s = "";
  if (f[0][0] != 'X') s += f[0][0];
  if (f[0][1] != 'X') s += f[0][1];
  if (f[1][1] != 'X') s += f[1][1];
  if (f[1][0] != 'X') s += f[1][0];
  while (s[0] != 'A') {
    s += s[0];
    s = s.substr(1);
  }
  return s;
}

int main() {
  char f1[3][3] = {0};
  cin >> f1[0] >> f1[1];
  char f2[3][3] = {0};
  cin >> f2[0] >> f2[1];
  if (get(f1) == get(f2)) cout << "YES" << endl;
  else cout << "NO" << endl; 
  return 0;
}