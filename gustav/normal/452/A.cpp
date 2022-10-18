#include <cstdio>

#include <string>
#include <iostream>

using namespace std;

string names[] = {
  "vaporeon", 
  "jolteon", 
  "flareon", 
  "espeon", 
  "umbreon", 
  "leafeon", 
  "glaceon", 
  "sylveon"
};

int main(void)
{
  int n; cin >> n;
  string s; cin >> s;

  for (int i = 0; i < 8; ++i) {
    if (s.size() != names[i].size())
      continue;

    bool ok = true;
    for (int j = 0; j < s.size(); ++j)
      if (s[j] != '.' && s[j] != names[i][j])
        ok = false;

    if (ok)
      cout << names[i] << endl;
  }

  return 0;
}