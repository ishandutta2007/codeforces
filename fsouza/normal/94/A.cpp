#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef long long lint;

int main() {
  string s;
  cin >> s;
  map<string, int> code;

  for (int i = 0; i < 10; i++) {
    string t;
    cin >> t;
    code[t] = i;
  }

  for (int i = 0; i < 8; i++)
    cout << code[s.substr(10*i, 10)];
  cout << endl;

  return 0;
}