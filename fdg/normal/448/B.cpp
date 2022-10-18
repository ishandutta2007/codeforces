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
  string s, t;
  cin >> s >> t;
  int cnt[26] = {0};
  for (char a : s) {
    cnt[a - 'a']++;
  }
  for (char a : t) {
    cnt[a - 'a']--;
  }
  for (int i = 0; i < 26; ++i)
    if (cnt[i] < 0) {
      puts("need tree");
      return 0;
    }
  if (s.size() == t.size()) {
    puts("array");
    return 0;
  }
  int p = 0;
  for (int i = 0; i < t.size(); ++i) {
    while (p < s.size() && s[p] != t[i]) ++p;
    if (p < s.size() && s[p] == t[i]);
    else {
      puts("both");
      return 0;
    }
    ++p;
  }
  puts("automaton");
  return 0;
}