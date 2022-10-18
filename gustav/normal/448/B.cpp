#include <cstdio>
#include <cstring>

#include <string>
#include <algorithm>

#include <iostream>

using namespace std;

string s, t;

bool solve_a() {
  int pos_s = 0;
  for (int i = 0; i < t.size(); ++i) {
    while (pos_s < s.size() && s[pos_s] != t[i]) ++pos_s;
    if (pos_s == s.size()) return false;
    ++pos_s;
  }
  return true;
}

bool solve_b() {
  int fs[26];
  int ft[26];

  memset(fs, 0, sizeof fs);
  memset(ft, 0, sizeof ft);

  for (int i = 0; i < s.size(); ++i)
    ++fs[s[i] - 'a'];
  
  for (int i = 0; i < t.size(); ++i)
    ++ft[t[i] - 'a'];

  for (int i = 0; i < 26; ++i)
    if (fs[i] != ft[i])
      return false;

  return true;
}

bool solve_both() {
  int fs[26];
  int ft[26];

  memset(fs, 0, sizeof fs);
  memset(ft, 0, sizeof ft);

  for (int i = 0; i < s.size(); ++i)
    ++fs[s[i] - 'a'];
  
  for (int i = 0; i < t.size(); ++i)
    ++ft[t[i] - 'a'];

  for (int i = 0; i < 26; ++i)
    if (fs[i] < ft[i])
      return false;

  return true;
}

int main(void)
{
  cin >> s;
  cin >> t;
  
  bool a = solve_a();
  bool b = solve_b();
  bool both = solve_both();

  if (!both)
    puts("need tree");
  else if (a)
    puts("automaton");
  else if (b)
    puts("array");
  else 
    puts("both");

  return 0;
}