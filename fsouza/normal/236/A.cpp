#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
  string s;
  cin >> s;

  sort(s.begin(), s.end());

  int many = unique(s.begin(), s.end()) - s.begin();

  if (many%2) cout << "IGNORE HIM!" << endl;
  else cout << "CHAT WITH HER!" << endl;

  return 0;
}