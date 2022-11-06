#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
  string s;

  cin >> s;

  int last = s.size()-1 - (find(s.rbegin(), s.rend(), '#') - s.rbegin());

  int no = count(s.begin(), s.end(), '(');
  int nc = count(s.begin(), s.end(), ')');
  int nh = s.size() - no - nc;

  int lastval = no - nc - (nh-1);
  bool ok = true;

  if (lastval < 1) ok = false;

  int delta = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    if (s[i] == '(') delta++;
    if (s[i] == ')') delta--;
    if (s[i] == '#') {
      if (i == last) delta -= lastval;
      else delta--;
    }
    if (delta < 0) ok = false;
  }
  if (delta != 0) ok = false;

  if (!ok) printf("-1\n");
  else {
    for (int i = 0; i < nh-1; i++) printf("1\n");
    printf("%d\n", lastval);
  }

  return 0;
}